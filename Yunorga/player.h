int init_player(motor_t ** motor)
{
  (*motor)->player = malloc(sizeof(player_t));
  (*motor)->player->movement_id = 1;
  (*motor)->player->speed = 1;
  (*motor)->player->player_cooldown = 0;
  return 0;
}

void display_player(motor_t ** motor)
{
  /*
  if ((*motor)->player->player_cooldown > 0)
  (*motor)->player->player_cooldown--;
  else if ((*motor)->player->player_cooldown == 0)
  {
    (*motor)->player->movement_id = 1;
    (*motor)->player->player_cooldown = -1;
  }
  */

  SDL_Renderer ** renderer;
  renderer = &(*motor)->renderer;

  //SDL_Surface * player_sprite_sheet;
/*
  if (*(&(*motor)->player->speed) == 1)
  player_sprite_sheet = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/dawn/dawn_walk.png");
  else if (*(&(*motor)->player->speed) == 2)
  player_sprite_sheet = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/dawn/dawn_run.png");

  SDL_Texture * player_texture = SDL_CreateTextureFromSurface(*renderer, player_sprite_sheet);
  SDL_FreeSurface(player_sprite_sheet);
*/
  SDL_Rect * player_rect;
  player_rect = &(*motor)->player->player_rect;

  player_rect->w = *(&(*motor)->player->width);
  player_rect->h = *(&(*motor)->player->height);

  player_rect->x = (*(&(*motor)->windows->width) - player_rect->w)/2;
  player_rect->x += 32;

  player_rect->y = (*(&(*motor)->windows->height) - player_rect->h)/2;
  player_rect->y += 32;

  SDL_Rect SrcR;

  SrcR.x = ((*motor)->player->movement_id);
  SrcR.x--;
  SrcR.x *= 50;

  if (strcmp((*motor)->last_key,"z") == 0)
  SrcR.y = 64*0;
  else if (strcmp((*motor)->last_key,"q") == 0)
  SrcR.y = 64*1;
  else if (strcmp((*motor)->last_key,"s") == 0)
  SrcR.y = 64*2;
  else if (strcmp((*motor)->last_key,"d") == 0)
  SrcR.y = 64*3;

  SrcR.w = 50;
  SrcR.h = 64;

  /*
  char path[100];
  if (*(&(*motor)->player->speed) == 1)
  sprintf(path, "C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/dawn/%c%d.png",*(*motor)->last_key,(*motor)->player->movement_id);
  else if (*(&(*motor)->player->speed) == 2)
  sprintf(path, "C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/dawn/%cs%d.png",*(*motor)->last_key,(*motor)->player->movement_id);
*/

  int image_width,image_height;

  SDL_QueryTexture((*motor)->textures->player_walk, NULL, NULL,  &image_width , &image_height);

  SDL_RenderCopy(*renderer, (*motor)->textures->player_walk, &SrcR, player_rect);
  //SDL_DestroyTexture(player_texture);

  /*
    SDL_Surface * image2 = IMG_Load(path);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(*renderer, image2);

    int image_width = 50;
    int image_height = 64;
    SDL_QueryTexture(texture2, NULL, NULL, &image_width , &image_height);
    SDL_RenderCopy(*renderer, texture2, NULL, player_rect);
  */

  //SDL_RenderPresent(*renderer);
  //SDL_FreeSurface(image2);


  free(renderer);
  renderer = NULL;
  free(player_rect);
  player_rect = NULL;

}
