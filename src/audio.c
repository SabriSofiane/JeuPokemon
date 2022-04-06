/**
  * \file audio.c
  * \brief fichier dédié pour les sons du jeu
  * \author Elias OKAT
  * \version 1
  * \date 28 mars 2022
*/
#include "../include/global_structure.h"
#include "../include/audio.h"
#include "../include/text.h"

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

/**
  * \function audio_init
  * \brief fonction d'Initialisation de l'audio
  * \param global_structure : moteur de jeux
*/
int audio_init(global_structure_t ** global_structure)
{
  int retour = 0;
  //(*global_structure)->musique->track_path_list
  (*global_structure)->musique = malloc(sizeof(musique_t));

  if ((*global_structure)->musique == NULL)
  {
    printf("Erreur a l'allocation de l'espace memoire pour la musique\n");
    retour--;
  }

  (*global_structure)->musique->track_in_list = 0;
  (*global_structure)->musique->volume = 1;
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
        //(*global_structure)->musique->track_path_list[(*global_structure)->musique->track_in_list] strlen(path);
        //strncpy((*global_structure)->musique->track_path_list[(*global_structure)->musique->track_in_list],path,43);
        (*global_structure)->musique->track_path_list[(*global_structure)->musique->track_in_list] = malloc(strlen(path) * sizeof(char));
        strncpy((*global_structure)->musique->track_path_list[(*global_structure)->musique->track_in_list],path,strlen(path));
        (*global_structure)->musique->track_in_list += 1;
        printf("%s ->\n", dir->d_name);
      }
    }
    closedir(d);
  }

  return(retour);
}

/**
  * \function play_sound
  * \brief fonction qui fait jouer un son mis en paramètre
  * \param global_structure : moteur de jeux
  * \param path : le chemin du fichier son
  * \param loop : variable qui defini si le son doit boucler ou non
  * \param volume : variable qui paramètre le volume du son
*/
void play_sound(global_structure_t ** global_structure,char * path,int loop,int volume)
{
  printf("PLAY AUDIO : %s\n",path);
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }

  (*global_structure)->musique->music=Mix_LoadMUS(path);
  Mix_VolumeMusic( (10 * 128) / 100);
  if(!(*global_structure)->musique->music) {
    printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
    // this might be a critical error...
  }
  if(Mix_FadeInMusic((*global_structure)->musique->music, -1,2000) == -1) {
    printf("Mix_PlayMusic: %s\n", Mix_GetError());
    // well, there's no music, but most games don't break without music...
  }
}


/**
  * \function stop_sound
  * \brief fonction qui arrète la musique
*/
void stop_sound()
{
  //Mix_FadeOutMusic(3000);
  //Mix_HaltMusic();
  //Mix_FreeMusic(musique);
}
/**
  * \function sound_quit
  * \brief Destructeur du son
*/
void sound_quit(){

}
