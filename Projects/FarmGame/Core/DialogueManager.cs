using System;
using System.Collections.Generic;

namespace FarmGame.Core
{
    /// <summary>
    /// Governs dialogue text lines, typing states, and event hooks for closing chats.
    /// </summary>
    public class DialogueManager
    {
        public static DialogueManager Instance { get; } = new DialogueManager();

        public bool IsDialogueActive { get; private set; } = false;
        public string SpeakerName { get; private set; } = string.Empty;
        public string CurrentLine => _dialogueLines.Count > 0 ? _dialogueLines[_currentLineIndex] : string.Empty;

        private List<string> _dialogueLines = new List<string>();
        private int _currentLineIndex = 0;

        public event Action OnDialogueComplete;

        private DialogueManager() { }

        #region Flow Rules
        /// <summary>
        /// Loads lines of dialog text and displays the conversational frame over the HUD.
        /// </summary>
        public void StartDialogue(string speaker, string[] lines)
        {
            if (lines == null || lines.Length == 0) return;

            SpeakerName = speaker;
            _dialogueLines = new List<string>(lines);
            _currentLineIndex = 0;
            IsDialogueActive = true;
            TimeManager.Instance.IsPaused = true; // Lock clock while talking
        }

        /// <summary>
        /// Advances to the next line of dialogue, or exits if it was the final sentence.
        /// </summary>
        public void AdvanceDialogue()
        {
            if (!IsDialogueActive) return;

            _currentLineIndex++;
            if (_currentLineIndex >= _dialogueLines.Count)
            {
                // Sequence completed cleanly
                IsDialogueActive = false;
                _dialogueLines.Clear();
                TimeManager.Instance.IsPaused = false;
                OnDialogueComplete?.Invoke();
            }
        }
        #endregion
    }
}