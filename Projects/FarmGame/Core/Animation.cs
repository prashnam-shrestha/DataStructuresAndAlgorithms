using Microsoft.Xna.Framework;

namespace FarmGame.Core
{
    /// <summary>
    /// Tracks spritesheet frames and timers to handle running, harvesting, or idling animations.
    /// </summary>
    public class Animation
    {
        public int FrameWidth { get; private set; }
        public int FrameHeight { get; private set; }
        public int FrameCount { get; private set; }
        public int CurrentFrame { get; private set; }

        private float _frameTimer;
        private float _frameDuration; // How long each frame displays (e.g., 0.1f seconds)
        private bool _isLooping;

        public Animation(int frameWidth, int frameHeight, int frameCount, float frameDuration, bool isLooping = true)
        {
            FrameWidth = frameWidth;
            FrameHeight = frameHeight;
            FrameCount = frameCount;
            _frameDuration = frameDuration;
            _isLooping = isLooping;
            _frameTimer = frameDuration;
            CurrentFrame = 0;
        }

        #region Animation Engine
        /// <summary>
        /// Steps the frame sequence forward based on elapsed real-world delta time.
        /// </summary>
        public void Update(GameTime gameTime)
        {
            float dt = (float)gameTime.ElapsedGameTime.TotalSeconds;
            _frameTimer -= dt;

            if (_frameTimer <= 0f)
            {
                _frameTimer = _frameDuration;
                CurrentFrame++;

                if (CurrentFrame >= FrameCount)
                {
                    if (_isLooping)
                    {
                        CurrentFrame = 0;
                    }
                    else
                    {
                        CurrentFrame = FrameCount - 1; // Freeze on the final frame
                    }
                }
            }
        }

        public void Reset()
        {
            CurrentFrame = 0;
            _frameTimer = _frameDuration;
        }

        /// <summary>
        /// Generates the crop/cut boundaries mapping onto your master spritesheet graphic texture.
        /// </summary>
        public Rectangle GetSourceRectangle(int rowOffset = 0)
        {
            return new Rectangle(CurrentFrame * FrameWidth, rowOffset * FrameHeight, FrameWidth, FrameHeight);
        }
        #endregion
    }
}