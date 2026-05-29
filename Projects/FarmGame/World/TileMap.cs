using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FarmGame.Utilities;

namespace FarmGame.World
{
    public class TileMap
    {
        public int Width { get; private set; }
        public int Height { get; private set; }

        private int[,] _grid;
        private Dictionary<int, Tile> _tileRegistry;

        // We create one shared pixel texture for fallback drawing
        private static Texture2D _pixel;

        public TileMap(int width, int height)
        {
            Width = width;
            Height = height;
            _grid = new int[width, height];
            _tileRegistry = new Dictionary<int, Tile>();

            SetupDefaultTiles();
            GenerateEmptyMap();
        }

        #region Setup
        private void SetupDefaultTiles()
        {
            _tileRegistry[0] = new Tile(0, "Grass",    true,  true);
            _tileRegistry[1] = new Tile(1, "WoodFence",false, false);
            _tileRegistry[2] = new Tile(2, "Water",    false, false);
            _tileRegistry[7] = new Tile(7, "DirtPath", true,  false);
        }

        private void GenerateEmptyMap()
        {
            for (int x = 0; x < Width; x++)
            {
                for (int y = 0; y < Height; y++)
                {
                    if (x == 0 || x == Width - 1 || y == 0 || y == Height - 1)
                        _grid[x, y] = 1; // border fence
                    else
                        _grid[x, y] = 0; // grass interior
                }
            }
        }

        /// <summary>
        /// Call once from Game1.LoadContent so the fallback pixel is available.
        /// </summary>
        public static void CreateFallbackTexture(GraphicsDevice graphicsDevice)
        {
            _pixel = new Texture2D(graphicsDevice, 1, 1);
            _pixel.SetData(new[] { Color.White });
        }
        #endregion

        #region Queries
        public bool IsTileWalkable(int x, int y)
        {
            if (x < 0 || x >= Width || y < 0 || y >= Height) return false;
            int tileId = _grid[x, y];
            return _tileRegistry.TryGetValue(tileId, out Tile tile) && tile.IsWalkable;
        }

        public void SetTile(int x, int y, int tileId)
        {
            if (x >= 0 && x < Width && y >= 0 && y < Height)
                _grid[x, y] = tileId;
        }
        #endregion

        #region Draw
        public void Draw(SpriteBatch spriteBatch, Texture2D tilesetTex)
        {
            for (int x = 0; x < Width; x++)
            {
                for (int y = 0; y < Height; y++)
                {
                    int tileId = _grid[x, y];
                    Vector2 pos = new Vector2(x * Constants.TileSize, y * Constants.TileSize);
                    Rectangle destRect = new Rectangle((int)pos.X, (int)pos.Y, Constants.TileSize, Constants.TileSize);

                    if (tilesetTex == null)
                    {
                        // FIXED: actually draw colored rectangles instead of 'continue'
                        Color fallbackColor = tileId switch
                        {
                            1 => new Color(101, 67, 33),   // fence = dark brown
                            2 => new Color(30, 100, 200),  // water = blue
                            7 => new Color(180, 140, 80),  // path  = tan
                            _ => new Color(60, 120, 40),   // grass = green
                        };

                        if (_pixel != null)
                            spriteBatch.Draw(_pixel, destRect, fallbackColor);
                    }
                    else
                    {
                        Rectangle sourceRect = new Rectangle(tileId * Constants.TileSize, 0, Constants.TileSize, Constants.TileSize);
                        spriteBatch.Draw(tilesetTex, pos, sourceRect, Color.White);
                    }
                }
            }
        }
        #endregion
    }
}