using System.Collections.Generic;
using FarmGame.Entities;

namespace FarmGame.Inventory
{
    /// <summary>
    /// Processes mercantile calculations for merchant exchanges, matching gold stores vs costs.
    /// </summary>
    public class ShopManager
    {
        public static ShopManager Instance { get; } = new ShopManager();

        public List<Item> MerchantStock { get; private set; } = new List<List<Item>>().Find(x => true) ?? new List<Item>();

        private ShopManager()
        {
            SetupDefaultStock();
        }

        private void SetupDefaultStock()
        {
            // Seed base items for Pierre's shop style interaction
            MerchantStock.Add(new Item(100, "Parsnip Seeds", "Planted in spring. Takes 4 days.", ItemType.Seed, 20));
            MerchantStock.Add(new Item(101, "Cauliflower Seeds", "Planted in spring. Takes 12 days.", ItemType.Seed, 80));
        }

        #region Transactions
        public bool BuyItem(Player player, InventorySystem inventory, Item targetItem)
        {
            if (player.Money >= targetItem.Value)
            {
                // Clone the item specification to create a distinct item object for the player
                Item purchasedCopy = targetItem.Clone(1);
                
                if (inventory.AddItem(purchasedCopy))
                {
                    player.Money -= targetItem.Value;
                    return true; // Success!
                }
            }
            return false; // Cash short or storage full!
        }

        public void SellItem(Player player, InventorySystem inventory, int itemSlotIndex)
        {
            Item itemToSell = inventory.Slots[itemSlotIndex];
            if (itemToSell != null && itemToSell.Type == ItemType.Crop)
            {
                player.Money += itemToSell.Value;
                inventory.RemoveItem(itemSlotIndex, 1);
            }
        }
        #endregion
    }
}