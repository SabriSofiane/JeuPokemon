/**
  * \file controller.c
  * \brief fichier de configuration pour jouer avec une manette
  * \author Elias OKAT
  * \version 1
  * \date 28 mars 2022
*/
#include "../include/global_structure.h"
/**
  * \function init_controller
  * \brief fonction d'Initialisation de la manette de jeu
  * \param: moteur de jeu
*/
int init_controller(global_structure_t ** global_structure)
{
  (*global_structure)->controller = malloc(sizeof(controller_t));

  (*global_structure)->controller->controller = malloc(sizeof(SDL_GameController*));
  (*global_structure)->controller->controller = NULL;

  (*global_structure)->controller->leftX = 0;
  (*global_structure)->controller->leftY = 0;
  (*global_structure)->controller->rightX = 0;
  (*global_structure)->controller->rightY = 0;

  (*global_structure)->controller->press = 0;

  (*global_structure)->controller->joy = ' ';
}
