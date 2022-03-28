#include "../include/motor.h"
#include "../include/admin.h"
#include "../include/text.h"

int init_admin(motor_t ** motor)
{
  (*motor)->admin_console->key_delay = SDL_GetTicks();
}

void selection_bar(motor_t ** motor,int nb_menu,int nb_option)
{
if ((*motor)->keys.right_arrow == 1)
(*motor)->admin_console->selection_bar_x++;

if ((*motor)->keys.left_arrow == 1)
(*motor)->admin_console->selection_bar_x--;

if ((*motor)->admin_console->selection_bar_x < 0)
(*motor)->admin_console->selection_bar_x = nb_menu;

if ((*motor)->admin_console->selection_bar_x > nb_menu)
(*motor)->admin_console->selection_bar_x = 0;


if ((*motor)->keys.up_arrow == 1)
{
  (*motor)->admin_console->selection_bar_y--;
  //strncpy((*motor)->admin_console->keypad," ",1);
}

if ((*motor)->keys.down_arrow == 1)
{
  (*motor)->admin_console->selection_bar_y++;
  //strncpy((*motor)->admin_console->keypad," ",1);
}

if ((*motor)->admin_console->selection_bar_y < 0)
(*motor)->admin_console->selection_bar_y = nb_option;

if ((*motor)->admin_console->selection_bar_y > nb_option)
(*motor)->admin_console->selection_bar_y = 0;
}

void display_console(motor_t ** motor)
{
  int selection_bar_x = 0;
  int selection_bar_y = 0;
  char * menu[10];
  menu[0] = "Collision avec un obstacle";
  menu[1] = "Rencontre pkm";
  menu[2] = "Interaction npc/obj";
  menu[3] = "Set Jump spot";
  menu[4] = "Declenchement musique";
  menu[5] = "Changement map/tp";
  menu[6] = "Trigger animation";


  int menu_selection[5];
  menu_selection[0] = 0;
  /*
  for (size_t i = 0; i < 5; i++) {
    menu_selection[i] = 0;
  }
  */

  selection_bar_x = (*motor)->admin_console->selection_bar_x;
  selection_bar_y = (*motor)->admin_console->selection_bar_y;


  if (selection_bar_y == 0)
  (*motor)->admin_console->selected_menu = selection_bar_x;
  //else if (selection_bar_y < 10)
  /*
    if ((*motor)->admin_console->menu_change == 0)
    {
      (*motor)->admin_console->arguments[selection_bar_y] = atoi((*motor)->admin_console->keypad);
    } else if ((*motor)->admin_console->menu_change == 1)
    {
      strcpy((*motor)->admin_console->keypad,"null");
      (*motor)->admin_console->menu_change = 0;
    }
    */


  selection_bar(&(*motor),10,5);




  char str[100];
  sprintf(str," z : %i _ q : %i _ s : %i _ d : %i",(*motor)->keys.z_key,(*motor)->keys.q_key,(*motor)->keys.s_key,(*motor)->keys.d_key);

  text_draw(motor,"--",1400,100+((*motor)->admin_console->selection_bar_y*30));
  text_draw(motor,menu[(*motor)->admin_console->selected_menu],1450,100);

  for (size_t i = 1; i < 11; i++) {
    char * value;
    if (strcmp((*motor)->admin_console->keypad,"null") != 0)
    //sprintf(value,"%i",(*motor)->admin_console->arguments[i]);
    text_draw(motor,(*motor)->admin_console->arguments[i],1450,100+(i*30) );
  }

  text_draw(motor,str,800,500);

  sprintf(str,"%2.f;%2.f",(*motor)->player->posX,(*motor)->player->posY-4);
  text_draw(motor,str,1000,550);
/*
  sprintf(str,"%i;%i",floorf((*motor)->player->posX) == (*motor)->player->posX,floorf((*motor)->player->posY) == (*motor)->player->posY);
  text_draw(motor,str,1000,570);

  sprintf(str,"%i",(*motor)->player->movement_id);
  text_draw(motor,str,1000,590);
  */
  text_draw(motor,"lol \t mdr",1000,590);
}
