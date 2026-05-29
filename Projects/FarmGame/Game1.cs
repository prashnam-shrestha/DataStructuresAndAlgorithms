using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using FarmGame.Core;
using FarmGame.Entities;
using FarmGame.UI;
using FarmGame.Utilities;
using FarmGame.World;

namespace FarmGame
{
    public class Game1 : Game
    {
        private GraphicsDeviceManager _graphics;
        private SpriteBatch _spriteBatch;

        private Texture2D _characterSpritesheet;
        private Texture2D _tilesetTexture;
        private Texture2D _uiTexture;
        private SpriteFont _gameFont;

        // Fallback pixel textures for drawing shapes without assets
        private Texture2D _pixel;
        private Texture2D _playerFallback;
        private Texture2D _npcFallback;

        public Game1()
        {
            _graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            IsMouseVisible = true;
            _graphics.PreferredBackBufferWidth  = Constants.ScreenWidth;
            _graphics.PreferredBackBufferHeight = Constants.ScreenHeight;
        }

        protected override void Initialize()
        {
            Player player = new Player(new Vector2(300, 300));
            EntityManager.Instance.MainPlayer = player;

            NPC robin = new NPC("Robin", new Vector2(500, 400));
            EntityManager.Instance.AddNPC(robin);

            Camera.Instance.Zoom = 1.5f;

            base.Initialize();
        }

        protected override void LoadContent()
        {
            _spriteBatch = new SpriteBatch(GraphicsDevice);

            // ── Create the shared 1×1 white pixel used everywhere for fallback drawing ──
            _pixel = new Texture2D(GraphicsDevice, 1, 1);
            _pixel.SetData(new[] { Color.White });

            // Give TileMap its fallback pixel so it can draw colored tiles
            TileMap.CreateFallbackTexture(GraphicsDevice);

            // ── Player fallback: cornflower-blue 28×28 square ──
            _playerFallback = new Texture2D(GraphicsDevice, 28, 28);
            Color[] playerPixels = new Color[28 * 28];
            for (int i = 0; i < playerPixels.Length; i++)
                playerPixels[i] = new Color(100, 149, 237); // cornflower blue
            _playerFallback.SetData(playerPixels);

            // ── NPC fallback: orange 24×24 square ──
            _npcFallback = new Texture2D(GraphicsDevice, 24, 24);
            Color[] npcPixels = new Color[24 * 24];
            for (int i = 0; i < npcPixels.Length; i++)
                npcPixels[i] = new Color(255, 165, 0); // orange
            _npcFallback.SetData(npcPixels);

            // ── Try loading real assets; silently skip if not compiled yet ──
            try { _characterSpritesheet = Content.Load<Texture2D>("Sprites/Characters"); }
            catch { System.Diagnostics.Debug.WriteLine("[INFO] No character spritesheet found, using fallback."); }

            try { _tilesetTexture = Content.Load<Texture2D>("Maps/Tileset"); }
            catch { System.Diagnostics.Debug.WriteLine("[INFO] No tileset found, using fallback colors."); }

            try { _uiTexture = Content.Load<Texture2D>("UI/PanelBackground"); }
            catch { System.Diagnostics.Debug.WriteLine("[INFO] No UI texture found."); }

            try { _gameFont = Content.Load<SpriteFont>("Fonts/PixelFont"); }
            catch { System.Diagnostics.Debug.WriteLine("[INFO] No font found — HUD text will be hidden until font is added."); }
        }

        protected override void Update(GameTime gameTime)
        {
            InputManager.Instance.Update();

            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed ||
                InputManager.Instance.IsKeyDown(Keys.Escape))
                Exit();

            TimeManager.Instance.Update(gameTime);
            UIManager.Instance.Update(gameTime);

            if (UIManager.Instance.CurrentState == UIState.HUD)
            {
                EntityManager.Instance.Update(gameTime);

                Player mainPlayer = EntityManager.Instance.MainPlayer;
                if (mainPlayer != null)
                    Camera.Instance.Follow(mainPlayer.Position, Constants.ScreenWidth, Constants.ScreenHeight);
            }

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(new Color(20, 20, 28));

            // ── PASS 1: World space (camera transform applied) ──
            _spriteBatch.Begin(
                SpriteSortMode.Deferred,
                BlendState.AlphaBlend,
                SamplerState.PointClamp,
                null, null, null,
                Camera.Instance.Transform
            );

            TileMap activeMap = MapManager.Instance.GetActiveMap();
            activeMap?.Draw(_spriteBatch, _tilesetTexture);

            // Draw entities with fallback textures when spritesheet is missing
            Texture2D playerTex = _characterSpritesheet ?? _playerFallback;
            Texture2D npcTex    = _characterSpritesheet ?? _npcFallback;
            EntityManager.Instance.DrawWithFallbacks(_spriteBatch, playerTex, npcTex);

            _spriteBatch.End();

            // ── PASS 2: Screen space UI (no camera transform) ──
            _spriteBatch.Begin(SpriteSortMode.Deferred, BlendState.AlphaBlend, SamplerState.PointClamp);

            UIManager.Instance.Draw(_spriteBatch, _gameFont, _uiTexture);

            // If no font loaded, draw a simple "no font" notice using pixel rectangles
            if (_gameFont == null)
                DrawNoFontNotice();

            _spriteBatch.End();

            base.Draw(gameTime);
        }

        /// <summary>
        /// Draws coloured indicator bars so you can see SOMETHING even without a font.
        /// Green bar = stamina, Red bar = health. Top-right shows time as bar fill %.
        /// </summary>
        private void DrawNoFontNotice()
        {
            Player p = EntityManager.Instance.MainPlayer;
            if (p == null || _pixel == null) return;

            int barW = 160, barH = 14, margin = 10;
            int x = Constants.ScreenWidth - barW - margin;

            // Health bar (red)
            _spriteBatch.Draw(_pixel, new Rectangle(x, margin,            barW, barH), new Color(60,  0,   0));
            _spriteBatch.Draw(_pixel, new Rectangle(x, margin,            (int)(barW * (p.Health  / Constants.MaxHealth)),  barH), Color.Red);

            // Stamina bar (yellow-green)
            _spriteBatch.Draw(_pixel, new Rectangle(x, margin + barH + 4, barW, barH), new Color(40, 60,  0));
            _spriteBatch.Draw(_pixel, new Rectangle(x, margin + barH + 4, (int)(barW * (p.Stamina / Constants.MaxStamina)), barH), Color.YellowGreen);

            // Small white dot = player position indicator in corner
            _spriteBatch.Draw(_pixel, new Rectangle(margin, margin, 8, 8), Color.White);
        }
    }
}