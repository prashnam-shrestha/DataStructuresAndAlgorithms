using System.Collections.Generic;
using Microsoft.Xna.Framework;
using FarmGame.Core;

namespace FarmGame.Farming
{
    /// <summary>
    /// Manages the registry database of all crops active and growing in your world.
    /// </summary>
    public class FarmingManager
    {
        public static FarmingManager Instance { get; } = new FarmingManager();

        private Dictionary<Point, CropTile> _activePlots = new Dictionary<Point, CropTile>();
        private Dictionary<int, CropData> _cropDatabase = new Dictionary<int, CropData>();

        private FarmingManager()
        {
            SetupCropDatabase();
            
            // Listen automatically to TimeManager day changes so crops grow overnight
            TimeManager.Instance.OnDayChanged += ProcessOvernightGrowth;
        }

        private void SetupCropDatabase()
        {
            // Registering Parsnip (ID 0): takes 4 days to grow, yields item ID 50, costs 20g seeds
            _cropDatabase[0] = new CropData(0, "Parsnip", 4, 50, 20);
            // Cauliflower (ID 1): takes 12 days to grow, yields item ID 51, costs 80g seeds
            _cropDatabase[1] = new CropData(1, "Cauliflower", 12, 51, 80);
        }

        #region Actions
        public void TillSoil(Point gridPos)
        {
            if (!_activePlots.ContainsKey(gridPos))
            {
                _activePlots[gridPos] = new CropTile(gridPos);
            }
        }

        public void WaterSoil(Point gridPos)
        {
            if (_activePlots.TryGetValue(gridPos, out CropTile tile))
            {
                tile.IsWatered = true;
            }
        }

        public bool PlantSeed(Point gridPos, int cropId)
        {
            if (_activePlots.TryGetValue(gridPos, out CropTile tile) && tile.CropId == -1)
            {
                if (_cropDatabase.ContainsKey(cropId))
                {
                    tile.CropId = cropId;
                    tile.AgeInDays = 0;
                    tile.CurrentGrowthStage = 0;
                    return true;
                }
            }
            return false;
        }

        private void ProcessOvernightGrowth()
        {
            foreach (var kvp in _activePlots)
            {
                CropTile tile = kvp.Value;
                _cropDatabase.TryGetValue(tile.CropId, out CropData data);
                tile.AdvanceDay(data);
            }
        }
        #endregion

        public CropTile GetTileAt(Point gridPos)
        {
            _activePlots.TryGetValue(gridPos, out CropTile tile);
            return tile;
        }
    }
}