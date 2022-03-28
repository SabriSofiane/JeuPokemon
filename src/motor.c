#include "../include/motor.h"
#include "../include/window_render.h"

#include "../include/player.h"
#include "../include/textures.h"
#include "../include/map.h"
#include "../include/controller.h"

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

/*-------------------------------------*/
//Ajouter vos nouvelle structure ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
/*-------------------------------------*/

/*
motor_t * init_motor_new()
{
    motor_t * motor = malloc(sizeof(motor_t));

    if(motor == NULL)                             // On test si le moteur a bien été créer
    {
        printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
        return NULL;
    }
    else
    {
        printf("Creation du moteur\n");
    }

    // Initialisation de la fenetre du moteur
    if (init_window_render(&motor) == -1)
    {
      printf("Erreur d'initialisation du render\n");
    }

    // Initialisation de la texture
    if (init_texture(&motor) == -1)
    {
      printf("Erreur d'initialisation des textures\n");
    }

    motor->musique = malloc(sizeof(musique_t));
    motor->menu = malloc(sizeof(menu_t));
    motor->menu->texture_speech_bubble = malloc(sizeof(SDL_Texture*));

    // Initialisation du joueur
    if (init_map(&motor) == -1)
    {
      printf("Erreur d'initialisation de la map\n");
    }

    // Initialisation du joueur
    if (init_player(&motor) == -1)
    {
      printf("Erreur d'initialisation du joueur\n");
    }



    motor->collision = SDL_TRUE;

    if(create_window_render(&motor->windows->window, &motor->renderer,motor->windows->width,motor->windows->height) == 0)
    {
        printf("Erreur a la creation de la fenetre du moteur\n");
        free(motor);
        return NULL;
    }

    motor->quit = 0;
    motor->tiles_number = 256;
    motor->matrice_file = NULL;
    motor->key_pressed = SDL_FALSE;

    for (size_t i = 0; i < SDL_NUM_SCANCODES; i++) {
      motor->key[i] = SDL_FALSE;
    }

    // Initialisation de la structure de la map


    motor->admin_console = malloc(sizeof(admin_console_t));
    motor->admin_console->selected_menu = 0;

    for (size_t i = 0; i < 10; i++) {
      strcpy(motor->admin_console->arguments[i],"");
    }

    motor->admin_console->menu_change = 0;

    return motor;
}
*/
motor_t * init_motor()
{
    motor_t * motor = malloc(sizeof(motor_t));

    if(motor == NULL)                             // On test si le moteur a bien été créer
    {
        printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
        return NULL;
    }
    else
    {
        printf("Creation du moteur\n");
    }

    /* Initialisation de la fenetre du moteur */
    init_window_render(&motor);


    /* Initialisation de la texture */
    init_texture(&motor);

    /* Initialisation du joueur */
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

    motor->collision = SDL_TRUE;

    motor->previous_time = 0;
    motor->actual_time = 0;
    if(create_window_render(&motor->windows->window, &motor->renderer,motor->windows->width,motor->windows->height) == 0)
    {
        printf("Erreur a la creation de la fenetre du moteur\n");
        free(motor);
        return NULL;
    }

    motor->quit = 0;
    motor->tiles_number = 256;
    motor->matrice_file = NULL;

    /* Initialisation de la structure de la map*/
    motor->map = malloc(sizeof(map_t));
    motor->map->map_id = 0;

    motor->admin_console = malloc(sizeof(admin_console_t));
    motor->admin_console->selected_menu = 0;

    for (size_t i = 0; i < 10; i++) {
      strcpy(motor->admin_console->arguments[i],"");
    }

    motor->admin_console->menu_change = 0;
    motor->musique = malloc(sizeof(musique_t));

    motor->menu = malloc(sizeof(menu_t));
    /*
    for (size_t i = 0; i < 10; i++) {
      motor->admin_console->keypad[i] = '';
    }
*/
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
