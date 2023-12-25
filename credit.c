#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

char* sayCompany(int digitos, long n){
    char* name = "Desconhecido";

    char strNumero[20];
    sprintf(strNumero, "%ld", n);

    if (digitos == 15 && strNumero[0] == '3' && (strNumero[1] == '4' || strNumero[1] == '7')){
        name = "American Express";
    }
    if (digitos == 16 && strNumero[0] == '5' && (strNumero[1] == '1' || strNumero[1] == '2' ||strNumero[1] == '3' || strNumero[1] == '4' || strNumero[1] == '5' )){
        name = "MasterCard";
    }
    if ((digitos == 13 || digitos == 16) && strNumero[0] == '4'){
        name = "Visa";
    }
    return name;
}

int contarDigitos(long n){
    int contador = 0;

    if (n < 0){
        n = -n;
    }

    do {
        n /= 10;
        contador++;
    } while (n != 0);

    return contador;

}

bool verificaLuhn(long n){
    char strNumero[20];
    sprintf(strNumero, "%ld", n);

    int soma = 0;
    int tamanho = 0;

    for(int i = 0; strNumero[i] != '\0'; i++) {
        tamanho++;
    }

    for(int i = tamanho - 2; i >= 0; i -=2){
        int digito = strNumero[i] - '0';
        digito *= 2;

        if (digito > 9){
            digito = (digito % 10) + 1;
        }
        soma += digito;
    }

    for (int i = tamanho -1; i >= 0; i -=2) {
        int digito = strNumero[i] - '0';
        soma += digito;
    }

    return (soma % 10 == 0);
}

bool verificarNumero(long n) {
    long temp = n;
    int contagemDigitos = 0;
    while(temp != 0){
        temp /= 10;
        contagemDigitos++;
    }
    if(contagemDigitos != 16) {
        return false;
    }
    if ( n < -9223372036854775807 || n > 9223372036854775807) {
        return false;
    }
    return true;

}


int main(void)
{
  long n = get_long("Digite o Nº do cartão: \n");
    int digitos = contarDigitos(n);
    char* company = sayCompany(digitos, n);


   if (verificaLuhn(n)) {
    printf("\n| Number VALID! \n");
   }
   else {
    printf("\n| Number Invalid! \n");
   }

   if (verificarNumero(n)) {
   printf("| THE CARD IS VALID! --> Nº: %ld\n", n);
   }
   else {
    printf("| INVALID! --> Nº: %ld\n", n);
   }

    printf("| NUMBER OF DIGITS: %d\n", digitos);
    printf("| NAME OF COMPANY: %s\n", company);
}
