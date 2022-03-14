#include "../include/motor.h"
#include "../include/audio.h"
#include "../include/text.h"

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"
void audio_init(motor_t ** motor)
{
  //(*motor)->musique->track_path_list
  (*motor)->musique->track_in_list = 0;
  (*motor)->musique->volume = 0.1;
    DIR *d;
   struct dirent *dir;
   d = opendir("./src/asset/audio/");
   if (d)
   {
       while ((dir = readdir(d)) != NULL)
       {
           if (strstr(dir->d_name,".mp3"))
           {
             char path[100];
             sprintf(path,"./src/asset/audio/%s",dir->d_name);
             //(*motor)->musique->track_path_list[(*motor)->musique->track_in_list] strlen(path);
             //strncpy((*motor)->musique->track_path_list[(*motor)->musique->track_in_list],path,43);
             (*motor)->musique->track_path_list[(*motor)->musique->track_in_list] = malloc(strlen(path) * sizeof(char));
             strncpy((*motor)->musique->track_path_list[(*motor)->musique->track_in_list],path,strlen(path));
             (*motor)->musique->track_in_list += 1;
             printf("%s ->\n", dir->d_name);
           }
       }
       closedir(d);
   }


}

void play_sound(motor_t ** motor,char * path,int loop,int volume)
{
  printf("PLAY AUDIO\n");
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
     printf("%s", Mix_GetError());
  }

  (*motor)->musique->music=Mix_LoadMUS(path);
  Mix_VolumeMusic( (volume * 128) / 100);
  if(!(*motor)->musique->music) {
    printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
    // this might be a critical error...
  }
  if(Mix_FadeInMusic((*motor)->musique->music, -1,2000) == -1) {
    printf("Mix_PlayMusic: %s\n", Mix_GetError());
    // well, there's no music, but most games don't break without music...
  }

}

void stop_sound()
{
  //Mix_FadeOutMusic(3000);
  //Mix_HaltMusic();
  //Mix_FreeMusic(musique);
}

void sound_quit(){

}
