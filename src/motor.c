#include "../include/motor.h"
#include "../include/window_render.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

/*-------------------------------------*/
//Ajouter vos nouvelle structure ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
/*-------------------------------------*/


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
    motor->windows = malloc(sizeof(window_t));    // Allocation de l'espace mémoire pour la fenetre
    motor->windows->width = 1280;                 // Définition de la largeur de la fenetre
    motor->windows->height = 720;                 // Définition de la hauteur de la fenetre
    motor->windows->size_coef = 2;                // Définition du Coefficient d'échelle (ne vraiment pas modifier svp)
    motor->windows->font = malloc(sizeof(TTF_Font*));


    /* Initialisation de la texture */
    motor->textures = malloc(sizeof(texture_t));

    motor->textures->texture_map = malloc(sizeof(SDL_Texture*));

    /* Initialisation du joueur */
    motor->player = malloc(sizeof(player_t));
    motor->controller = malloc(sizeof(controller_t));

    motor->controller->controller = malloc(sizeof(SDL_GameController*));
    motor->controller->controller = NULL;

    motor->controller->leftX = 0;
    motor->controller->leftY = 0;
    motor->controller->rightX = 0;
    motor->controller->rightY = 0;

    motor->controller->press = 0;

    motor->controller->joy = ' ';

    motor->player->movement_id = 1;
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
    motor->key_pressed = SDL_FALSE;

    for (size_t i = 0; i < SDL_NUM_SCANCODES; i++) {
      motor->key[i] = SDL_FALSE;
    }

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
