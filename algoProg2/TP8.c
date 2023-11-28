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
    int espace = l/2 - 1;
    int etoile = 0;
    for (int i = 0; i<hb;i++){
        for(int j = 0; j<espace; j++){
            sapin[i][j] = ' ';
        }
        for(int j = espace; j<l/2 + etoile; j++){
            sapin[i][j] = '*';
        }
        espace--;
        etoile += 1;
    }
    for(int i = hb; i<h; i++){
        for(int j = 0; j<l/2-1;j++){
            sapin[i][j] = ' ';
        }
        for (int j =l/2-2; j<(l/2-1)+2; j++){
            sapin[i][j] = '+';
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

typedef struct{
    int x;
    int y;
}Position;

int positionValide(char** sapin, Position p){
    if (sapin[p.x][p.y] == '*'){
        return 1;
    }
    return 0;
}



int main(){
    int hb = 0;
    printf("entrez la hauteur des branches : ");
    scanf("%d",&hb);
    int h = hb + hb/3;
    int l = hb * 2;
    char** sapin = allouer_sapin(h,l);
    initialiser_sapin(sapin, h,l,hb);
    afficher_sapin(sapin, h, l);
}


//---------------5


//4



