void mark_cell(motor_t ** motor)
{
  /*
  system("start opera");

  int y = (*motor)->player->posY;
  y -= 3;
  char *** matrix = get_String_Matrice("C:/Users/Elias/Desktop/JEU_POKEMON/src/file_map2.dat", 0, (*motor)->player->posX,y);
  */
  
  //printf("%s\n",matrix[0][0]);
  //(*motor)->nb_collision_cell_add++;
  //(*motor)->collision_cell_add[(*motor)->nb_collision_cell_add] = atoi(matrix[0][0]);

  /*
  FILE *fp;
  char filePath[100];
  fp = fopen("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/config_file/collision_file.txt", "a");

  if (fp == NULL)
  {
    printf("Impossible d'ouvrir le fichier d'edition des collisions\n");
    exit(EXIT_FAILURE);
  }

*/


/*
  fseek(fp, -100, SEEK_END);//next to last char, last is EOF

  char str[120];
  if( fgets (str, 120, fp)!=NULL ) {
        puts(str);
        if (strchr(str, ch))
  }
*/
/*
  char buffer[10];
  sprintf(buffer,"%s;",matrix[0][0]);
  fputs(buffer, fp);


  fclose(fp);

  free(matrix);
  matrix = NULL;
  */
/*
  const SDL_MessageBoxButtonData buttons[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT      0, 0, "no" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "cancel" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
        { // .colors (.r, .g, .b)
            // [SDL_MESSAGEBOX_COLOR_BACKGROUND]
            { 255,   0,   0 },
            // [SDL_MESSAGEBOX_COLOR_TEXT]
            {   0, 255,   0 },
            // [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER]
            { 255, 255,   0 },
            // [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND]
            {   0,   0, 255 },
            // [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED]
            { 255,   0, 255 }
        }
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, // .flags
        NULL, // .window
        "example message box", // .title
        "select a button", // .message
        SDL_arraysize(buttons), // .numbuttons
        buttons, // .buttons
        &colorScheme // .colorScheme
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
    }
    if (buttonid == -1) {
        SDL_Log("no selection");
    } else {
        SDL_Log("selection was %s", buttons[buttonid].text);
    }
*/
}
