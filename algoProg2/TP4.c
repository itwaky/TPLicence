#include <stdio.h>


// ----------------------------1.a------------------------

void afficher_tab(int tab[], int size){
    for (int i = 0; i<size; ++i){
        printf("| %d ", tab[i]);
    }
    printf("\n");
}


// -------------------------1.c-------------------------------

void triBulles(int tab[], int size){
    int temp = 0;
    for (int i = 0; i<size - 1;i++){
        for (int j = 0; j<size - 1; j++){
            if (tab[j]>tab[j + 1]){
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

// --------------------------1.d---------------------------

// int main(){
//     int tab[] = {5,3,2,4,1};    
//     triBulles(tab, 5);
//     afficher_tab(tab, 5);
//     return 0;
// }

