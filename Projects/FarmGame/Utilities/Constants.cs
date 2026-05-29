namespace FarmGame.Utilities
{
    /// <summary>
    /// Holds all magic numbers and global constants to avoid hardcoding values across the project.
    /// </summary>
    public static class Constants
    {
        // Screen & Camera
        public const int ScreenWidth = 1280;
        public const int ScreenHeight = 720;
        public const float CameraLerpSpeed = 5.0f;
        
        // TileMap
        public const int TileSize = 32;
        
        // Time System
        public const float RealSecondsPerInGameMinute = 0.166f; // 1 real sec = 10 in-game mins
        public const int MorningHour = 6;
        public const int NightHour = 20; // 8 PM
        public const int PassOutHour = 26; // 2 AM next day
        public const int DaysPerSeason = 28;
        
        // Player
        public const float PlayerBaseSpeed = 150f;
        public const float PlayerSprintMultiplier = 1.5f;
        public const float MaxStamina = 100f;
        public const float MaxHealth = 100f;
        public const float MaxHunger = 100f;
        public const float InvincibilityDuration = 1.5f;
        
        // Audio Keys
        public const string MusicFarm = "music_farm";
        public const string MusicTown = "music_town";
        public const string MusicMenu = "music_menu";
        public const string SfxFootstep = "sfx_footstep";
        public const string SfxUI = "sfx_ui_click";
    }
}