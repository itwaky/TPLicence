#include <stdio.h>
#include <stdlib.h>
#define SIZE 8



// Prends toutes les moyenne * leurs ects et les divise par 30
float calculMoy (float* tab){
    float total = 0;
    for (int i = 0; i < 8; i++){
        if (i == 0 || i == 3){
            total += *(tab + i)*6;
        }else if (i == 2){
            total += *(tab + i)*4;
        }else if (i == 1 || i == 4 || i == 5 || i == 6){
            total += *(tab + i)*3;
        }else{
            total += *(tab+i)*2;
        }
    }
    return total/30;
    //return (algebre*6 + fcr*3 + progFonc*4 + AlgoProg*6 + bdd*3 + progWeb*3 + anglais*3 + ppe*2) / 30;
}


//Demande les moyenne de l'utilisateur est les enregistre dans un tableau dont l'adress du premier element est retourner
float* entreMoy(){
    float* tab = malloc(SIZE * sizeof(float));
    printf("Entrez vos moyennes dans l'ordre suivant : 0->algebre, 1->fcr, 2->progFonc, 3->AlgoProg, 4->bdd, 5->progWeb, 6->anglais, 7->ppe\n");
    for (int i = 0; i < 8; i = i + 1){
        printf("Entrez la moyenne %d : ", i);
        scanf("%f", tab+i);

        //printf("boucle Numero = %d\n element = %f\n", i, *(tab + i));   
    }
    return tab;


}




int main(){
    int finUtil = 1;
    float* adressTab = entreMoy();
    printf("La moyenne seras de : %f\n", calculMoy(adressTab));
    while (finUtil)
    {
        char choix = 'n';
        printf("Voulez vous changer une moyenne ? (y/n) : ");
        scanf("\n%c", &choix);
        if (choix == 'y'){
            int choixMoy = -1;
            printf("Quelle moyenne voulez vous changer (rappel : 0=algebre, 1=fcr, 2=progFonc, 3=AlgoProg, 4=bdd, 5=progWeb, 6=anglais, 7=ppe): ");
            scanf("%d", &choixMoy);
            if (choixMoy >= 0 && choixMoy <=7){
                float newMoy = 0;
                printf("Entrez la nouvelle moyenne : ");
                scanf("%f", &newMoy);
                *(adressTab + choixMoy) = newMoy;
                printf("La nouvelle moyenne seras de : %f\n", calculMoy(adressTab));
            }
            else{
                printf("Entre invalide.\n");
                break;
            }
        }else{
            break;
        }
    }
}