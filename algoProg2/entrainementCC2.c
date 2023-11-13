#include <stdio.h>


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

    
}



