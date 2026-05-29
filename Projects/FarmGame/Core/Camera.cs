using Microsoft.Xna.Framework;

namespace FarmGame.Core
{
    /// <summary>
    /// Manages the viewport matrix transformation to follow the player across the map layers.
    /// </summary>
    public class Camera
    {
        public static Camera Instance { get; } = new Camera(); // ← THIS LINE WAS MISSING

        public Matrix Transform { get; private set; }
        public float Zoom { get; set; } = 1.0f;

        private Camera() // ← make private to enforce singleton
        {
            Transform = Matrix.Identity;
        }

        /// <summary>
        /// Centers the camera viewport matrix smoothly onto a target position.
        /// </summary>
        public void Follow(Vector2 target, int screenWidth, int screenHeight)
        {
            Transform = Matrix.CreateTranslation(new Vector3(-target.X, -target.Y, 0)) *
                        Matrix.CreateScale(new Vector3(Zoom, Zoom, 1)) *
                        Matrix.CreateTranslation(new Vector3(screenWidth / 2f, screenHeight / 2f, 0));
        }
    }
}