using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using FarmGame.Core;
using FarmGame.Utilities;

namespace FarmGame.UI
{
    /// <summary>
    /// Displays grid overlays matching storage array configurations inside Backpack layout grids.
    /// </summary>
    public class InventoryMenu
    {
        private int _cursorIndex = 0;
        private const int SlotsPerRow = 12;

        public void Update(GameTime gameTime)
        {
            InputManager input = InputManager.Instance;

            // Basic inventory navigating via arrow keys
            if (input.IsKeyPressed(Keys.Right)) _cursorIndex = (_cursorIndex + 1) % 24;
            if (input.IsKeyPressed(Keys.Left))  _cursorIndex = (_cursorIndex - 1 + 24) % 24;
            if (input.IsKeyPressed(Keys.Down))  _cursorIndex = (_cursorIndex + SlotsPerRow) % 24;
            if (input.IsKeyPressed(Keys.Up))    _cursorIndex = (_cursorIndex - SlotsPerRow + 24) % 24;
        }

        public void Draw(SpriteBatch spriteBatch, SpriteFont font, Texture2D uiTex)
        {
            int startX = (Constants.ScreenWidth - (SlotsPerRow * 40)) / 2;
            int startY = (Constants.ScreenHeight - 200) / 2;

            // Draw Dim background underlay
            // Custom direct rendering color block simulation rules inside system loop boundaries
            
            if (font == null) return;
            spriteBatch.DrawString(font, "=== BACKPACK INVENTORY ===", new Vector2(startX, startY - 40), Color.White);

            // Render individual grid blocks loop
            for (int i = 0; i < 24; i++)
            {
                int row = i / SlotsPerRow;
                int col = i % SlotsPerRow;
                Vector2 slotPos = new Vector2(startX + (col * 40), startY + (row * 40));

                // Color selection highlights active cursor locations
                Color boxColor = (i == _cursorIndex) ? Color.Yellow : Color.Gray;
                spriteBatch.DrawString(font, "[ ]", slotPos, boxColor);
            }
        }
    }
}