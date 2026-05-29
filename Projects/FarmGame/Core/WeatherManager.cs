using FarmGame.Utilities;

namespace FarmGame.Core
{
    public enum WeatherType { Sunny, Rainy, Stormy }

    /// <summary>
    /// Ruleset calculator deciding daily environment patterns and ambient overlays.
    /// </summary>
    public class WeatherManager
    {
        public static WeatherManager Instance { get; } = new WeatherManager();

        public WeatherType CurrentWeather { get; private set; } = WeatherType.Sunny;
        public WeatherType TomorrowWeather { get; private set; } = WeatherType.Sunny;

        private WeatherManager()
        {
            // Hook up into the daily loop cycle
            TimeManager.Instance.OnDayChanged += ApplyOvernightWeatherRollover;
        }

        #region Engine Lifecycle
        /// <summary>
        /// Moves tomorrow's forecast into today and computes the next consecutive sequence loop.
        /// </summary>
        public void ApplyOvernightWeatherRollover()
        {
            CurrentWeather = TomorrowWeather;

            // Standard RNG rolling mechanism selecting next daily weather sequence configurations
            int rolledChance = Helpers.GetRandomInt(0, 100);

            if (rolledChance < 70)
            {
                TomorrowWeather = WeatherType.Sunny; // 70% chance of clear skies
            }
            else if (rolledChance < 90)
            {
                TomorrowWeather = WeatherType.Rainy; // 20% chance of rain
            }
            else
            {
                TomorrowWeather = WeatherType.Stormy; // 10% chance of thunder lightning storm variants
            }
        }
        #endregion
    }
}