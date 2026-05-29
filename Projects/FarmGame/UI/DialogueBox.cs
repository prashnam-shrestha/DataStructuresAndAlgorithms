using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FarmGame.Core;
using FarmGame.Utilities;

namespace FarmGame.UI
{
    /// <summary>
    /// Renders the layout panel, text lines, and speaker names for social interactions.
    /// </summary>
    public class DialogueBox
    {
        public void Draw(SpriteBatch spriteBatch, SpriteFont font)
        {
            DialogueManager dialogue = DialogueManager.Instance;
            if (!dialogue.IsDialogueActive || font == null) return;

            int x = 50;
            int y = Constants.ScreenHeight - 200;

            // Render speaker identity label
            spriteBatch.DrawString(font, dialogue.SpeakerName, new Vector2(x + 20, y + 15), Color.Khaki);
            
            // Render actual conversational subtitle text line
            spriteBatch.DrawString(font, dialogue.CurrentLine, new Vector2(x + 20, y + 55), Color.White);
        }
    }
}