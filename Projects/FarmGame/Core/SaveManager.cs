using System;
using System.IO;
using System.Text.Json;

namespace FarmGame.Core
{
    /// <summary>
    /// Contains all saveable game state data.
    /// </summary>
    public class SaveData
    {
        public int Day { get; set; } = 1;
        public int SeasonIndex { get; set; } = 0;
        public int Year { get; set; } = 1;
        public int PlayerMoney { get; set; } = 500;
        public float PlayerHealth { get; set; } = 100f;
        public float PlayerStamina { get; set; } = 100f;
        public string CurrentMap { get; set; } = "Farm";
        public float PlayerX { get; set; } = 100f;
        public float PlayerY { get; set; } = 100f;
        // Expanded properties for inventory and farm tiles will map here later.
    }

    /// <summary>
    /// Handles reading and writing JSON save states to cross-platform application data folders.
    /// </summary>
    public class SaveManager
    {
        public static SaveManager Instance { get; } = new SaveManager();

        private readonly string _saveDirectory;
        private readonly JsonSerializerOptions _jsonOptions;

        private SaveManager()
        {
            // Set up cross-platform save path: %AppData%/FarmGame (Win) or ~/.farmgame (Mac/Linux)
            string baseFolder = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            _saveDirectory = Path.Combine(baseFolder, "FarmGame");

            if (!Directory.Exists(_saveDirectory))
            {
                Directory.CreateDirectory(_saveDirectory);
            }

            _jsonOptions = new JsonSerializerOptions { WriteIndented = true };
        }

        #region IO Methods
        /// <summary>
        /// Saves game data to a specific slot (1, 2, or 3).
        /// </summary>
        public void SaveGame(int slotIndex, SaveData data)
        {
            string filePath = GetFilePath(slotIndex);
            try
            {
                string json = JsonSerializer.Serialize(data, _jsonOptions);
                File.WriteAllText(filePath, json);
                Console.WriteLine($"Game saved successfully to slot {slotIndex}.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[ERROR] Failed to save game: {ex.Message}");
            }
        }

        /// <summary>
        /// Loads game data from a specific slot. Returns a new default save if none exists.
        /// </summary>
        public SaveData LoadGame(int slotIndex)
        {
            string filePath = GetFilePath(slotIndex);
            if (File.Exists(filePath))
            {
                try
                {
                    string json = File.ReadAllText(filePath);
                    return JsonSerializer.Deserialize<SaveData>(json, _jsonOptions) ?? new SaveData();
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"[ERROR] Failed to load game: {ex.Message}");
                }
            }
            
            return new SaveData(); // Return fresh start if missing or corrupt
        }

        /// <summary>
        /// Checks if a save file exists in the specified slot.
        /// </summary>
        public bool SaveExists(int slotIndex)
        {
            return File.Exists(GetFilePath(slotIndex));
        }

        private string GetFilePath(int slotIndex)
        {
            return Path.Combine(_saveDirectory, $"SaveSlot{slotIndex}.json");
        }
        #endregion
    }
}