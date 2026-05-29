using Microsoft.Xna.Framework;

namespace FarmGame.Farming
{
    /// <summary>
    /// Tracks the unique soil configurations and growth status of an individual grid layout tile.
    /// </summary>
    public class CropTile
    {
        public Point GridPosition { get; set; }
        public bool IsTilled { get; set; }
        public bool IsWatered { get; set; }
        
        public int CropId { get; set; } = -1; // -1 means nothing planted yet
        public int AgeInDays { get; set; } = 0;
        public int CurrentGrowthStage { get; set; } = 0;

        public CropTile(Point gridPos)
        {
            GridPosition = gridPos;
            IsTilled = true;
            IsWatered = false;
        }

        /// <summary>
        /// Logic step processed overnight when the player goes to sleep.
        /// </summary>
        public void AdvanceDay(CropData data)
        {
            if (!IsTilled) return;

            // Crops only grow if the soil was watered yesterday
            if (IsWatered && CropId != -1 && data != null)
            {
                AgeInDays++;
                
                // Scale growth stages mathematically across total days required
                float growthRatio = (float)AgeInDays / data.DaysToGrow;
                CurrentGrowthStage = (int)(growthRatio * (data.TotalStages - 1));
                
                if (CurrentGrowthStage >= data.TotalStages)
                {
                    CurrentGrowthStage = data.TotalStages - 1; // Cap at final maturity stage
                }
            }

            // Reset moisture state every single morning
            IsWatered = false;
        }
    }
}