#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/initialisation.h"
#include "../lib/pokemon/player.h"
#include "../lib/pokemon/map.h"

  
int init(motor_t ** motor)
{
  int retour = 0;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) != 0)
    {
      printf("Erreur durant l'initialisation Video de SDL");
      retour = -1;
    }

  if (SDL_Init(SDL_INIT_JOYSTICK) != 0)
    {
      printf("Erreur durant l'initialisation de SDL Joystick");
      retour = -1;
    }

  if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
    {
      //Pas encore utilisé le 26/02/2022
      printf("Erreur durant l'initialisation SDL Gamecontroller");
      retour = -1;
    }

  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 3)
    {
      printf("Erreur durant l'initialisation de SDL IMAGE");
      retour = -1;
    }

  if (init_player(&(*motor)) != 0)
    {
      printf("Erreur durant l'initialisation du joueur");
      retour = -1;
    }

  if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
      printf("Erreur durant l'initialisation de SDL Audio");
      retour = -1;
    }

  /*
  A activer quand ajout de SDL_TTF
  if(TTF_Init() != 0)
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
*/

  if (init_map(&(*motor)) != 0)
  {
    printf("Erreur durant l'initialisation de la map");
    retour = -1;
  }

  if (init_player(&(*motor)) != 0)
  {
    printf("Erreur durant l'initialisation du joueur");
    retour = -1;
  }

  return(retour);
}
