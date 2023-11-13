
#include <stdio.h>



//--------------------------1.tableau de points----------------------------


typedef struct Points
{
    int x;
    int y;
}Points;

void affichePoint(Points p){
    printf("(%d,%d), ", p.x, p.y);
}


void affiche_point_tab(Points tab[], int size){
    for(int i = 0; i<size; ++i){
        affichePoint(tab[i]);
    }
    printf("\n");
}


// void afficheTab(int tab[], int size){
//     for(int i = 0; i<size; ++i){
//         printf("%d, ", tab[i]);
//     }
//     printf("\n");
// }
// 
// 
// void bulle(int tab[], int size){
//     for (int i = 0; i<size; ++i){
//         for(int j = 0; j<size - i - 1; ++j){
//             if(tab[j+1]<tab[j]){
//                 int temp = tab[j];
//                 tab[j] = tab[j+1];
//                 tab[j+1] = temp;
//             }
//         }
//     }
// }

void bullePoint(Points tab[], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size - i - 1; ++j){
            if ((tab[j].x > tab[j+1].x) || (tab[j].x == tab[j+1].x && tab[j].y>tab[j+1].y)){
                Points temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}



void bullePointDiag(Points tab[], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size - i - 1; ++j){
            if ((tab[j].x + tab[j].y > tab[j+1].x + tab[j+1].y) || (tab[j].x + tab[j].y == tab[j+1].x + tab[j+1].y && tab[j].x>tab[j+1].x)){
                Points temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

// int main(){
//     Points tp [36] = {{3,1}, {3,5}, {4,1},{5,3},{6,2},{3,2}, {5,2}, {3,4},  {3,3}, {6,1},{4,4}, {2,2}, {6,6},{5,5} ,{3,6} , {2,6} ,{1,2}, {2,3},{6,4},  {5,6} , {4,3},{4,6} , {2,4}, {1,1},{6,5}, {4,5}, {2,1}, {5,4}, {2,5},{5,1},{1,3}, {1,4}, {1,5}, {6,3}, {4,2}, {1,6}  };
// 
//     affiche_point_tab(tp, 36);
// 
// 
//     bullePoint(tp, 36);
// 
//     affiche_point_tab(tp,36);
// 
// 
//     bullePointDiag(tp, 36);
// 
//     affiche_point_tab(tp, 36);
// 
// 
// }







//----------------------------2.Matrices--------------------------


//----------1

void affiche(int matrice[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// int main(){
//     int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     affiche(matrice, 3);
// }

//-------2


int nombreDeZeros(int matrice[][3], int size){
    int total = 0;
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] == 0){
                total++;
            }
        }
    }
    return total;
}


// int main(){
// 
//     int matrice[3][3] = {{1,2,0},{4,0,6},{0,8,9}};
//     printf("nb zero : %d", nombreDeZeros(matrice, 3));
// }

//-----3

int estDiagonale(int matrice[][3], int size){
    int diag = matrice[0][0];
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] != diag){
                return 0;
            }
        }
    }
    return 1;
}


//------4


int estSymetrique(int matrice[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] != matrice[j][i]){
                return 0;
            }
        }
    }
    return 1;
}


// int main(){
//     int matrice[3][3] = {{1,4,7},
//                          {4,5,8},
//                          {7,8,9}};
//     affiche(matrice, 3);
//     printf("La matrice est elle symetrique : %d \n", estSymetrique(matrice, 3));
// }


//--------5

void transpose(int matrice[][3],int matrice2[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            matrice2[i][j] = matrice[j][i];
            matrice2[j][i] = matrice[i][j];
        }
    }
}


// int main(){
//     int matrice[3][3] = {{1,4,8},
//                          {5,5,8},
//                          {7,8,9}};
//     int matrice2[3][3] = {};
// 
//     affiche(matrice, 3);
//     
//     transpose(matrice,matrice2, 3);
// 
//     affiche(matrice2, 3);
// }


//--------6

void addition(int matrice[][3], int matrice2[][3], int size){
    for(int i = 0; i<size ; ++i){
        for(int j = 0; j<size; ++j){
            matrice[i][j] = matrice[i][j] + matrice2[i][j];
        }
    }
}

// int main(){
//     int matrice[3][3] = {{1,4,8},
//                          {5,5,8},
//                          {7,8,9}};
//     int matrice2[3][3] = {{1,4,8},
//                           {5,5,8},
//                           {7,8,9}};
// 
// 
//     addition(matrice, matrice2, 3);
//     affiche(matrice, 3);
// }


//---------7

#define N 3
typedef int Matrice[N][N];

void multiplication(Matrice matrice1, Matrice matrice2){
    Matrice temp = {{0}};// chiant a innitialiser donc marche pas;
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            int total = 0;
            for(int k = 0; k<N; ++k){
                total += matrice1[i][k] * matrice2[k][j];
            }
            temp[i][j] = total;
        }
    }
    for(int i = 0 ; i<N ; ++i){
        for(int j = 0; j<N; ++j){
            matrice1[i][j] = temp[i][j];
        }
    }
}

int main(){
    int matrice[3][3] = {{1,4,8},
                         {5,5,8},
                         {7,8,9}};
    int matrice2[3][3] = {{1,4,8},
                          {5,5,8},
                          {7,8,9}};


    multiplication(matrice, matrice2);

    affiche(matrice, 3);
}


