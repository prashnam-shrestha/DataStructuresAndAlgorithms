using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FarmGame.Utilities
{
    /// <summary>
    /// Generates colored procedural textures so the game has graphics even without loaded art files.
    /// </summary>
    public static class TextureFactory
    {
        public static Texture2D CreateSolidColor(GraphicsDevice device, int width, int height, Color color)
        {
            Texture2D texture = new Texture2D(device, width, height);
            Color[] data = new Color[width * height];
            for (int i = 0; i < data.Length; ++i) data[i] = color;
            texture.SetData(data);
            return texture;
        }

        public static Texture2D GeneratePlayerTexture(GraphicsDevice device)
        {
            // Generates a 128x32 spritesheet (4 frames: Up, Down, Left, Right)
            Texture2D texture = new Texture2D(device, 128, 32);
            Color[] data = new Color[128 * 32];
            
            // Fill completely blue
            for (int i = 0; i < data.Length; ++i) data[i] = Color.CornflowerBlue;
            texture.SetData(data);
            return texture;
        }

        public static Texture2D GenerateTileset(GraphicsDevice device)
        {
            // Generates a wide texture where each 32x32 block is a different tile color
            Texture2D texture = new Texture2D(device, 256, 32);
            Color[] data = new Color[256 * 32];
            
            for (int x = 0; x < 256; x++)
            {
                for (int y = 0; y < 32; y++)
                {
                    int index = y * 256 + x;
                    int tileId = x / 32;
                    
                    if (tileId == 0) data[index] = Color.ForestGreen; // Grass
                    else if (tileId == 1) data[index] = Color.SaddleBrown; // Fence/Wood
                    else if (tileId == 2) data[index] = Color.DodgerBlue; // Water
                    else if (tileId == 7) data[index] = Color.Tan; // Path
                    else data[index] = Color.Gray; // Default
                }
            }
            texture.SetData(data);
            return texture;
        }
    }
}