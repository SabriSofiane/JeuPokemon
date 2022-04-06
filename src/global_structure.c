/**
  * \file global_structure.c
  * \brief fichier du moteur
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

#include "../include/global_structure.h"
#include "../include/window_render.h"

#include "../include/player.h"
#include "../include/text.h"
#include "../include/audio.h"
#include "../include/textures.h"
#include "../include/map.h"
#include "../include/menu.h"
#include "../include/combat.h"
#include "../include/controller.h"
/**
  * \function init_global_structure
  * \brief Constructeur du moteur de jeu
  * \param global_structure : moteur de jeux
*/
global_structure_t * init_global_structure()
{
  global_structure_t * global_structure = malloc(sizeof(global_structure_t));  // Allocation de l'espace mémoire du moteur

  /* Initialisation du moteur */
  if(global_structure == NULL)                           // On test si le moteur a bien été créer
  {
    printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
    return NULL;
  }
  else
  {
    printf("Creation du moteur\n");
  }

  global_structure->quit = 0;
  global_structure->tiles_number = 256;
  global_structure->matrice_file = NULL;
  

  /* Initialisation de la fenetre du moteur */
  if (init_window_render(&global_structure) != 0)
  {
    printf("Erreur a la initialisation de la fenetre et du rendu\n");
    return NULL;
  }
  else
  {
    printf("Creation de la fenetre\n");
  }

  /* Initialisation de la texture */
  if(init_texture(&global_structure) != 0)
  {
    printf("Erreur a la initialisation des textures\n");
    return NULL;
  }
  else
  {
    printf("Initialisation des textures\n");
  }

  if(create_window_render(&global_structure->windows->window, &global_structure->renderer,global_structure->windows->width,global_structure->windows->height) == 0)
  {
    printf("Erreur a la creation de la fenetre du moteur\n");
    free(global_structure);
    return NULL;
  } else
  {
    printf("Initialisation de la fenetre du moteur\n");
  }

  /* Initialisation des fonctions audio du jeu */
  if(audio_init(&global_structure) != 0)
  {
    printf("Erreur a la initialisation des fonctions audio\n");
    return NULL;
  } else
  {
    printf("Initialisation de l'audio\n");
  }


  /* Initialisation des fonctions textuelles du jeu */
  if(text_init(&global_structure) != 0)
  {
    printf("Erreur a la initialisation des fonctions des textuelles\n");
    return NULL;
  } else
  {
    printf("Initialisation des textuelles\n");
  }

  /* Initialisation de la structure de la map*/
  if(init_map(&global_structure) != 0)
  {
    printf("Erreur a la initialisation de la map\n");
    return NULL;
  } else
  {
    printf("Initialisation de la map\n");
  }

  /*
  global_structure->controller = malloc(sizeof(controller_t));

  global_structure->controller->controller = malloc(sizeof(SDL_GameController*));
  global_structure->controller->controller = NULL;

  global_structure->controller->leftX = 0;
  global_structure->controller->leftY = 0;
  global_structure->controller->rightX = 0;
  global_structure->controller->rightY = 0;

  global_structure->controller->press = 0;

  global_structure->controller->joy = ' ';
  */

  /* Initialisation du joueur */
  if(init_player(&global_structure) != 0)
  {
    printf("Erreur a la initialisation du joueur\n");
    return NULL;
  } else
  {
    printf("Initialisation du joueur\n");
  }

  /* Initialisation des combat */
  int pkm_enemy_ids[5] = {1,2,3,4,5};
  if(init_combat(&global_structure,pkm_enemy_ids) != 0)
  {
    printf("Erreur a la initialisation des fonctions de combats\n");
    return NULL;
  } else
  {
    printf("Initialisation des combats\n");
  }

  /* Initialisation des menus */
  if(init_menu(&global_structure) != 0)
  {
    printf("Erreur a la initialisation des fonctions des menus\n");
    return NULL;
  } else
  {
    printf("Initialisation des menus\n");
  }

  return global_structure;
}

/**
  * \function destroy_global_structure
  * \brief destructeur du moteur de jeu
  * \param global_structure : moteur de jeux
*/
void destroy_global_structure(global_structure_t ** global_structure)
{
  if(*global_structure != NULL)
  {
    destroy_window_render(&(*global_structure)->windows->window, &(*global_structure)->renderer);

    /*
    Exemple de destruction d'une texture

    SDL_DestroyTexture(global_structure->textures->texture_map);

    ⚠️ TOUJOURS détruire une élément d'une structure avant de détruire la structure
    */

    free(&(*global_structure)->textures);
    free(&(*global_structure)->windows);
    free(&(*global_structure)->player);

    free(&(*global_structure)->controller->controller);
    free(&(*global_structure)->controller->joy1);
    free(&(*global_structure)->controller->joy2);
    free(&(*global_structure)->controller);

    printf("Destruction du moteur\n");
  }

  free(*global_structure);
  *global_structure = NULL;
}
