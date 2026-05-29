using System.Collections.Generic;

namespace FarmGame.Inventory
{
    /// <summary>
    /// Static collection repository containing definitions for every tool, seed, and crop.
    /// </summary>
    public static class ItemDatabase
    {
        private static Dictionary<int, Item> _items = new Dictionary<int, Item>();

        static ItemDatabase()
        {
            // Tools configurations
            _items[0] = new Item(0, "Hoe", "Used to till soil.", ItemType.Tool, 0);
            _items[1] = new Item(1, "Watering Can", "Used to water crops.", ItemType.Tool, 0);

            // Harvested crops objects
            _items[50] = new Item(50, "Parsnip", "A juicy root vegetable.", ItemType.Crop, 35);
            _items[51] = new Item(51, "Cauliflower", "Valuable compact white head florets.", ItemType.Crop, 175);
        }

        /// <summary>
        /// Fetches a unique item clone instantiation out of base catalog records safely.
        /// </summary>
        public static Item GetItem(int id)
        {
            if (_items.TryGetValue(id, out Item item))
            {
                return item.Clone(1);
            }
            return null;
        }
    }
}