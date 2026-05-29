using Microsoft.Xna.Framework;
using FarmGame.Core;
using FarmGame.Farming;
using FarmGame.Inventory;
using FarmGame.Utilities; // ← THIS WAS MISSING (needed for Constants)

namespace FarmGame.World
{
    /// <summary>
    /// Governs player tile alignment calculations for clearing weeds, hoeing, or laying floor path objects.
    /// </summary>
    public class PlacementManager
    {
        public static PlacementManager Instance { get; } = new PlacementManager();

        private PlacementManager() { }

        #region Matrix Modifiers
        public void UseToolAtLocation(Point gridPos, Item activeItem)
        {
            if (activeItem == null || activeItem.Type != ItemType.Tool) return;

            FarmingManager farming = FarmingManager.Instance;

            if (activeItem.Name == "Hoe")
            {
                farming.TillSoil(gridPos);
                AudioManager.Instance.PlaySFX(Constants.SfxFootstep);
            }
            else if (activeItem.Name == "Watering Can")
            {
                farming.WaterSoil(gridPos);
            }
        }

        public bool DeploySeedAtLocation(Point gridPos, Item seedItem, InventorySystem sourceInventory, int activeSlot)
        {
            if (seedItem == null || seedItem.Type != ItemType.Seed) return false;

            int targetCropId = (seedItem.Id == 100) ? 0 : 1;

            if (FarmingManager.Instance.PlantSeed(gridPos, targetCropId))
            {
                sourceInventory.RemoveItem(activeSlot, 1);
                return true;
            }

            return false;
        }
        #endregion
    }
}