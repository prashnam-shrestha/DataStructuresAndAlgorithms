using System.Collections.Generic;

namespace FarmGame.World
{
    /// <summary>
    /// Tracks which map scene layer environment is currently loaded and active.
    /// </summary>
    public class MapManager
    {
        public static MapManager Instance { get; } = new MapManager();

        public string CurrentMapName { get; private set; } = "Farm";
        
        private Dictionary<string, TileMap> _loadedMaps = new Dictionary<string, TileMap>();

        private MapManager()
        {
            // Seed base infrastructure maps automatically
            _loadedMaps["Farm"] = new TileMap(50, 50);
            _loadedMaps["Town"] = new TileMap(80, 80);
        }

        #region Actions
        public TileMap GetActiveMap()
        {
            return _loadedMaps[CurrentMapName];
        }

        /// <summary>
        /// Smoothly swaps maps and updates world parameters contextually.
        /// </summary>
        public void TransitionToMap(string newMapName)
        {
            if (_loadedMaps.ContainsKey(newMapName))
            {
                CurrentMapName = newMapName;
            }
        }
        #endregion
    }
}