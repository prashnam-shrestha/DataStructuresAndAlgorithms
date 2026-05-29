using System;
using Microsoft.Xna.Framework;

namespace FarmGame.Utilities
{
    /// <summary>
    /// General helper functions, such as RNG and pathfinding stubs.
    /// </summary>
    public static class Helpers
    {
        private static readonly Random _random = new Random();

        /// <summary>
        /// Returns a random float between min and max.
        /// </summary>
        public static float GetRandomFloat(float min, float max)
        {
            return (float)(_random.NextDouble() * (max - min) + min);
        }

        /// <summary>
        /// Returns a random integer between min (inclusive) and max (exclusive).
        /// </summary>
        public static int GetRandomInt(int min, int max)
        {
            return _random.Next(min, max);
        }

        /// <summary>
        /// Helper for simple directional velocity based on a facing enum.
        /// </summary>
        public static Vector2 GetDirectionVector(int facingEnumId)
        {
            // Assuming 0=Up, 1=Down, 2=Left, 3=Right
            return facingEnumId switch
            {
                0 => new Vector2(0, -1),
                1 => new Vector2(0, 1),
                2 => new Vector2(-1, 0),
                3 => new Vector2(1, 0),
                _ => Vector2.Zero
            };
        }
    }
}