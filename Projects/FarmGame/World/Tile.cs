namespace FarmGame.World
{
    /// <summary>
    /// Represents an individual cell type on the map grid.
    /// </summary>
    public class Tile
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsWalkable { get; set; }
        public bool IsTillable { get; set; } // Can the player plow it with a hoe?

        public Tile(int id, string name, bool isWalkable, bool isTillable)
        {
            Id = id;
            Name = name;
            IsWalkable = isWalkable;
            IsTillable = isTillable;
        }
    }
}