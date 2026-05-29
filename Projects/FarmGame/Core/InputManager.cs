using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace FarmGame.Core
{
    /// <summary>
    /// Singleton class handling all keyboard and mouse inputs.
    /// </summary>
    public class InputManager
    {
        public static InputManager Instance { get; } = new InputManager();

        private KeyboardState _currentKeyState;
        private KeyboardState _previousKeyState;
        private MouseState _currentMouseState;
        private MouseState _previousMouseState;

        private InputManager() { }

        #region Update
        /// <summary>
        /// Updates the current and previous input states. Call this once per frame.
        /// </summary>
        public void Update()
        {
            _previousKeyState = _currentKeyState;
            _currentKeyState = Keyboard.GetState();

            _previousMouseState = _currentMouseState;
            _currentMouseState = Mouse.GetState();
        }
        #endregion

        #region Keyboard Helpers
        /// <summary>
        /// Checks if a key is currently held down.
        /// </summary>
        public bool IsKeyDown(Keys key) => _currentKeyState.IsKeyDown(key);

        /// <summary>
        /// Checks if a key was just pressed this exact frame.
        /// </summary>
        public bool IsKeyPressed(Keys key) => _currentKeyState.IsKeyDown(key) && !_previousKeyState.IsKeyDown(key);
        #endregion

        #region Mouse Helpers
        /// <summary>
        /// Checks if the left mouse button was just clicked this frame.
        /// </summary>
        public bool IsLeftMouseClicked() => _currentMouseState.LeftButton == ButtonState.Pressed && _previousMouseState.LeftButton == ButtonState.Released;

        /// <summary>
        /// Checks if the right mouse button was just clicked this frame.
        /// </summary>
        public bool IsRightMouseClicked() => _currentMouseState.RightButton == ButtonState.Pressed && _previousMouseState.RightButton == ButtonState.Released;

        /// <summary>
        /// Gets the current screen-space mouse position.
        /// </summary>
        public Vector2 GetMousePosition() => new Vector2(_currentMouseState.X, _currentMouseState.Y);

        /// <summary>
        /// Returns the scroll wheel value delta (difference) since last frame.
        /// </summary>
        public int GetScrollDelta() => _currentMouseState.ScrollWheelValue - _previousMouseState.ScrollWheelValue;
        #endregion
    }
}