using Microsoft.Xna.Framework;
using FarmGame.Utilities;

namespace FarmGame.Core
{
    /// <summary>
    /// Determines global screen color tints to simulate morning warmth, bright days, and dark nights.
    /// </summary>
    public class LightingEngine
    {
        public static LightingEngine Instance { get; } = new LightingEngine();

        private LightingEngine() { }

        /// <summary>
        /// Calculates the background tint color factor matching the current hour.
        /// </summary>
        public Color GetAmbientLight()
        {
            int hour = TimeManager.Instance.CurrentHour;

            // Morning twilight shift transition boundaries
            if (hour >= 6 && hour < 8) return new Color(245, 200, 170);   // Early morning amber glow
            if (hour >= 8 && hour < 17) return Color.White;                // Plain un-tinted daylight
            if (hour >= 17 && hour < 20) return new Color(200, 150, 195); // Dusk purple twilight
            
            return new Color(45, 45, 85); // Night time deep blue overlay tint
        }
    }
}