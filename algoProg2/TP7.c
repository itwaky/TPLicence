#include <math.h>

//-----------------------1.echange d'adresse-----------------


//-----a


// la fonction echange1 effectera la valeur de p1 a p2 et inversement sauf que cette fonction 
// modifie la valeur par copie mais ne retourne rien donc elle ne sert a rien



//-----b

// la fonction echange2 prend 2 pointeur en parametre et echange la valeur pointer par les 2 pointeur 
// contrainement a echange1 celle ci a bien un interé


//-----c

// la fonction echange3 prend 2 pointeur en parrametre elle echange les adresse des deux pointeur 
// mais ve que cela est fait par copie cela n'a aucun intere


//----d

// la fonction echange4 prend 2 pointeur de pointeur en parametre et elle echange la valeur de l'adresse pointeur par le pointeir
// donc contrairement en c cela change vrm les valeur pointer




// c'est bien ce que j'attendez





//-------------------------------2.Ponts Pointés--------------------------------------

#include <stdio.h>

typedef struct {int x; int y;} point;


// fonction : affichage d'un point
// arguments : un point
// retour :  rien
// pre-conditions : 
// post-conditions : 

void afficher_point (point p){
  printf("(%d, %d)",p.x,p.y);
  return;
}

// fonction : affichage d'un tableau de points
// arguments : un tableau de points et sa taille
// retour :  rien
// pre-conditions :  le second parametre est la taille du premier
// post-conditions : 

void afficher_point_tab (int n, point t[n]){
  int i; 
  for (i = 0; i < n; i++) {
    afficher_point(t[i]);
    printf(" ");
  }
  printf("\n");
  return;
}


void affiche_pointeur_point(point* p){
    afficher_point(*p);
}

void afficher_pointeur_point_tab(int taille, point* tabPointeur[]){
    for(int i = 0; i<taille; i++){
        affiche_pointeur_point(tabPointeur[i]);
        printf(" ");
    }
    printf("\n");
}


void init_pointeur_tab(int taille, point* tabPointeur[],point tab[]){
    for(int i = 0; i<taille; i++){
        tabPointeur[i] = &tab[i];
    }
}   

float norme(point* p){
    return sqrt((p->x)*(p->x) + (p->y)*(p->y));// faut faire -lm pour utiliser la librairie math.h
}



void tri_selection(point* tab[], int size){
    for(int i = 0; i < size; ++i){
        int plusPetit = i;
        for(int j = i; j < size; ++j){
            if(norme(tab[j]) < norme(tab[plusPetit])){
                plusPetit = j;
            }
        }
        point* temp = tab[i];
        tab[i] = tab[plusPetit];
        tab[plusPetit] = temp;
    }
}



int main (){
  point tp [36] = {
    {3,1}, {3,5}, {4,1}, {5,3}, {6,2}, {3,2},
    {5,2}, {3,4}, {3,3}, {6,1}, {4,4}, {2,2},
    {6,6}, {5,5}, {3,6}, {2,6}, {1,2}, {2,3},
    {6,4}, {5,6}, {4,3}, {4,6}, {2,4}, {1,1},
    {6,5}, {4,5}, {2,1}, {5,4}, {2,5}, {5,1},
    {1,3}, {1,4}, {1,5}, {6,3}, {4,2}, {1,6}
  };
  afficher_point_tab (36, tp);
  printf("\n");

  point* pointeur[36];
  init_pointeur_tab(36, pointeur, tp);

  afficher_pointeur_point_tab(36,pointeur);
  printf("\n");
  tri_selection(pointeur, 36);
  afficher_pointeur_point_tab(36,pointeur);



  return 0;
}

