using System;
using Microsoft.Xna.Framework;
using FarmGame.Utilities;

namespace FarmGame.Core
{
    /// <summary>
    /// Tracks the in-game clock, days, and seasons. Triggers events when time thresholds pass.
    /// </summary>
    public class TimeManager
    {
        public static TimeManager Instance { get; } = new TimeManager();

        public int CurrentMinute { get; private set; }
        public int CurrentHour { get; private set; }
        public int CurrentDay { get; private set; } = 1;
        public int CurrentSeasonIndex { get; private set; } = 0; // 0=Spring, 1=Summer, 2=Fall, 3=Winter
        public int CurrentYear { get; private set; } = 1;

        public bool IsPaused { get; set; } = false;

        private float _realTimer;

        // Events to broadcast time changes to other systems
        public event Action OnMinuteChanged;
        public event Action OnHourChanged;
        public event Action OnDayChanged;
        public event Action OnSeasonChanged;

        private TimeManager()
        {
            CurrentHour = Constants.MorningHour;
            CurrentMinute = 0;
        }

        #region Update
        /// <summary>
        /// Advances the in-game clock based on real elapsed time.
        /// </summary>
        public void Update(GameTime gameTime)
        {
            if (IsPaused) return;

            float dt = (float)gameTime.ElapsedGameTime.TotalSeconds;
            _realTimer += dt;

            // Check if enough real time has passed to increment an in-game minute (default: 10 mins)
            if (_realTimer >= Constants.RealSecondsPerInGameMinute)
            {
                _realTimer -= Constants.RealSecondsPerInGameMinute;
                AdvanceTime(10); // Advance by 10 in-game minutes
            }
        }
        #endregion

        #region Helpers
        private void AdvanceTime(int minutes)
        {
            CurrentMinute += minutes;

            if (CurrentMinute >= 60)
            {
                CurrentMinute -= 60;
                CurrentHour++;
                OnHourChanged?.Invoke();

                if (CurrentHour >= Constants.PassOutHour) // 2 AM forced sleep
                {
                    ForceNextDay();
                }
            }

            OnMinuteChanged?.Invoke();
        }

        /// <summary>
        /// Skips to the next day, usually triggered by sleeping.
        /// </summary>
        public void ForceNextDay()
        {
            CurrentHour = Constants.MorningHour;
            CurrentMinute = 0;
            CurrentDay++;

            if (CurrentDay > Constants.DaysPerSeason)
            {
                CurrentDay = 1;
                CurrentSeasonIndex++;

                if (CurrentSeasonIndex > 3)
                {
                    CurrentSeasonIndex = 0;
                    CurrentYear++;
                }
                OnSeasonChanged?.Invoke();
            }

            OnDayChanged?.Invoke();
        }
        #endregion
    }
}