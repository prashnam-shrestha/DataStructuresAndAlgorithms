namespace FarmGame.Inventory
{
    public enum ItemType { Tool, Seed, Crop, Resource, Foragable }

    /// <summary>
    /// Definition blueprint of an object that can exist in an inventory slot.
    /// </summary>
    public class Item
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public ItemType Type { get; set; }
        public int StackSize { get; set; }
        public int MaxStack { get; set; } = 99;
        public int Value { get; set; } // Sell price

        public Item(int id, string name, string description, ItemType type, int value, int stackSize = 1)
        {
            Id = id;
            Name = name;
            Description = description;
            Type = type;
            Value = value;
            StackSize = stackSize;
        }

        /// <summary>
        /// Creates an identical duplicate copy of this item.
        /// </summary>
        public Item Clone(int count = 1)
        {
            return new Item(Id, Name, Description, Type, Value, count) { MaxStack = this.MaxStack };
        }
    }
}