void display_map(motor_t ** motor,SDL_Texture * texture_map1){
  int nb_bordure = 10;

  SDL_Renderer ** renderer;
  renderer = &(*motor)->renderer;
  char *** mat = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map2.dat", nb_bordure, (*motor)->player->posX,(*motor)->player->posY);
  int loop = (2 * nb_bordure) + 1;


  for (int i = 0; i < loop; i++) {
    for (int j = 0; j < loop; j++) {
      int image_width = 32;
      int image_height = 32;

      SDL_Rect SrcR;
      SDL_Rect DestR;

      int tiles_size = (int)(32*(floor((*motor)->windows->size_coef)));
      //printf("tiles_size %f\n",(floor((*motor)->windows->size_coef)) );
      //printf("%i| %i;%i\t",mat[i][j] , ( mat[i][j]-(mat[i][j]/64) )/32 ,mat[i][j]/32);
      int y = atoi(mat[i][j])/tiles_size;
      int x = atoi(mat[i][j])-(y*tiles_size);
      y++;

      SrcR.x = 32*x;
      SrcR.y = 32*y;

      //if (strstr(mat[j][i],",") != NULL)
      //rect_data[j][i] = split_string_data(mat[j][i],',',1);

      SrcR.w = 32;
      SrcR.h = 32;

      DestR.x = 0 + (tiles_size * j);
      DestR.y = 0 + (tiles_size * i);
      DestR.w = tiles_size;
      DestR.h = tiles_size;

      SDL_QueryTexture(texture_map1, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy(*renderer, texture_map1, &SrcR, &DestR);
    }
  }

  free(mat);
  free(*renderer);
}
