using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FarmGame.Utilities;

namespace FarmGame.Entities
{
    /// <summary>
    /// Base AI logic loop causing townfolks to wander aimlessly or stand still.
    /// </summary>
    public class NPC : Entity
    {
        public string Name { get; private set; }
        
        private float _decisionTimer;
        private int _currentAction; // 0=Idle, 1=Walking

        public NPC(string name, Vector2 spawnPosition)
        {
            Name = name;
            Position = spawnPosition;
            HitboxSize = new Vector2(24, 24);
            HitboxOffset = new Vector2(4, 8);
            ChooseNextAction();
        }

        public override void Update(GameTime gameTime)
        {
            float dt = (float)gameTime.ElapsedGameTime.TotalSeconds;
            _decisionTimer -= dt;

            if (_decisionTimer <= 0)
            {
                ChooseNextAction();
            }

            if (_currentAction == 1)
            {
                Position += Velocity * dt;
            }
        }

        private void ChooseNextAction()
        {
            _decisionTimer = Helpers.GetRandomFloat(2.0f, 5.0f); // Make choice every 2-5 seconds
            _currentAction = Helpers.GetRandomInt(0, 2); // 0 or 1

            if (_currentAction == 1)
            {
                int directionIndex = Helpers.GetRandomInt(0, 4); // 0=Up, 1=Down, 2=Left, 3=Right
                Velocity = Helpers.GetDirectionVector(directionIndex) * 40f; // Walk slow
            }
            else
            {
                Velocity = Vector2.Zero;
            }
        }

        public override void Draw(SpriteBatch spriteBatch, Texture2D texture)
        {
            if (texture != null)
            {
                spriteBatch.Draw(texture, Position, Color.White);
            }
        }
    }
}