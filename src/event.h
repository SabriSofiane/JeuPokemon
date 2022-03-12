/*
Le but de ce fichier est de gérer tous les événements, merci d'adopter la même
syntaxe lors d'ajout d'événement, par défaut les événements de déplacement de
la souris sont désactivées.
*/


int event_handle(motor_t ** motor)
{
  int retour=3;

  SDL_WaitEvent(&(*motor)->event);

  if ((*motor)->event.type == SDL_MOUSEMOTION)
  return -1;

  char * key_pressed;
  key_pressed = (*motor)->last_key;
  if ((*motor)->event.type == SDL_KEYDOWN)
  {
    switch ((*motor)->event.key.keysym.sym)
    {
      case SDLK_z:
      key_pressed = "z";
      break;

      case SDLK_q:
      key_pressed = "q";
      break;

      case SDLK_s:
      key_pressed = "s";

      break;

      case SDLK_d:
      key_pressed = "d";
      break;



      case SDLK_RETURN:

      printf("lol\n");


      switch ((*motor)->menu->el_battle_menu_atk_select) {
        case 0:
        (*motor)->menu->choixCombat = 0;
        player_attack(player,&wild_pkm,(*motor)->menu->choixCombat);
        retour = combat(player,&wild_pkm);
        break;
        case 1:
        (*motor)->menu->choixCombat = 1;
        player_attack(player,&wild_pkm,(*motor)->menu->choixCombat);
        break;
        case 2:
        (*motor)->menu->choixCombat = 2;
        player_attack(player,&wild_pkm,(*motor)->menu->choixCombat);
        break;
        case 3:
        (*motor)->menu->choixCombat = 3;
        player_attack(player,&wild_pkm,(*motor)->menu->choixCombat);
        break;

      }

      switch ((*motor)->menu->el_battle_menu_select) {
        case 0:
        (*motor)->menu->menu_battle = 0;
        (*motor)->menu->menu_battle_attaque= 1;

        break;
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;

      }

      if(retour == 1){
        (*motor)->menu->speech_bubble = 1;
      }

      break;

      case SDLK_m:
      key_pressed = "m";


      break;

      case SDLK_b:
      key_pressed = "b";
      break;

      case SDLK_a:
      key_pressed = "a";
      break;

      case SDLK_UP:

      if ((*motor)->menu->el_menu_select > 0)
      (*motor)->menu->el_menu_select--;
      else
      (*motor)->menu->el_menu_select = 5;


      if ((*motor)->menu->el_battle_menu_select > 0)
      (*motor)->menu->el_battle_menu_select--;
      else
      (*motor)->menu->el_battle_menu_select =3;

      printf("%d",(*motor)->menu->el_battle_menu_select);


      if ((*motor)->menu->el_battle_menu_atk_select > 0)
      (*motor)->menu->el_battle_menu_atk_select--;
      else
      (*motor)->menu->el_battle_menu_atk_select =3;

      printf("%d",(*motor)->menu->el_battle_menu_atk_select);








      break;

      case SDLK_DOWN:

      printf("%d",(*motor)->menu->el_battle_menu_select);
      if ((*motor)->menu->el_menu_select < 5)
      (*motor)->menu->el_menu_select++;
      else
      (*motor)->menu->el_menu_select = 0;


      if ((*motor)->menu->el_battle_menu_select < 3)
      (*motor)->menu->el_battle_menu_select++;
      else
      (*motor)->menu->el_battle_menu_select =0;
      printf("%d",(*motor)->menu->el_battle_menu_select);


      if ((*motor)->menu->el_battle_menu_atk_select < 3)
      (*motor)->menu->el_battle_menu_atk_select++;
      else
      (*motor)->menu->el_battle_menu_atk_select =0;
      printf("%d",(*motor)->menu->el_battle_menu_atk_select);

      break;

      default:
      break;
    }
    strcpy((*motor)->last_key,key_pressed);
  }
  else if ((*motor)->event.type == SDL_QUIT)
  {
    (*motor)->quit = 1;
  }

  return 1;
}
