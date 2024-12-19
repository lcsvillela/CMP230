#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int calc_inv(int a){

    int number = 0, inv = 0;
    for (int i = 0; i < 1000; i++){
    number =  (int) ((a * i) % 26);

    if (number == 1){
        inv = i;
        break;
        }

    }
    if (inv != 0){
    return inv;
    }else{
    return -1;
    }



}

int main (int argc, char *argv[]){

    if ( argc != 2){
     printf("faltam argumentos: escreva uma frase entre aspas com letras maiúsculas");
     return 1;
    }

    const int a = 5;
    const int b = 7;
    char *s = argv[1];
    int len = strlen(s);
    char cipher[len], cipher_num[len];
    char decrypt[len], decrypt_num[len];
    int inv=0;
    int number=0;


    for (int i = 0; i < len; i++){

        if (s[i] != ' '){
            cipher[i] = (char) ((( a * ( s[i] - 'A' ) + b ) % 26) + 'A');
            cipher_num[i] = (char) ((( a * ( s[i] ) + b ) % 26) );
        }else{
            cipher[i] = ' ';
        }
    }

    cipher[len]='\0';

    inv = calc_inv(a);
    

    for (int i = 0; i < len; i++){

            if (cipher[i] != ' '){
            decrypt[i] = (char) (((inv* ((cipher[i] + 'A'- b + 26)) % 26)) + 'A');
            decrypt_num[i] = (char) (((inv* ((cipher[i] - b + 26 )) % 26)));
    }else{
            decrypt[i] = ' ';
    }
    }
    decrypt[len] = '\0';

    printf("mensagem texto plano: %s\n", s);
    printf("mensagem texto plano em ASCII: ");
    for (int i = 0; i < len; i++){
        printf("%d ", s[i]);
    }
    printf("\n");
    printf("mensagem cifrada: %s\n", cipher);
    printf("mensagem cifrada em ASCII: ");
    for (int i = 0; i < len; i++){
    printf("%d ", cipher_num[i]);
    }
    printf("\n");

    printf("mensagem decifrada: %s\n", decrypt);
    printf("a: %d, b: %d, inverso multiplicativo de a: %d\n", a,b,inv);

    char  *alpha= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int contador[26];

    for (int i = 0; i < 26; i++)
        contador[i] =0;

    for (int i = 0; i < len; i++){
        for (int j = 0; j < 26; j++){
           
            if (cipher[i] != ' '){
            
                if (cipher[i] == alpha[j])
                    contador[j]+=1;
            }
        }
    }

    int primeiro = 0, segundo = 0;
    char letra_a, letra_e;
    for (int i = 0; i < 26; i++){
        printf("%c : %d\n", alpha[i], contador[i]);

        if (contador[i] > primeiro){
            primeiro=contador[i];
            letra_a=alpha[i];
        }
    }

    for (int i = 0; i < 26; i++){
        if ((contador[i] >= segundo) && (contador[i] < primeiro)){
            segundo=contador[i];
            letra_e=alpha[i];
        }
    }


    printf("Pela frequência das letras, a letra A é %c e a letra E é %c\n", letra_a,letra_e);

   //quebra da affine força bruta:
   //

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if ( 'A' ==  (((i* ((letra_a + 'A'- j + 26)) % 26)) + 'A') && 'E' ==  (((i* ((letra_e + 'A'- j + 26)) % 26)) + 'A')){
                printf("\nTentando a chave inverso de a: %d e b: %d\n", i,j);

                for (int k =0; k < len; k++){
                    if (cipher[k] != ' '){
                        printf("%c", (((i* ((cipher[k] + 'A'- j + 26)) % 26)) + 'A'));
                    }else{
                        printf(" ");
                    }
                }
            }

        }
    }


}
