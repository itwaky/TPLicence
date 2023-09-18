#include <stdio.h>


int nbMois (int nb, int annee){
    if (nb == 1 || nb == 3 || nb == 5 || nb == 7 || nb == 8 || nb == 10 || nb == 12){
        return 31;
    }
    if (nb == 4 || nb == 6 || nb == 9 || 11){
        return 30;
    }
    if (nb == 2 && annee == 1){
        printf("%d\n", 1);
        return 29;
    }else{
        printf("%d\n", 0);
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
    printf("%d\n", bissextile(annee));
    int dureeMois = nbMois(mois, bissextile(annee));
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




