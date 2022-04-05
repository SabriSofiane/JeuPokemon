/**
  * \file controller.c
  * \brief fichier de configuration pour jouer avec une manette
  * \author Elias OKAT
  * \version 1
  * \date 28 mars 2022
*/
#include "../include/motor.h"
/**
  * \function init_controller
  * \brief fonction d'Initialisation de la manette de jeu
  * \param: moteur de jeu
*/
int init_controller(motor_t ** motor)
{
  (*motor)->controller = malloc(sizeof(controller_t));

  (*motor)->controller->controller = malloc(sizeof(SDL_GameController*));
  (*motor)->controller->controller = NULL;

  (*motor)->controller->leftX = 0;
  (*motor)->controller->leftY = 0;
  (*motor)->controller->rightX = 0;
  (*motor)->controller->rightY = 0;

  (*motor)->controller->press = 0;

  (*motor)->controller->joy = ' ';
}
