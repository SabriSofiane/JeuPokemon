#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

#include "../include/motor.h"
#include "../include/window_render.h"

#include "../include/player.h"
#include "../include/text.h"
#include "../include/audio.h"
#include "../include/textures.h"
#include "../include/map.h"
#include "../include/menu.h"
#include "../include/combat.h"
#include "../include/controller.h"

motor_t * init_motor()
{
  motor_t * motor = malloc(sizeof(motor_t));  // Allocation de l'espace mémoire du moteur

  /* Initialisation du moteur */
  if(motor == NULL)                           // On test si le moteur a bien été créer
  {
    printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
    return NULL;
  }
  else
  {
    printf("Creation du moteur\n");
  }

  motor->quit = 0;
  motor->tiles_number = 256;
  motor->matrice_file = NULL;
  srand(time(0));

  /* Initialisation de la fenetre du moteur */
  if (init_window_render(&motor) != 0)
  {
    printf("Erreur a la initialisation de la fenetre et du rendu\n");
    return NULL;
  }
  else
  {
    printf("Creation de la fenetre\n");
  }

  /* Initialisation de la texture */
  if(init_texture(&motor) != 0)
  {
    printf("Erreur a la initialisation des textures\n");
    return NULL;
  }
  else
  {
    printf("Initialisation des textures\n");
  }

  if(create_window_render(&motor->windows->window, &motor->renderer,motor->windows->width,motor->windows->height) == 0)
  {
    printf("Erreur a la creation de la fenetre du moteur\n");
    free(motor);
    return NULL;
  } else
  {
    printf("Initialisation de la fenetre du moteur\n");
  }

  /* Initialisation des fonctions audio du jeu */
  if(audio_init(&motor) != 0)
  {
    printf("Erreur a la initialisation des fonctions audio\n");
    return NULL;
  } else
  {
    printf("Initialisation de l'audio\n");
  }


  /* Initialisation des fonctions textuelles du jeu */
  if(text_init(&motor) != 0)
  {
    printf("Erreur a la initialisation des fonctions des textuelles\n");
    return NULL;
  } else
  {
    printf("Initialisation des textuelles\n");
  }

  /* Initialisation de la structure de la map*/
  if(init_map(&motor) != 0)
  {
    printf("Erreur a la initialisation de la map\n");
    return NULL;
  } else
  {
    printf("Initialisation de la map\n");
  }

  /*
  motor->controller = malloc(sizeof(controller_t));

  motor->controller->controller = malloc(sizeof(SDL_GameController*));
  motor->controller->controller = NULL;

  motor->controller->leftX = 0;
  motor->controller->leftY = 0;
  motor->controller->rightX = 0;
  motor->controller->rightY = 0;

  motor->controller->press = 0;

  motor->controller->joy = ' ';
  */

  /* Initialisation du joueur */
  if(init_player(&motor) != 0)
  {
    printf("Erreur a la initialisation du joueur\n");
    return NULL;
  } else
  {
    printf("Initialisation du joueur\n");
  }

  /* Initialisation des combat */
  int pkm_enemy_ids[5] = {1,2,3,4,5};
  if(init_combat(&motor,pkm_enemy_ids) != 0)
  {
    printf("Erreur a la initialisation des fonctions de combats\n");
    return NULL;
  } else
  {
    printf("Initialisation des combats\n");
  }

  /* Initialisation des menus */
  if(init_menu(&motor) != 0)
  {
    printf("Erreur a la initialisation des fonctions des menus\n");
    return NULL;
  } else
  {
    printf("Initialisation des menus\n");
  }

  return motor;
}


void destroy_motor(motor_t ** motor)
{
  if(*motor != NULL)
  {
    destroy_window_render(&(*motor)->windows->window, &(*motor)->renderer);

    /*
    Exemple de destruction d'une texture

    SDL_DestroyTexture(motor->textures->texture_map);

    ⚠️ TOUJOURS détruire une élément d'une structure avant de détruire la structure
    */

    free(&(*motor)->textures);
    free(&(*motor)->windows);
    free(&(*motor)->player);

    free(&(*motor)->controller->controller);
    free(&(*motor)->controller->joy1);
    free(&(*motor)->controller->joy2);
    free(&(*motor)->controller);

    printf("Destruction du moteur\n");
  }

  free(*motor);
  *motor = NULL;
}
