#include <stdlib.h>
#include <stdio.h>


//---1


// hb + 1/3 hb


//---2

// hb * 2-1



//---3

// Etoilel = l * 2 + 1

//--4


// Espacel = l/2-Etoile/2


//-------------Mise en oeuvre-----------


//1

char** allouer_sapin (int h, int l){
    char** hauteur = (char**) malloc(sizeof(char*)*h);
    if (hauteur == NULL) exit(-1);
    for(int i = 0; i<h; i++){
        *(hauteur + i) = (char*) malloc(sizeof(char)*l);
        if(*(hauteur + i) == NULL) exit (-1);
    }
    return hauteur;
}


//2
void liberer_sapin(char **m,int l){
    for(int i = 0; i<l; i++){
        free(*(m + i));
    }
    free(m);
}


//3


void initialiser_sapin(char** sapin, int h, int l, int hb){
    int espace = 0;
    for(int i = hb-1; i==0; i++){
        for(int j = 0; j<l; j++){
            if(j < espace){
                *(*(sapin+i)+j) = ' ';
            }else{
                *(*(sapin+i)+j) = '*';
            }
            espace++;
        }
    }
}

void afficher_sapin(char** sapin, int h, int l){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            printf("%c", sapin[i][j]);
        }
        printf("\n");
    }
}



int main(){

    char** sapin = allouer_sapin(5,5);
    initialiser_sapin(sapin, 5,5,5);
    afficher_sapin(sapin, 5, 5);
}