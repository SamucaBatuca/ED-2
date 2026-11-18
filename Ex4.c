#include <stdio.h>
#include <stdlib.h>
int soma;

int soma_dig(int num){
    /*a cada iteracao, verifica se já consumiu todos os digitos e vai somando*/
    if(num<=0){return soma;}
    soma += num % 10;
    num = num / 10;
    soma_dig(num);
}

int pot(int base, int exp){
    /*a cada iteracao, verifica se já consumiu todos os digitos e vai multiplicando*/
    if(exp<=0){return 1;}
    return base * pot(base, exp-1);
}

int inverte(char *str, int tam){
    /*a cada iteracao, verifica se já consumiu todos os digitos e vai invertendo*/
    if(tam<=0){return 0;}
    printf("%c", str[tam-1]);
    inverte(str, tam-1);
}


int main(){
    printf("%ld\n", soma_ate(5));
    printf("%d\n", pot(2, 3));
    inverte("Teste", 6);
}