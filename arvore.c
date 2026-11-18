#include <stdio.h>
#include <stdlib.h>

// struct do registro de elementos na árvore
typedef struct reg {
    int chave;
    struct reg *pai;
    struct reg *filho;
    struct reg *irmao;
} celula;

typedef celula *arvore; // define que a célula é um ponteiro para a árvore e sub-árvore
arvore r = NULL;


arvore constroi_arv(int x) {
    arvore r;
    r = (arvore) malloc(sizeof(celula));
    r->pai = NULL;      // define como raiz
    r->chave = x;       // coloca o identificador/valor
    r->filho = NULL;    
    r->irmao = NULL;    
    return r;
}

// adiciona um filho com chave x ao nó r
void cria_filho(arvore r, int x) {
    arvore f;
    if (r != NULL) {
        f = (arvore) malloc(sizeof(celula));
        f->pai = r;         // define que ele pertence à uma sub-árvore r
        f->chave = x;       // coloca o identificador/valor
        f->filho = NULL;    // define que não tem filhos 
        f->irmao = r->filho;    // define o irmão do nó como o filho anterior da raiz
        r->filho = f;       // define o novo filho, ou folha, como o nó adicionado
    }
}


// retorna o número de filhos de um nó dado
int num_filhos(arvore r) {
    int k = 0;
    if (r != NULL) {
        r = r->filho;
        while (r != NULL) {
            k++;
            r = r->irmao;
        }
    }

    return k; 
}

arvore retorna_pai(arvore r) { return r->pai; }
    
int eh_raiz(arvore r) {
    if (retorna_pai(r) == NULL) return 1;
    else return 0; 
}

int eh_folha(arvore r) {
    if (r->filho == NULL) return 1;
    else return 0; 
}

int tamanho(arvore r) {
    if (r == NULL) return 0;
    else return 1 + tamanho(r->filho) + tamanho(r->irmao);
}

int altura(arvore r) {
    int alt, alt_maior;
    if (r == NULL) return -1;           // se n existir arvore
    if (r->filho == NULL) return 0;     // se encontrar nenhum filho
    r = r->filho;                       // desce um nível                       
    alt_maior = altura(r); 
    while (r->irmao != NULL) {          // busca lateralmente por irmãos
        r = r->irmao;
        alt = altura(r);
        if (alt_maior < alt) alt_maior = alt;   // registra o maior irmão
    }

    return alt_maior + 1;
}



int main(){

}