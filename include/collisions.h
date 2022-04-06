
int check_collision(global_structure_t ** global_structure);

/*Fonction de detection d'une interaction avec un élément du jeu (overworld) à la suite d'un appuis sur une touche d'action (a,x,y,b)*/
int * check_interaction(global_structure_t ** global_structure);

int * check_tile_agurments(global_structure_t ** global_structure);

void collision(global_structure_t ** global_structure);
