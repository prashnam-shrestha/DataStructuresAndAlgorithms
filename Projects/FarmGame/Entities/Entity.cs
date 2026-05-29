using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FarmGame.Entities
{
    /// <summary>
    /// Abstract base rule class for everything moving or interactable in the game world.
    /// </summary>
    public abstract class Entity
    {
        public Vector2 Position { get; set; }
        public Vector2 Velocity { get; set; }
        public Vector2 HitboxSize { get; set; } = new Vector2(24, 24);
        public Vector2 HitboxOffset { get; set; } = new Vector2(4, 8);
        public bool IsActive { get; set; } = true;

        public Rectangle Bounds => new Rectangle(
            (int)(Position.X + HitboxOffset.X),
            (int)(Position.Y + HitboxOffset.Y),
            (int)HitboxSize.X,
            (int)HitboxSize.Y
        );

        public abstract void Update(GameTime gameTime);
        public abstract void Draw(SpriteBatch spriteBatch, Texture2D texture);
    }
}