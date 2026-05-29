using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FarmGame.World
{
    /// <summary>
    /// Defines immutable architectural boundaries like your farmhouse, barns, or shipping boxes.
    /// </summary>
    public class Building
    {
        public string Name { get; private set; }
        public Vector2 Position { get; private set; }
        public Rectangle SolidCollisionBox { get; private set; }

        public Building(string name, Vector2 gridPosition, int widthInTiles, int heightInTiles, int tileSize = 32)
        {
            Name = name;
            Position = gridPosition * tileSize;
            
            // Build absolute world coordinates footprint boundary box
            SolidCollisionBox = new Rectangle(
                (int)Position.X,
                (int)Position.Y,
                widthInTiles * tileSize,
                heightInTiles * tileSize
            );
        }

        #region Output Draw
        public void Draw(SpriteBatch spriteBatch, Texture2D buildingTexture)
        {
            if (buildingTexture != null)
            {
                spriteBatch.Draw(buildingTexture, Position, Color.White);
            }
        }
        #endregion
    }
}