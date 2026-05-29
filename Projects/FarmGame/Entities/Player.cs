using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using FarmGame.Core;
using FarmGame.Utilities;

namespace FarmGame.Entities
{
    public class Player : Entity
    {
        public float Health { get; set; } = Constants.MaxHealth;
        public float Stamina { get; set; } = Constants.MaxStamina;
        public int Money { get; set; } = 500;

        public int FacingDirection { get; private set; } = 1; // 0=Up, 1=Down, 2=Left, 3=Right

        public Player(Vector2 spawnPosition)
        {
            Position = spawnPosition;
            HitboxSize = new Vector2(24, 16);
            HitboxOffset = new Vector2(4, 16);
        }

        public override void Update(GameTime gameTime)
        {
            float dt = (float)gameTime.ElapsedGameTime.TotalSeconds;
            HandleInput(dt);

            // ✅ THIS WAS MISSING — actually move the player by applying velocity
            Position += Velocity * dt;
        }

        private void HandleInput(float dt)
        {
            Vector2 moveInput = Vector2.Zero;
            InputManager input = InputManager.Instance;

            if (input.IsKeyDown(Keys.W) || input.IsKeyDown(Keys.Up))    { moveInput.Y -= 1; FacingDirection = 0; }
            if (input.IsKeyDown(Keys.S) || input.IsKeyDown(Keys.Down))  { moveInput.Y += 1; FacingDirection = 1; }
            if (input.IsKeyDown(Keys.A) || input.IsKeyDown(Keys.Left))  { moveInput.X -= 1; FacingDirection = 2; }
            if (input.IsKeyDown(Keys.D) || input.IsKeyDown(Keys.Right)) { moveInput.X += 1; FacingDirection = 3; }

            if (moveInput != Vector2.Zero)
            {
                moveInput.Normalize();
                float currentSpeed = Constants.PlayerBaseSpeed;

                if (input.IsKeyDown(Keys.LeftShift) && Stamina > 5f)
                {
                    currentSpeed *= Constants.PlayerSprintMultiplier;
                    Stamina -= 12f * dt;
                }

                Velocity = moveInput * currentSpeed;
            }
            else
            {
                Velocity = Vector2.Zero;
            }

            if (Velocity == Vector2.Zero && Stamina < Constants.MaxStamina)
            {
                Stamina += 2f * dt;
            }
        }

        public override void Draw(SpriteBatch spriteBatch, Texture2D texture)
        {
            if (texture != null)
            {
                // Draw full texture (ignoring source rect since it's a plain fallback square)
                spriteBatch.Draw(texture, Position, Color.White);
            }
        }

        public void ConsumeStamina(float amount)
        {
            Stamina = Math.Max(0, Stamina - amount);
        }
    }
}