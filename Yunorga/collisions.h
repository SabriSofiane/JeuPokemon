int check_collision(motor_t ** motor)
{
  int y = (*motor)->player->posY;
  y -= 5;

  char *** matrice = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map2.dat", 1, (*motor)->player->posX,y);
  int collision = split_string_data(matrice[1][1],',',1);

  free(matrice);
  matrice = NULL;

  return collision;
}

int check_interaction(motor_t ** motor)
{

  int pos_x = (*motor)->player->posX;

  int pos_y = (*motor)->player->posY;
  pos_y -= 5;

  if ((strcmp((*motor)->last_key,"z")== 0))
  pos_y--;

  if ((strcmp((*motor)->last_key,"s")== 0))
  pos_y++;

  if ((strcmp((*motor)->last_key,"q")== 0))
  pos_x--;

  if ((strcmp((*motor)->last_key,"d")== 0))
  pos_x++;


  char *** matrice = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map2.dat", 1, pos_x,pos_y);
  int interaction = split_string_data(matrice[1][1],',',2);


  printf("-------------\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("%i;%i -> %s\t",i,j,matrice[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");


  free(matrice);
  matrice = NULL;

  return interaction;
}


void collision(motor_t ** motor)
{
  int collision = check_collision(motor);

  if (collision == 1)//(split_string_data(mat2[1][0],',',1) == 1)
  {
    if (strcmp((*motor)->last_key,"z") == 0)
    (*motor)->player->posY++;
    else if (strcmp((*motor)->last_key,"q") == 0)
    (*motor)->player->posX++;
    else if (strcmp((*motor)->last_key,"s") == 0)
    (*motor)->player->posY--;
    else if (strcmp((*motor)->last_key,"d") == 0)
    (*motor)->player->posX--;
  }

  /*
  printf("-------------\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("%i;%i -> %s\t",i,j,mat2[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
*/ //Pour debug de mat2

  /*
  les cases a surveiller sont :

  haut : mat2[0][1]
  gauche : mat2[1][0]
  bas : mat2[2][1]
  droite : mat2[1][2]
  */

}
