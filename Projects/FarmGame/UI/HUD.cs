using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FarmGame.Core;
using FarmGame.Utilities;

namespace FarmGame.UI
{
    /// <summary>
    /// Draws persistent on-screen vitals like time, gold, stamina, and current day.
    /// </summary>
    public class HUD
    {
        private readonly string[] _seasons = { "Spring", "Summer", "Fall", "Winter" };

        public void Draw(SpriteBatch spriteBatch, SpriteFont font)
        {
            if (font == null) return; // Fallback protection if assets aren't loaded yet

            TimeManager time = TimeManager.Instance;

            // 1. Draw Time Box Overlay UI (Top Right)
            string timeString = $"{time.CurrentHour:D2}:{time.CurrentMinute:D2}";
            string dateString = $"Yr {time.CurrentYear} - {_seasons[time.CurrentSeasonIndex]} {time.CurrentDay}";
            
            Vector2 timePos = new Vector2(Constants.ScreenWidth - 200, 20);
            spriteBatch.DrawString(font, dateString, timePos, Color.White);
            spriteBatch.DrawString(font, timeString, timePos + new Vector2(0, 25), Color.Yellow);

            // 2. Draw Player Statistics Tracker bars (Bottom Right Layout)
            // Stubs pointing directly to defaults for now, fully connected during final Game1 assembly
            float currentStamina = 100f; 
            float currentHealth = 100f;
            int currentMoney = 500;

            Vector2 statsPos = new Vector2(Constants.ScreenWidth - 220, Constants.ScreenHeight - 100);
            spriteBatch.DrawString(font, $"Gold: {currentMoney}g", statsPos, Color.Gold);
            spriteBatch.DrawString(font, $"HP: {(int)currentHealth}/100", statsPos + new Vector2(0, 30), Color.Tomato);
            spriteBatch.DrawString(font, $"Energy: {(int)currentStamina}/100", statsPos + new Vector2(0, 55), Color.LightGreen);
        }
    }
}