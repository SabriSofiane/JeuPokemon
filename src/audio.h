/*
Le but de ce fichier est de fournir des fonction pour la gestion de l'audio
via la librairie "SDL_mixer"
*/

void play_sound(motor_t ** motor,char * path)
{
  printf("PLAY AUDIO\n");
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
     printf("%s", Mix_GetError());
  }

  Mix_Music *music;
  music=Mix_LoadMUS(path);
  Mix_VolumeMusic(MIX_MAX_VOLUME/2);
  if(!music) {
    printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
    // this might be a critical error...
  }
  if(Mix_PlayMusic(music, 1)==-1) {
    printf("Mix_PlayMusic: %s\n", Mix_GetError());
    // well, there's no music, but most games don't break without music...
  }

}
