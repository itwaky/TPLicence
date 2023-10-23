#include <stdio.h>


//-----------------------------exercice1--------------------------------



int int_of_char (char c) {
    return (c-65);
}

char char_of_int (int n) {
    return (n+65);
}

void affiche_str(char str[]){
    int i = 0;
    while(str[i]!='\0'){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

/*
* Fonction code_cara
* code un caractère avec un décalage de 13 caractère sur la table ascii
* entrer : char entre 'A' et 'Z' inclus
* sortie : char coder entre 'A' et 'Z' inclus
*/
char code_cara(char c){
    return char_of_int((int_of_char(c) + 13) % 26);
}


char code_caraN(char c, int n){
    return char_of_int((int_of_char(c) + n) % 26);
}


/*
* Fonction code_message
* code une chaine de caractère avec un décalage des caractère de 13 sur la table ascii pour chaques caractères de la chaine
* entrer : chaine de caractère contenant des caractère de 'A' a 'Z' dans la table ascii
* sortie :chaine de caractère coder contenant des caractère de 'A' a 'Z' dans la table ascii
*/
void code_message(char str[]){
    int i = 0;
    while(str[i]!='\0'){
        str[i] = code_cara(str[i]);
        i++;
    }
}

void code_messageN(char str[], int n){
    int i = 0;
    while(str[i]!='\0'){
        str[i] = code_caraN(str[i], n);
        i++;
    }
}

int indice_max(int tab[], int size){
    int max = tab[0];
    int indice = 0;
    for(int i = 1; i<size;++i){
        if(tab[i]>max){
            max = tab[i];
            indice = i;
        }
    }
    return indice;
}


/*
* Fonction plusFrequent
* renvoie le caractère le plus fréquent du chaine de caractère
* entré: tableau de charactères les caractère doivent inclus entre 'A' et 'Z'
* sortie: charactère le plus fréquent
*/
char plusFrequent(char str[]){
    int i = 0;
    int tab[25] = {0};
    while(str[i]!='\0'){
        tab[int_of_char(str[i])]++;
        i++;
    }
    int c = indice_max(tab, 26);
    return char_of_int(c);
}


void decode_chaine(char str[]){
    int plusFreq = int_of_char(plusFrequent(str));
    int decalage = int_of_char('E') - plusFreq;
    printf("Le décalage est de : %d \n", decalage);
    if (decalage<0){
        decalage = decalage + 26;
    }
    code_messageN(str, decalage);
}

int main(){
    // char str[99];
    // int decal = 0;
    // printf("Entre une chaine de caractère en majuscule a coder : ");
    // scanf("%s", str);
    // printf("Entrez le décalage : ");
    // scanf("%d", &decal);
    // code_messageN(str, decal);
    // printf("Le message coder est  : ");
    // affiche_str(str);
    char str[] = "IYHCVSHSLAAYLSHWSBZMYLXBLUALLZASLL";
    printf("Lettre + frequente est : %c \n", plusFrequent(str));
    decode_chaine(str);
    affiche_str(str);   

}




