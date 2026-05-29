using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Media;
using Microsoft.Xna.Framework.Content;

namespace FarmGame.Core
{
    /// <summary>
    /// Handles all music and sound effects, with graceful fallbacks for missing assets.
    /// </summary>
    public class AudioManager
    {
        public static AudioManager Instance { get; } = new AudioManager();

        private Dictionary<string, SoundEffect> _sfxLibrary = new Dictionary<string, SoundEffect>();
        private Dictionary<string, Song> _musicLibrary = new Dictionary<string, Song>();

        public float MusicVolume { get; private set; } = 0.5f;
        public float SFXVolume { get; private set; } = 0.8f;

        private string _currentSongKey = string.Empty;

        private AudioManager() { }

        #region Initialization
        /// <summary>
        /// Attempts to load audio files. If they don't exist, logs a warning rather than crashing.
        /// </summary>
        public void LoadAudio(ContentManager content, string key, string path, bool isMusic = false)
        {
            try
            {
                if (isMusic)
                {
                    Song song = content.Load<Song>(path);
                    _musicLibrary[key] = song;
                }
                else
                {
                    SoundEffect sfx = content.Load<SoundEffect>(path);
                    _sfxLibrary[key] = sfx;
                }
            }
            catch (ContentLoadException)
            {
                Console.WriteLine($"[WARNING] Audio file not found: {key} at {path}. Game will continue silently.");
            }
        }
        #endregion

        #region Playback
        public void PlaySFX(string key)
        {
            if (_sfxLibrary.TryGetValue(key, out SoundEffect sfx))
            {
                sfx.Play(SFXVolume, 0.0f, 0.0f);
            }
        }

        public void PlayMusic(string key)
        {
            if (key == _currentSongKey || !_musicLibrary.ContainsKey(key)) return;

            MediaPlayer.Volume = MusicVolume;
            MediaPlayer.IsRepeating = true;
            MediaPlayer.Play(_musicLibrary[key]);
            _currentSongKey = key;
        }

        public void SetMusicVolume(float volume)
        {
            MusicVolume = Math.Clamp(volume, 0f, 1f);
            MediaPlayer.Volume = MusicVolume;
        }

        public void SetSFXVolume(float volume)
        {
            SFXVolume = Math.Clamp(volume, 0f, 1f);
        }
        #endregion
    }
}