#include <stdlib.h>
#include <stdio.h>

//---------------------------------Pointueur et allocation dynamique---------------------

//------intro


//ex Bonus

//model1

void translate(int* x, int* y, int tx, int ty){
    *x += tx;
    *y += ty;
}

// int main(){
//     int x = 2;
//     int y = 3;
//     translate(&x, &y, 2,5);
//     printf("x = %d, y = %d \n", x,y);
// }

//model2

typedef struct
{
    int x;
    int y;
}Point2D;

// Point2D translate(Point2D a, int tx , int ty){ // ne plus faire
//     a.x += tx;
//     a.y += ty;
//     return a;
// }

void translate(Point2D* p , int tx, int ty){
    p->x+=tx;
    p->y+=ty;
}


int main(){
    Point2D a = {3,4};
    translate(&a, 3,5);
    printf("point = (%d,%d) \n", a.x, a.y);
}

//1

// 5
// deux fois l'adresse de x
// deux fois l'adresse de x mais par y
// affiche valeur pointer par y qui est x
// affiche 12 car on a ajouter 7 a la valeur pointer pas y


//2


// *px : 5
// *py : 7
// *px : 7
// *py : 5


//3

// 1 2 3
// 124 5 10


//4

// 1 12 3
// 3

//5

// affiche de mercredi a vendredi

//6

// *p = 5, *q = 6



//7


void incremente(int* p){
    *p++;
}


//8

void echange(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//9

void carre(int* x){
    *x = *x * *x;
}

//10

void disque(float rayon, float* diam, float* peri, float* surf){
    *diam = 2.f * rayon;
    *peri = 3.14f * *diam;
    *surf = 3.14f * rayon * rayon;
}


//11

void somme_diff(int x, int y, int* somme, int* diff){
    *somme = x + y;
    *diff = x - y;
}


//12

void afficherTab(int* tab, int size){
    for(int i = 0; i<size; i++){
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

int* cree_tab_carre(int n){
    int* tab =  (int*) malloc(sizeof(int)*n);
    if(tab == NULL) exit(-1);
    int cpt = 1;
    for(int i = 0; i <n; i++){
        *(tab+i) = cpt*cpt;
        cpt++;
        // ou tab[i] = (i+1) * (i+1);
    }
    return tab;
}


// int main(){
//     int* ptr = cree_tab_carre(5);
//     afficherTab(ptr, 5);
//     free(ptr);
// }


//13


int* copieTab(int* tab, int n){// dans le standard memcpy
    int* tab2 = (int*) malloc(sizeof(int) * n);
    if (tab2 == NULL) exit(-1);
    for(int i = 0; i < n; i++){
        *(tab2 + i) = *(tab + i);
    }
    return tab2;
}


//14


int* concat(int* tab1, int* tab2, int n1, int n2){
    int cpt = 0;
    int* tabConcat = (int*) malloc(sizeof(int) * (n1+n2));
    if(tabConcat == NULL) exit(-1);
    for(int i = 0; i < n1; i++){
        *(tabConcat + cpt) = *(tab1 + i);
        cpt++;
    }
    for(int i = 0; i<n2; i++){
        *(tabConcat + cpt) = *(tab2 + i);
        cpt++;
    }
    return tabConcat;
}


// int main(){
//     int* tab1 = cree_tab_carre(5);
//     int* tab2 = cree_tab_carre(10);
// 
//     int* tabConcat = concat(tab1, tab2, 5, 10);
//     afficherTab(tabConcat, 15);
//     free(tab1);
//     free(tab2);
//     free(tabConcat);
// }

//15

//a 14

//b 28

//c l'adresse du deuxième élément de t

//d l'adresse du premier élément de t

//e 14

//f l'adesse du 5ieme élément de t d'écrémenter de 12

//g une adresse sans aucun sens

//h l'adresse du 3ieme éléments de t



//16

int* sous_tab(int* tab, int taille, int i1, int i2){
    int* sousTab = (int*) malloc(sizeof(int) * (i2 - i1));
    if(sousTab == NULL) exit(-1);
    for(int i = 0; i <= (i2 - i1); i++){
        *(sousTab + i) = *(tab + (i1 + i));
    }
    return sousTab;
}


int main(){
    int* tab = cree_tab_carre(10);
    afficherTab(tab, 10);
    int* sousTab = sous_tab(tab, 10, 5, 9);
    afficherTab(sousTab, 5);
    free(tab);
    free(sousTab);
}

//17

