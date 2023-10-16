
#include <stdio.h>

int mcCarty(int n){
    if (n>100){
        return n - 10;
    }else{
        mcCarty(mcCarty(n + 11));
    }
};

// Affiche la table d'un entier x
// entre : entier
// sortie : void

void multiplication(int x){
    for (int i = 1; i<=10; ++i){
        printf("%d x %d = %d\n", i, x, x*i);
    }
}


int main(){
    int entier = 0;
    int choix = 1;
    do
    {
        printf("Entre un entier :");
        scanf("%d", &entier);
        multiplication(entier);

        printf("Souhaitez vous recommencer avec un autre entier ? : (0->non|1->oui) ");
        scanf("%d", &choix);
    } while (choix);
    
    return 0;
};