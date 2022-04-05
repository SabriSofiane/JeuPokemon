#include "../include/motor.h"

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
