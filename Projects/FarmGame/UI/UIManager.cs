using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using FarmGame.Core;

namespace FarmGame.UI
{
    public enum UIState { HUD, InventoryMenu, ShopMenu, Dialogue }

    /// <summary>
    /// Master manager governing which UI menus are open and routing input to them.
    /// </summary>
    public class UIManager
    {
        public static UIManager Instance { get; } = new UIManager();

        public UIState CurrentState { get; set; } = UIState.HUD;

        private HUD _hud;
        private InventoryMenu _inventoryMenu;

        private UIManager()
        {
            _hud = new HUD();
            _inventoryMenu = new InventoryMenu();
        }

        #region Update and Draw
        public void Update(GameTime gameTime)
        {
            InputManager input = InputManager.Instance;

            // Toggle inventory open/closed with the Tab or E key
            if (input.IsKeyPressed(Keys.Tab) || input.IsKeyPressed(Keys.E))
            {
                if (CurrentState == UIState.HUD)
                {
                    CurrentState = UIState.InventoryMenu;
                    TimeManager.Instance.IsPaused = true; // Pause world while managing items
                }
                else if (CurrentState == UIState.InventoryMenu)
                {
                    CurrentState = UIState.HUD;
                    TimeManager.Instance.IsPaused = false;
                }
            }

            // Update active state logic
            if (CurrentState == UIState.InventoryMenu)
            {
                _inventoryMenu.Update(gameTime);
            }
        }

        public void Draw(SpriteBatch spriteBatch, SpriteFont font, Texture2D uiTex)
        {
            // Always draw the HUD layout baseline elements
            _hud.Draw(spriteBatch, font);

            // Draw popups overlay overlays
            if (CurrentState == UIState.InventoryMenu)
            {
                _inventoryMenu.Draw(spriteBatch, font, uiTex);
            }
        }
        #endregion
    }
}