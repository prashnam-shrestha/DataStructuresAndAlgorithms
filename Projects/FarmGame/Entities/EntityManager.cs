using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace FarmGame.Entities
{
    public class EntityManager
    {
        public static EntityManager Instance { get; } = new EntityManager();

        public Player MainPlayer { get; set; }
        private List<NPC> _townNPCs = new List<NPC>();

        private EntityManager() { }

        public void AddNPC(NPC npc) => _townNPCs.Add(npc);

        public void Update(GameTime gameTime)
        {
            MainPlayer?.Update(gameTime);
            foreach (var npc in _townNPCs)
                npc.Update(gameTime);
        }

        // Original Draw kept for compatibility
        public void Draw(SpriteBatch spriteBatch, Texture2D spritesheet)
            => DrawWithFallbacks(spriteBatch, spritesheet, spritesheet);

        /// <summary>
        /// Draws player and NPCs with separate fallback textures so each
        /// is visible even when no spritesheet asset is loaded.
        /// </summary>
        public void DrawWithFallbacks(SpriteBatch spriteBatch, Texture2D playerTex, Texture2D npcTex)
        {
            List<Entity> renderList = new List<Entity>();
            if (MainPlayer != null) renderList.Add(MainPlayer);
            renderList.AddRange(_townNPCs);

            // Y-sort so characters behind others draw first
            renderList.Sort((a, b) => a.Position.Y.CompareTo(b.Position.Y));

            foreach (var entity in renderList)
            {
                Texture2D tex = (entity is Player) ? playerTex : npcTex;
                entity.Draw(spriteBatch, tex);
            }
        }
    }
}