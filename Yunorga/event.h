void init_event(motor_t ** motor)
{
  /*
  for (size_t i = 0; i < 10; i++) {
    &(*motor)->key_log[i]= "null";
  }
  */
}

void mouvement(motor_t ** motor,int move_add,char axis)
{
  if (axis == 'x')
  {
    (*motor)->player->posX+=move_add;
    if (check_collision(motor) == 1)
    {
      printf("Collision X \n");
      (*motor)->player->posX+=move_add;
    }
    else if ((*motor)->player->speed == 2)
    (*motor)->player->posX+=move_add;
    if (check_collision(motor) == 1)
    (*motor)->player->posX+=move_add;

  } else if (axis == 'y')
  {

    (*motor)->player->posY+=move_add;
    if (check_collision(motor) == 1)
    {
      printf("Collision X \n");
    (*motor)->player->posY+=move_add;
    }
    else if ((*motor)->player->speed == 2)
    (*motor)->player->posY+=move_add;
    if (check_collision(motor) == 1)
    (*motor)->player->posY+=move_add;
  }
  (*motor)->player->player_cooldown = 20;
}

int event_handle(motor_t ** motor)
{
    SDL_Event * event;
    event = &(*motor)->event;

    //printf("Event \n", );

    SDL_WaitEvent(event);

    if (event->type == SDL_MOUSEMOTION)
    return -1;

      char * move_key;
      move_key = (*motor)->last_key;

      if (event->type == SDL_KEYDOWN)
      {
        system("cls");

        char * source = "ZQSD BMA Backspace";
        //printf("KEY %s\n",SDL_GetKeyName(event->key.keysym.sym) );
        if (1)//(strstr( source, SDL_GetKeyName(event->key.keysym.sym) ) != NULL)
        {

        switch (event->key.keysym.sym) {
          case SDLK_z:
          move_key = "z";
          //mouvement(motor,-1,'y');

          if ((strcmp((*motor)->last_key,"z")!= 0))
          (*motor)->player->movement_id = 1;

          (*motor)->player->posY-=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posY+=1;
          else if ((*motor)->player->speed == 2)
          (*motor)->player->posY-=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posY+=1;

          (*motor)->player->player_cooldown = 20;

          break;

          case SDLK_q:
          move_key = "q";
          //mouvement(motor,-1,'x');

          if ((strcmp((*motor)->last_key,"q")!= 0))
          (*motor)->player->movement_id = 1;

          (*motor)->player->posX-=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posX+=1;
          else if ((*motor)->player->speed == 2)
          (*motor)->player->posX-=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posX+=1;
          (*motor)->player->player_cooldown = 20;

          break;

          case SDLK_s:
          move_key = "s";
          //mouvement(motor,1,'y');

          if ((strcmp((*motor)->last_key,"s")!= 0))
          (*motor)->player->movement_id = 1;

          (*motor)->player->posY+=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posY-=1;
          else if ((*motor)->player->speed == 2)
          (*motor)->player->posY+=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posY-=1;

          (*motor)->player->player_cooldown = 20;

          break;

          case SDLK_d:
          move_key = "d";
          //mouvement(motor,1,'x');

          if ((strcmp((*motor)->last_key,"d")!= 0))
          (*motor)->player->movement_id = 1;


          (*motor)->player->posX+=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posX-=1;
          else if ((*motor)->player->speed == 2)
          (*motor)->player->posX+=1;
          if (check_collision(motor) == 1)
          (*motor)->player->posX-=1;

          (*motor)->player->player_cooldown = 20;


          break;

          case SDLK_m:
          system("cls");//mark_cell(&(*motor));

          int y = (*motor)->player->posY;
          y -= 5;
          char *** mat2 = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map2.dat", 0, (*motor)->player->posX,y);
          char command[100];
          sprintf(command,"node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %s 1",mat2[0][0]);
          system(command);
          free(mat2);
          mat2 = NULL;

          break;

          case SDLK_b:
          //printf("%i\n",(*motor)->collision_cell_add[(*motor)->nb_collision_cell_add]);
          if ((*motor)->player->speed == 1)
          (*motor)->player->speed = 2;
          else
          (*motor)->player->speed = 1;
          printf("Vitesse : %i\n",(*motor)->player->speed );
          break;

          case SDLK_a:
          printf("A pressed %i \n",check_interaction(motor));
          if (check_interaction(motor) == 2)
          {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                         "interaction detecté",
                         "",
                         NULL);
          }
          break;

          case SDLK_BACKSPACE:
          if (1)//(check_interaction(motor) == 1)
          {
            int pos_x = (*motor)->player->posX;

            int pos_y = (*motor)->player->posY;
            pos_y -= 5;

            char *** matrice = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map2.dat", 1, pos_x,pos_y);
            char * matrix_cell_id;
            if ((strcmp((*motor)->last_key,"z")== 0))
            matrix_cell_id = matrice[0][1];

            if ((strcmp((*motor)->last_key,"s")== 0))
            matrix_cell_id = matrice[2][1];

            if ((strcmp((*motor)->last_key,"q")== 0))
            matrix_cell_id = matrice[1][0];

            if ((strcmp((*motor)->last_key,"d")== 0))
            matrix_cell_id = matrice[1][2];



            char command[100];
            sprintf(command,"node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %s 0 1",matrix_cell_id);
            system(command);

            printf("-------------\n");
            for (size_t i = 0; i < 3; i++) {
              for (size_t j = 0; j < 3; j++) {
                printf("%i;%i -> %s\t",i,j,matrice[i][j]);
              }
              printf("\n");
            }
            printf("-------------\n");
          }
          break;
          default:
          break;
        }

          strcpy((*motor)->last_key,move_key);

          printf("%i;%i\nlast key : %s\n",(*motor)->player->posX,(*motor)->player->posY,(*motor)->last_key);
          int sprite_id = (*motor)->player->movement_id;
          sprite_id--;



          printf("sprite %i\n", sprite_id);

          if ((*motor)->player->movement_id < 4)
          (*motor)->player->movement_id++;
          else
          (*motor)->player->movement_id = 1;

        }

      }else if (event->type == SDL_QUIT)
      {
        (*motor)->quit = 1;
      }
    return 1;
}
