#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//---1


// hb + 1/3 hb


//---2

// hb * 2-1



//---3

// Etoilel = l * 2 + 1

//--4


// Espacel = l/2-Etoile/2


//-------------Mise en oeuvre-----------


//------------------------1

char** allouer_sapin (int h, int l){
    char** hauteur = (char**) malloc(sizeof(char*)*h);
    if (hauteur == NULL) exit(-1);
    for(int i = 0; i<h; i++){
        *(hauteur + i) = (char*) malloc(sizeof(char)*l);
        if(*(hauteur + i) == NULL) exit (-1);
    }
    return hauteur;
}


//-------------------------2
void liberer_sapin(char** m,int h){
    for(int i = 0; i<h; i++){
        free(*(m + i));
    }
    free(m);
}


//--------------------------3


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


//---------------------4

void afficher_sapin(char** sapin, int h, int l){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            printf("%c", sapin[i][j]);
        }
        printf("\n");
    }
}

//---------------5


//4



//----------------------Partie2------------------------


//------------------1

typedef struct{
    int x;
    int y;
}Position_t;


//-----------------------2

int positionValide(char** sapin, Position_t p){
    if (sapin[p.x][p.y] == '*'){
        return 1;
    }
    return 0;
}



//------------------------3

int aleatoire(int min, int max){
    static int rand_init = 0;
    if(!rand_init){
        srand(time(NULL));
        rand_init = 1;
    }
    return rand()%(max-min) + min;
}


void mystere(Position_t* deco, int nb_boules, char** sapin, int h_branches, int largeur){
    int ligne = 0;
    int colonne = 0;
    for(int i = 0; i<nb_boules;i++){
        do{
            ligne = aleatoire(0, h_branches);
            colonne = aleatoire(0, largeur);
            deco[i].x = ligne;
            deco[i].y = colonne;
        }while(!positionValide(sapin, deco[i]));
    }
    return;
}

// la fonction mystere retourne un tableau de position_t contenant les position valide pour les décorations

void afficheTab(Position_t* deco, int size){
    printf("indice boules : ");
    for(int i = 0; i<size; i++){
        printf("(%d,%d) ", deco[i].x, deco[i].y);
    }
    printf("\n");
    return;
}


//--------------------------------------------------------4


void decorer_sapin(char** sapin, Position_t* deco, int sizeDeco){
    for (int i = 0; i<sizeDeco; i++){
        sapin[deco[i].x][deco[i].y] = 'o';
    }
    return;
}



//-------------------------------5


int main(){
    int hb = 0;
    printf("entrez la hauteur des branches : ");
    scanf("%d",&hb);
    int h = hb + hb/3;
    int l = hb * 2;
    char** sapin = allouer_sapin(h,l);
    initialiser_sapin(sapin, h,l,hb);
    //afficher_sapin(sapin, h, l);


    int qteBoules = 0;
    printf("Entrez la quantité de boules : ");
    scanf("%d", &qteBoules);


    Position_t* deco = (Position_t*) malloc(sizeof(Position_t)*qteBoules);
    mystere(deco, qteBoules, sapin, hb, l);
    afficheTab(deco, qteBoules);



    decorer_sapin(sapin, deco, qteBoules);
    afficher_sapin(sapin,h,l);

    free(deco);
    liberer_sapin(sapin, h);
}




