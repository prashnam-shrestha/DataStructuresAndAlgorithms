using Microsoft.Xna.Framework;

namespace FarmGame.Core
{
    /// <summary>
    /// Handles simple bounding box collisions between entities and the environment.
    /// </summary>
    public class CollisionManager
    {
        public static CollisionManager Instance { get; } = new CollisionManager();

        private CollisionManager() { }

        #region Queries
        /// <summary>
        /// Checks if an intended movement will overlap with a solid/non-walkable tile.
        /// (TileMap implementation will be fully defined in World/TileMap.cs later).
        /// </summary>
        /// <param name="bounds">The entity's bounding box.</param>
        /// <param name="mapWidth">Map width in tiles.</param>
        /// <param name="mapHeight">Map height in tiles.</param>
        /// <param name="tileSize">Size of one tile in pixels.</param>
        /// <param name="isTileWalkableFunc">A function that returns whether a specific grid X,Y is walkable.</param>
        public bool IsCollidingWithWorld(Rectangle bounds, int mapWidth, int mapHeight, int tileSize, System.Func<int, int, bool> isTileWalkableFunc)
        {
            // Calculate which grid tiles the bounding box is overlapping
            int leftTile = bounds.Left / tileSize;
            int rightTile = bounds.Right / tileSize;
            int topTile = bounds.Top / tileSize;
            int bottomTile = bounds.Bottom / tileSize;

            // Keep within map bounds
            if (leftTile < 0 || rightTile >= mapWidth || topTile < 0 || bottomTile >= mapHeight)
            {
                return true; // Consider off-map as colliding
            }

            // Check every tile the bounding box touches
            for (int x = leftTile; x <= rightTile; x++)
            {
                for (int y = topTile; y <= bottomTile; y++)
                {
                    if (!isTileWalkableFunc(x, y))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
        #endregion
    }
}