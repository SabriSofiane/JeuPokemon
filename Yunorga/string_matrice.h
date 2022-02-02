char *** creer_string_matrice(int size)
{
  char *** data = (char *** )malloc(size * sizeof(char ** )) ;

  //Allocate memroy for each row
  for(int i = 0 ; i < size ; i++ )
  {
      data[i] = (char ** ) malloc(size * sizeof(char * )) ;
      for ( int j = 0 ; j < size ; j++ )
      {
          data[i][j] = malloc(2 * sizeof(char));// (char *)malloc(1 * sizeof(char));
          strcpy(data[i][j],"-1");
      }
   }
   return data;
}

void detruire_string_matrice(char *** matrice,int size)
{
  for(int i = 0 ; i < size ; i++ )
  {
      for ( int j = 0 ; j < size ; j++ )
      {
          free(matrice[i][j]);
      }
      free(matrice[i]);
   }
   free(matrice);
}

char *** get_String_Matrice(char * filename, int nb_bordure,int x_center,int y_center)
{
  int r = 64, c = 64;


  FILE * pf2;

  pf2 = fopen(filename, "r");

  if (pf2 == NULL) {
    printf("\n Erreur3");
    return 0;
  }

  char *** data = creer_string_matrice(r);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      char str[80];
      fscanf(pf2, "%s", str);
      strcpy(data[i][j],str);
    }
  }

  fclose(pf2);

  char *** data2 = creer_string_matrice((2*nb_bordure)+1);

  for (int i = -1 * nb_bordure, countY = -1; i < nb_bordure + 1; i++) {
    countY++;
    for (int j = -1 * nb_bordure, countX = 0; j < nb_bordure + 1; j++) {
      data2[countY][countX] = data[(y_center + i)][(x_center + j)];//printf("%s\t",data[(playerY + i)][(playerX + j)]);
      countX++;
    }
  }

  detruire_string_matrice(data,32);

  return data2;
}

int split_string_data(char str[80], const char s2,int index)
{

  const char s[2] = ",";
  char *token;

  // get the first token
  token = strtok(str, s);

  if (index == 0)
  return atoi(token);

  //walk through other tokens
  while(index != 0) {
    //printf( " %s\n", token );
    token = strtok(NULL, s);
    index--;
 }
 return atoi(token);
}
