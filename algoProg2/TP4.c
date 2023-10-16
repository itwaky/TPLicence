#include <stdio.h>


// ----------------------------1.a------------------------

void afficher_tab(const int tab[], int size){
    for (int i = 0; i<size; ++i){
        printf("%d\t ", tab[i]);
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



// --------------------------2.a----------------------------


// int maximum(int tab[], int size){
//     int temp = tab[0];
//     for(int i = 1; i<size ; ++i){
//         if (temp<tab[i]){
//             temp = tab[i];
//         }
//     }
//     return temp;
// }



//---------------------------2.b--------------------------

// int indiceMax(int tab[], int size){
//     int temp = tab[0];
//     int indiceMax = 0;
//     for(int i = 1; i<size ; ++i){
//         if (temp<tab[i]){
//             temp = tab[i];
//             indiceMax = i;
//         }
//     }
//     return indiceMax;
// 
// }
// 
// 
// int main(){
//     int tab[5] = {2,8,2,3,4};
//     int max = indiceMax(tab, 5);
//     printf("%d\n", max);
// }


//------------------------------3-------------------------------


//int rechercheWhile(int tab[],int size, int elem){
//    int i = 0;
//    while (i != size - 1)
//    {
//        if(tab[i] == elem){
//            return i;
//        }
//        ++i;
//    }
//    
//    return -1;
//}

//int recherche(int tab[],int size, int elem){
//    for (int i = 0; i<size; ++i){
//        if(tab[i] == elem){
//            return i;
//        }
//    }
//    return -1;
//}
// 
// int main(){
//     int tab[5] = {1,2,3,4,5};
//     printf("%d\n", recherche(tab, 5, 7));
// }



//-------------------------------4-----------------------------------

// remplace l'élément par 0 puis le déplace à la fin du tableau
// paramètres : tableau flottant, taille du tableau de flottant -> entier, indice de l'élément a supprimer -> entier
// sortie : void

void supprimeTab(float tab[], int size, int elem){
    for (int i = elem; i<size - 1; ++i){
        tab[i] = tab[i+1];
        if (i == size - 2){
            tab[i+1] = 0;
        }
    }
}


int main(){
    float tab[5] = {1,2,3,4,5};
    supprimeTab(tab, 5, 3);
}


//---------------------------------5-------------------------------


// void insertTab(float tab[],int pos, int elem){
//     tab[pos] = elem;
// }
// 
// 
// int main(){
//     float tab[5] = {1,2,3,4,5};
//     insertTab(tab, 3, 10);
// }

