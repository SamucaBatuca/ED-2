#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int soma;

static long soma_ate_cauda(long n, long acc){
    if (n <= 0){return acc;}
    return soma_ate_cauda(n-1, acc + n);
}

void ite_soma(long n){
    long acc = 0;
    for(long i = 1; i <= n; i++){
        acc += i;
    }
    printf("%ld\n", acc);
}


void inverte_cauda(char *str, int pos, char *acc){
    if(str[pos] == '\0'){return;}
    
    acc[pos] = str[strlen(str)-1 - pos];
    inverte_cauda(str, pos+1, acc);
    
}

void ite_inverte(char *str){
    char *acc = malloc(strlen(str)+1);
    for(int i = 0; i < strlen(str); i++){
        acc[i] = str[strlen(str)-1 - i];
    }
    acc[strlen(str)] = '\0';
    printf("%s\n", acc);
    free(acc);
}


int main(){
    printf("%ld\n", soma_ate_cauda(5, 0));
    char *teste = malloc(sizeof("Teste"));
    inverte_cauda("Teste", 0, teste);
    printf("%s\n", teste);
    free(teste);


}