#include <stdio.h>

//-----------------------------exercice1------------------------



int nbMois (int nb, int annee){
    printf("Debut fonction nbMois \n");
    if (nb == 1 || nb == 3 || nb == 5 || nb == 7 || nb == 8 || nb == 10 || nb == 12){
        printf("%d\n", 31);
        return 31;
    }
    if (nb == 4 || nb == 6 || nb == 9 || nb == 11){
        printf("%d\n", 30);
        return 30;
    }
    if (nb == 2 && annee == 1){
        printf("%d\n", 29);
        return 29;
    }else{
        printf("%d\n", 28);
        return 28;
    }
    printf("rate");
}

int bissextile(int annee){
    if (annee%4 != 0){
        return 0;
    }else{
        if (annee%100 == 0 && annee%400 != 0){
            return 0;
        }else{
            return 1;
        }
    }
}

void lendemain(int jour, int mois, int annee){
    //printf("%d\n", bissextile(annee));
    int anneeBissextile = bissextile(annee);
    int dureeMois = nbMois(mois, anneeBissextile);
    printf("duree du mois : %d\n", dureeMois);
    jour = jour + 1;
    if (jour > dureeMois){
        jour = 1;
        mois = mois + 1;
        if (mois > 12){
            mois = 1;
            annee = annee + 1;
        }
    }
    printf("%d/%d/%d", jour, mois, annee);
}

int main(){
    printf("%d\n", bissextile(1900));
    printf("%d\n", bissextile(1901));
    printf("%d\n", bissextile(1936));
    printf("%d\n", bissextile(2000));
    
    lendemain(30,1,2002);
    printf("\n");
    lendemain(28,2,2001);
    printf("\n");
    lendemain(28,2,2000);
    printf("\n");
    lendemain(31,1,2000);
    printf("\n");

}




//----------------------------------exercice2---------------------



/*

void calculatrice(){
    float operant1 = 0;
    float operant2 = 0;
    char operateur = 0; 
    printf("entrez votre opération que vous souhaitez effectuez : ");
    scanf("%f %c %f", &operant1, &operateur, &operant2);
    printf("operant1 = %f, operateur = %c, operant2 = %f \n", operant1, operateur, operant2);
    switch (operateur)
    {
    case '+':
        printf("Le resultat du calcul est : %f\n", operant1 + operant2);
        break;
    case '-':
        printf("Le resultat du calcul est : %f\n", operant1 - operant2);
        break;
    case '*':
        printf("Le resultat du calcul est : %f\n", operant1 * operant2);
        break;
    case '/':
        if (operant2 == 0.f){
            printf("Division par 0 impossible !\n");
        }else{
            printf("Le resultat du calcul est : %f\n", operant1 / operant2);
        }
        break;
    default:
        printf("Opétation invalide.\n");
        break;
    }

}


int main(){
    calculatrice();
}


*/

//-------------------------------exercice3----------------------------------


/*
#include <stdio.h>
int nb_jours(int mois) {
 int mj;
 if ((mois == 1) || (mois == 3) || (mois == 5) || (mois == 7) || (mois == 8) || (mois == 10) || (mois == 12) )
 mj = 31;
 else if (mois == 2)
 mj = 28;
 else if ((mois<1) || (mois>12))
 {printf("Ce mois n'existe pas.\n"); return 0;}
 else
 mj = 30;
 return mj;
}
// fonction : lendemain
// arguments : trois entiers representant le jour, le mois et l'annee.
// resultat : aucun.
// pre-conditions : l'annee n'est pas bissextile.
// post-conditions : aucune.
void lendemain (int jour, int mois , int an)
{
 int mj=nb_jours(mois);
 if ((jour<1) || (jour > mj))
 {printf("Ce jour n'existe pas.\n"); return;}
 else
 if (jour < mj)
 jour = jour+1;
 else
 {
 jour = 1;
 if (mois < 12)
 mois=mois+1;
 else
 {
 mois = 1;
 an =an+1;
 }
 }

 printf("Date du lendemain : %d / %d / %d\n",jour,mois,an);
 return;
}
int main()
{
 return 0;
}

*/