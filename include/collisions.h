
int check_collision(motor_t ** motor);

/*Fonction de detection d'une interaction avec un élément du jeu (overworld) à la suite d'un appuis sur une touche d'action (a,x,y,b)*/
int * check_interaction(motor_t ** motor);

int * check_tile_agurments(motor_t ** motor);

void collision(motor_t ** motor);
