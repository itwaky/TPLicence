#include <stdio.h>

#include <string.h>


//------------------------CC2--2022------------------------------

//-----------exercice1


//-----1.1

int estADN(char ADN[]){
    int i = 0;
    while(ADN[i]!='\0'){
        if (ADN[i] != 'A' && ADN[i] != 'C' && ADN[i] != 'G' && ADN[i] != 'T'){
            return 0;
        }
        i++;
    }
    return 1;
}


//------1.2

float diffChaine(char ADN1[], char ADN2[]){
    int i = 0;
    int diff = 0;
    while(ADN1[i] != '\0'){
        if(ADN1[i] != ADN2[i]){
            diff++;
        }
        i++;
    }
    return (float) diff/i;
}

//------1.3

int noteAdn(char ADN[]){
    int i = 0;
    int note = 0;
    while(ADN[i] != '\0'){
        if(ADN[i] == 'A'){
            note++;
        }
        if(ADN[i] == 'C'){
            note += 2;
        }
        if(ADN[i] == 'G'){
            note += 4;
        }
        i++;
    }
    return note;
}



//------------exercice2

//----2.1


typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct
{
    int numLocation;
    Date dateDebut;
    Date dateFin;
}Contrat;

typedef struct
{
    char modele[20];
    int nImma;
    int kilometrage;
    int dispo;
    Contrat contratLocation;
}Voiture;


Voiture initVoiture(char modele[], int imma, int kilometrage){
    Voiture v;
    strcpy(v.modele, modele);
    v.nImma = imma;
    v.kilometrage = kilometrage;
    v.dispo = 1;
    Date debut = {0,0,0};
    Date fin = {0,0,0};
    Contrat c = {0, debut, fin};
    v.contratLocation = c;
    return v;
}

void afficheVoiture(Voiture v){
    int i = 0;
    printf("Modele : ");
    while(v.modele[i] != '\0'){
        printf("%c", v.modele[i]);
        i++;
    }
    printf(" numéros immatriculation : %d, kilometrage : %d, dispo : %d\n", v.nImma, v.kilometrage, v.dispo);
}

void afficheVoitureContrat(Voiture v){
    afficheVoiture(v);
    printf("Contrat : ");
    Contrat c = v.contratLocation;
    Date dateDebut = c.dateDebut;
    Date dateFin = c.dateFin;
    printf("nContrat : %d, date début : %d/%d/%d, date fin : %d/%d/%d \n\n", c.numLocation, dateDebut.jour, dateDebut.mois, dateDebut.annee, dateFin.jour, dateFin.mois, dateFin.annee);

}


void dispo(const Voiture tab[], int size){
    printf("Modèles disponibles : \n");
    for(int i = 0; i<size; i++){
        if(tab[i].dispo){
            afficheVoiture(tab[i]);
        }
    }

}



Voiture nouveau_contrat(Voiture v, Date dateDebut, Date dateFin){
    static int id = 1;
    v.dispo = 0;
    Contrat c = {id, dateDebut, dateFin};
    v.contratLocation = c;
    id++;
    return v;
}


int main(){
    // 1.1
    // char adnVrai[] = "AACTTGGCATGA";
    // char adnFaux[] = "AACTTGGCAETGA";
    // printf("Vrai : %d , Faux : %d \n", estADN(adnVrai), estADN(adnFaux));

    // 1.2
    // char adn1[] = "ATTC";
    // char adn2[] = "ACTG";
    // printf("Difference  = %f\n", diffChaine(adn1, adn2));


    // 1.3
    // char adn[] = "AATGC";
    // printf("Note : %d\n", noteAdn(adn));

    // 2.2
    char modele[] = "toyota";
    int nImma = 123456789;
    int kilometrage = 100000;
    Voiture v = initVoiture(modele, nImma, kilometrage);
    // afficheVoiture(v);
    

    char modele2[] = "audi";
    int nImma2 = 987654321;
    int kilometrage2 = 9999;
    Voiture v2 = initVoiture(modele2, nImma2, kilometrage2);
    // Voiture tab[] = {v, v2};
    // dispo(tab, 2);

    afficheVoitureContrat(v);

    Date dateDebut = {12,01,2019};
    Date dateFin = {20,01,2019};
    v = nouveau_contrat(v, dateDebut, dateFin);

    afficheVoitureContrat(v);

    Date dateDebut2 = {21,02, 2019};
    Date dateFin2 = {28, 02, 2019};
    v = nouveau_contrat(v, dateDebut2, dateFin2);

    afficheVoitureContrat(v);


}




//----------------------CC2--2021----------------------------------





