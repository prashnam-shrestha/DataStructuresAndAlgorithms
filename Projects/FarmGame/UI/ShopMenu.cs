using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FarmGame.Inventory;
using FarmGame.Utilities;

namespace FarmGame.UI
{
    /// <summary>
    /// Displays item lists, costs, and inventories when talking to seed store merchants.
    /// </summary>
    public class ShopMenu
    {
        public void Draw(SpriteBatch spriteBatch, SpriteFont font)
        {
            if (font == null) return;
            int startX = 100;
            int startY = 100;

            spriteBatch.DrawString(font, "=== SEED SHOP ===", new Vector2(startX, startY), Color.Gold);
            
            var stock = ShopManager.Instance.MerchantStock;
            for (int i = 0; i < stock.Count; i++)
            {
                Item item = stock[i];
                spriteBatch.DrawString(font, $"{item.Name} - {item.Value}g", new Vector2(startX, startY + 40 + (i * 30)), Color.White);
            }
        }
    }
}