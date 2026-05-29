namespace FarmGame.Farming
{
    /// <summary>
    /// Standard configurations defining crop varieties, stages, and seasonal restrictions.
    /// </summary>
    public class CropData
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int DaysToGrow { get; set; }
        public int TotalStages { get; set; } = 4; // Seeds, sprout, mid-growth, harvest-ready
        public int HarvestedItemId { get; set; }
        public int SeedPrice { get; set; }

        public CropData(int id, string name, int daysToGrow, int harvestedItemId, int seedPrice)
        {
            Id = id;
            Name = name;
            DaysToGrow = daysToGrow;
            HarvestedItemId = harvestedItemId;
            SeedPrice = seedPrice;
        }
    }
}