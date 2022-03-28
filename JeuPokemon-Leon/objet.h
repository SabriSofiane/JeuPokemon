void init_obj() //jsp lol
{
    FILE * file_obj;
}

void obj_soin(choix)
{

}

void obj_pkb(choix)
{
  
}

void selec_obj(int choix)
{
  if (strcmp(item_player[choix].type, "soin"))
    obj_soin(choix);
  else if (strcmp(item_player[choix].type, "pokeball"))
    obj_pkb(choix);
  else
    printf("Erreur\n");
}
