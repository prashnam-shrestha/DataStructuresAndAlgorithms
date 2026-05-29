using Microsoft.Xna.Framework;
using System;

namespace FarmGame.Utilities
{
    /// <summary>
    /// Useful extension methods for MonoGame math and logic.
    /// </summary>
    public static class Extensions
    {
        /// <summary>
        /// Converts a 2D position to grid/tile coordinates.
        /// </summary>
        public static Point ToGrid(this Vector2 position)
        {
            return new Point(
                (int)Math.Floor(position.X / Constants.TileSize),
                (int)Math.Floor(position.Y / Constants.TileSize)
            );
        }

        /// <summary>
        /// Gets the center position of a tile coordinate.
        /// </summary>
        public static Vector2 ToVector2Center(this Point gridPos)
        {
            return new Vector2(
                (gridPos.X * Constants.TileSize) + (Constants.TileSize / 2f),
                (gridPos.Y * Constants.TileSize) + (Constants.TileSize / 2f)
            );
        }
    }
}