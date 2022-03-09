#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/string_matrice.h"

char *** creer_string_matrice(int size)
{
  char *** data = (char *** )malloc(size * sizeof(char ** )) ;

  //Allocate memroy for each row
  for(int i = 0 ; i < size ; i++ )
  {
      data[i] = (char ** ) malloc(size * sizeof(char * )) ;
      for ( int j = 0 ; j < size ; j++ )
      {
          data[i][j] = malloc(30 * sizeof(char));// (char *)malloc(1 * sizeof(char));
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

char *** get_String_Matrice(motor_t ** motor,char * filename, int nb_bordure,int x_center,int y_center,char * nom_function)
{
  int r = (*motor)->tiles_number;
  int c = (*motor)->tiles_number;

  char *** data = (*motor)->matrice_file;
  char *** data2 = creer_string_matrice((2*nb_bordure)+1);


  for (int i = -1 * nb_bordure, countY = -1; i < nb_bordure + 1; i++) {
    countY++;
    for (int j = -1 * nb_bordure, countX = 0; j < nb_bordure + 1; j++) {
      if ( ((y_center + i) < 0) || ((x_center + j) < 0) )
      strncpy(data2[countY][countX],"-1",2);
      else if ( ((y_center + i) >= r) || ((x_center + j) >= r) )
      strncpy(data2[countY][countX],"-1",2);
      else
      strncpy(data2[countY][countX],data[(y_center + i)][(x_center + j)],30);//data[(y_center + i)][(x_center + j)];//printf("%s\t",data[(playerY + i)][(playerX + j)]);
      countX++;
    }
  }
  return data2;
}

int split_string_data(char str[80], const char s2,int index)
{
  int retour = -1;
  const char s[2] = ",";
  char * token;
  char str_buffer[80];
  strcpy(str_buffer,str);
  // get the first token
  token = strtok(str_buffer, s);

  if (index == 0)
  return atoi(token);
  //walk through other tokens
  while(index != 0) {
    token = strtok(NULL, s);
    index--;
 }
 //if (token != '')
 retour = atoi(token);

 return retour;
}
