#include "../include/motor.h"
#include "../include/event.h"
#include "../include/string_matrice.h"
#include "../include/collisions.h"
#include "../include/audio.h"
#include "../include/menu.h"


void mouvement(motor_t ** motor, float move_add, char axis) {
  if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key == 1)
  {
    if (axis == 'x')
    {
      (*motor)->player->posX += move_add;
    }
      else if (axis == 'y')
    {
      (*motor)->player->posY += move_add;
    }

    if ((*motor)->keys.z_key == 1)
    {
      (*motor)->keys.q_key = 0;
      (*motor)->keys.s_key = 0;
      (*motor)->keys.d_key = 0;
    } else if ((*motor)->keys.q_key == 1)
    {
      (*motor)->keys.z_key = 0;
      (*motor)->keys.s_key = 0;
      (*motor)->keys.d_key = 0;
    } else if ((*motor)->keys.s_key == 1)
    {
      (*motor)->keys.z_key = 0;
      (*motor)->keys.q_key = 0;
      (*motor)->keys.d_key = 0;
    } else if ((*motor)->keys.d_key == 1)
    {
      (*motor)->keys.z_key = 0;
      (*motor)->keys.q_key = 0;
      (*motor)->keys.s_key = 0;
    }
  }
}

int event_handle(motor_t ** motor) {

  while (SDL_PollEvent(&(*motor)->event)) {

    float move_step =  (*motor)->player->move_step;

    if ((*motor)->event.type == SDL_KEYDOWN)
    {
      switch ((*motor)->event.key.keysym.sym)
      {
      case SDLK_z:

      if (((*motor)->keys.q_key + (*motor)->keys.d_key) == 0)
      {
        if ((*motor)->keys.lastkey != 'z')
        (*motor)->player->posY += (-1)*move_step;
        else if (((*motor)->keys.z_key == 0))
        (*motor)->player->posY += (-1)*move_step;

        if (((*motor)->keys.z_key == 0))
          (*motor)->player->movement_id = 1;


        (*motor)->keys.z_key = 1;
        mouvement(motor,(-1)*move_step,'y');
        (*motor)->keys.lastkey = 'z';
      }

        break;

      case SDLK_q:

      if (((*motor)->keys.z_key + (*motor)->keys.s_key) == 0)
      {

        if ((*motor)->keys.lastkey != 'q')
        (*motor)->player->posX += (-1)*move_step;
        else if (((*motor)->keys.q_key == 0))
        (*motor)->player->posX += (-1)*move_step;

        if (((*motor)->keys.q_key == 0))
          (*motor)->player->movement_id = 1;




        (*motor)->keys.q_key = 1;
        mouvement(motor,(-1)*move_step,'x');
        (*motor)->keys.lastkey = 'q';
      }
        break;

      case SDLK_s:

      if (((*motor)->keys.q_key + (*motor)->keys.d_key) == 0)
      {

      if ((*motor)->keys.lastkey != 's')
      (*motor)->player->posY += move_step;
      else if (((*motor)->keys.s_key == 0))
      (*motor)->player->posY += move_step;

      if (((*motor)->keys.s_key == 0))
        (*motor)->player->movement_id = 1;

        (*motor)->keys.s_key = 1;
        mouvement(motor,move_step,'y');
        (*motor)->keys.lastkey = 's';
      }
        break;

      case SDLK_d:

      if (((*motor)->keys.z_key + (*motor)->keys.s_key) == 0)
      {
        if ((*motor)->keys.lastkey != 'd')
        (*motor)->player->posX += move_step;
        else if (((*motor)->keys.d_key == 0))
        (*motor)->player->posX += move_step;

        if (((*motor)->keys.d_key == 0))
          (*motor)->player->movement_id = 1;

          (*motor)->keys.d_key = 1;
          mouvement(motor,move_step,'x');
          (*motor)->keys.lastkey = 'd';
      }
        break;

      case SDLK_m:
        system("cls");

        int y = (*motor)->player->posY;
        y -= 5;
        char *** mat2 = get_String_Matrice(&(*motor), 0, (*motor)->player->posX, y);
        char command[100];
        sprintf(command, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %0.f %0.f 1", (*motor)->player->posY,(*motor)->player->posX);
        system(command);

        detruire_string_matrice(mat2, 1);
        mat2 = NULL;
        break;

      case SDLK_b:
      /*
        //printf("%i\n",(*motor)->collision_cell_add[(*motor)->nb_collision_cell_add]);
        if ((*motor)->player->speed == 1)
          (*motor)->player->speed = 2;
        else
          (*motor)->player->speed = 1;

        printf("Vitesse : %i\n", (*motor)->player->speed);
        */
      printf("Position : %0.f;%0.f\n", (*motor)->player->posX,(*motor)->player->posY);
        break;

      case SDLK_l:;
      FILE* fout = fopen("player", "wb");
      fwrite((*motor)->player, sizeof(player_t), 1, fout);
      fclose(fout);
      break;

      case SDLK_r:;
      player_t lol;
      FILE* fout2 = fopen("player","rb");
      fread(&lol, sizeof(player_t), 1, fout2);
      fclose(fout2);

      printf("%f\n",lol.posX);
      break;

      case SDLK_a:;

        if ((*motor)->menu->speech_bubble == 1)
        (*motor)->menu->speech_bubble = 0;

        if (1 == 2)
        {
          char *** mat;
          int px = (*motor)->player->posX;

          mat = get_String_Matrice(&(*motor), 0, px, (*motor)->player->posY-4);
            int calque1 = split_string_data(mat[0][0],',',0);
            int calque2 = split_string_data(mat[0][0],',',1);
            int calque3 = split_string_data(mat[0][0],',',2);
            int calque4 = split_string_data(mat[0][0],',',3);
            int calque_collision = split_string_data(mat[0][0],',',4);


            printf("calque1 : %i \ncalque2 : %i \ncalque3 : %i \ncalque4 : %i \ncalque_collision : %i \n Full calque : %s",calque1,calque2,calque3,calque4,calque_collision,mat[0][0]);
            detruire_string_matrice(mat, 1);
        }
        if (1 == 3) {
          char *** mat;
          int px = (*motor)->player->posX;

          mat = get_String_Matrice(&(*motor), 0, px, (*motor)->player->posY-4);
          //int mat_val = split_string_data(mat[i][j],',',0);
          printf("%s\n", mat[0][0]);
          detruire_string_matrice(mat, 1);
        } //Trouver la position
        else if (1 == 1)
        {
        int * arguments = check_interaction(&(*motor));

        printf("A pressed %i;%i;%i \n",arguments[4],arguments[5],arguments[6]);

        for (size_t i = 0; i < 7; i++) {
          printf("argument[%i] = %i\n",i,arguments[i]);
        }

       //Le joueur a appuyé sur A en face d'une entié avec une interaction possible.
       /*
       arg 0 : 3;
       arg 1 : type d'interaction (1 : texte a afficher, 2 : combat a lancer, 3 : teleportation, 4 : objet a ramasser, 5 : utiliser la canne a pêche);
       arg 2 : donnée propre a l'interaction (1 : numéro du texte a afficher, 2 : numero du dresseur à combattre, 3 : numero du texte a afficher avant teleportation, 4 : numero de l'objet a ramasser, 5 : rien);
       arg 3 : numero de la musique a jouer, si pas de changement nécessaire (-1);
       *///(arguments[5])

         switch (arguments[5]) {
           case 1:;
           FILE * file;

           char buffer[10];
           sprintf(buffer,"src/asset/dialogues/data/%i.txt",arguments[6]);
           file = fopen(buffer, "r");

           if (file == NULL) {
             printf("Erreur au chargement du fichier du dialogue\n");
           }

           char string[255] = "";
           fscanf(file,"%s",string);
           while (!feof(file)) {
             char buffer[255] = "";
             fscanf(file,"%s",buffer);
             strncat(string, " ", 2);
             strncat(string, buffer, strlen(buffer));
           }



           (*motor)->menu->speech_bubble = 1;

           strncpy((*motor)->menu->speech_bubble_text,string,ftell(file));
           speech_bubble(&(*motor));
           fclose(file);



           break;

           case 2:
           break;

           case 3:
           break;

           case 4:
           break;

           case 5:
           break;

           default:
           break;
         }


      }
        break;

      case SDLK_t:
        stop_sound();
        play_sound(motor,(*motor)->musique->track_path_list[1],-1,10);
        printf("Check_collision : %i\n",check_collision(motor));
        break;

      case SDLK_c:;
        //(*motor)->collision != (*motor)->collision;
        //printf("%s\n",(*motor)->collision );

        char command2[100];
        sprintf(command2, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\dialog.js %i %f %f %i %s %s %s",(*motor)->map->map_id,(*motor)->player->posX,(*motor)->player->posY-4,(*motor)->admin_console->selected_menu+1,(*motor)->admin_console->arguments[0],(*motor)->admin_console->arguments[1],(*motor)->admin_console->arguments[2]);
        system(command2);

        break;

      case SDLK_y:
      SDL_SetWindowSize((*motor)->windows->window,2000,720);
        break;

      case SDLK_w:
        break;

      case SDLK_UP:
      (*motor)->keys.up_arrow = 1;
      (*motor)->admin_console->menu_change = 1;
        break;

      case SDLK_LEFT:
      (*motor)->keys.left_arrow = 1;
        break;

      case SDLK_DOWN:
      (*motor)->keys.down_arrow = 1;
      (*motor)->admin_console->menu_change = 1;
        break;

      case SDLK_RIGHT:
      (*motor)->keys.right_arrow = 1;
        break;

      case SDLK_KP_0:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"0");
        break;

      case SDLK_KP_1:;
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"1");
        break;

      case SDLK_KP_2:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"2");
        break;

      case SDLK_KP_3:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"3");
        break;

      case SDLK_KP_4:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"4");
        break;

      case SDLK_KP_5:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"5");
        break;

      case SDLK_KP_6:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"6");
        break;

      case SDLK_KP_7:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"7");
        break;

      case SDLK_KP_8:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"8");
        break;

      case SDLK_KP_9:
      strcat((*motor)->admin_console->arguments[(*motor)->admin_console->selection_bar_y],"9");
        break;

      case SDLK_BACKSPACE:;
      int selection_bar_y = (*motor)->admin_console->selection_bar_y;
      int len = strlen((*motor)->admin_console->arguments[selection_bar_y]);
      printf("len %i\n",len );
      memmove(&(*motor)->admin_console->arguments[selection_bar_y][len-1],&(*motor)->admin_console->arguments[selection_bar_y][len],len-(len-1));
        break;


      case SDLK_u:;
      int * arguments = check_tile_agurments(motor);
      free(arguments);

      for (size_t i = 0; i < 5; i++) {
        printf("Interaction[%i] : %i\n",i,arguments[i]);
      }

        break;

      case SDLK_SPACE:
        if (2)
        {
          int posX = (*motor)->player->posX;

          int posY = (*motor)->player->posY;
          posY -= 5;

          char ** * matrice = get_String_Matrice(&(*motor), 1, posX, posY);
          char * matrix_cell_id;
          if ((*motor)->keys.z_key == 1)
            matrix_cell_id = matrice[0][1];

          if ((*motor)->keys.s_key == 1)
            matrix_cell_id = matrice[2][1];

          if ((*motor)->keys.q_key == 1)
            matrix_cell_id = matrice[1][0];

          if ((*motor)->keys.d_key == 1)
            matrix_cell_id = matrice[1][2];

          char command[100];
          sprintf(command, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %s 0 1", matrix_cell_id);
          system(command);

          printf("-------------\n");
          for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
              printf("%i;%i->%s\t", i, j, matrice[i][j]);
            }
            printf("\n");
          }
          printf("-------------\n");
          detruire_string_matrice(matrice, 3);
        }
        break;

      default:
        //return -1;
        break;
      }


     if ((*motor)->player->movement_id < 8)
       (*motor)->player->movement_id++;
     else
       (*motor)->player->movement_id = 1;


    }
    else if ((*motor)->event.type == SDL_KEYUP)
    {
      switch ((*motor)->event.key.keysym.sym)
      {

      case SDLK_z:

      (*motor)->keys.z_key = 0;
      (*motor)->keys.lastkey = 'z';

        break;

      case SDLK_q:
      (*motor)->keys.q_key = 0;
      (*motor)->keys.lastkey = 'q';

        break;

      case SDLK_s:
      (*motor)->keys.s_key = 0;
      (*motor)->keys.lastkey = 's';

        break;

      case SDLK_d:
      (*motor)->keys.d_key = 0;
      (*motor)->keys.lastkey = 'd';

        break;

      case SDLK_UP:
      (*motor)->keys.up_arrow = 0;
        break;

      case SDLK_LEFT:
      (*motor)->keys.left_arrow = 0;
        break;

      case SDLK_DOWN:
      (*motor)->keys.down_arrow = 0;
        break;

      case SDLK_RIGHT:
      (*motor)->keys.right_arrow = 0;
        break;

      default:
        //return -1;
        break;
      }
    }
    else if ((*motor)->event.type == SDL_QUIT)
    {
      (*motor)->quit = 1;
    }

  }

}