using System;

namespace FarmGame.Inventory
{
    /// <summary>
    /// Manages an array of item slots, item stacking limits, and hotbar tracking.
    /// </summary>
    public class InventorySystem
    {
        public Item[] Slots { get; private set; }
        public int SelectedSlotIndex { get; set; } = 0;
        public int Size => Slots.Length;

        public InventorySystem(int size = 24)
        {
            Slots = new Item[size];
        }

        #region Inventory Logic
        /// <summary>
        /// Attempts to add an item to the backpack, matching existing stacks first.
        /// </summary>
        public bool AddItem(Item item)
        {
            // Step 1: Look for an existing stack of the same item type
            for (int i = 0; i < Slots.Length; i++)
            {
                if (Slots[i] != null && Slots[i].Id == item.Id && Slots[i].StackSize < Slots[i].MaxStack)
                {
                    int spaceLeft = Slots[i].MaxStack - Slots[i].StackSize;
                    int amountToAdd = Math.Min(spaceLeft, item.StackSize);

                    Slots[i].StackSize += amountToAdd;
                    item.StackSize -= amountToAdd;

                    if (item.StackSize <= 0) return true;
                }
            }

            // Step 2: If items remain, look for a completely empty room slot
            for (int i = 0; i < Slots.Length; i++)
            {
                if (Slots[i] == null)
                {
                    Slots[i] = item;
                    return true;
                }
            }

            return false; // Inventory full!
        }

        /// <summary>
        /// Removes a quantity of items from a specific slot index.
        /// </summary>
        public void RemoveItem(int index, int amount = 1)
        {
            if (index < 0 || index >= Slots.Length || Slots[index] == null) return;

            Slots[index].StackSize -= amount;
            if (Slots[index].StackSize <= 0)
            {
                Slots[index] = null;
            }
        }

        public Item GetActiveItem()
        {
            if (SelectedSlotIndex < 0 || SelectedSlotIndex >= Slots.Length) return null;
            return Slots[SelectedSlotIndex];
        }
        #endregion
    }
}