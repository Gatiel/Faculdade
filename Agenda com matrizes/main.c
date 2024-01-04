#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_TELEFONE 15
#define TAM_NOME 50


void adicionarContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *numContatos){
    printf("Digite o nome: ");
    scanf("%s", nomes[*numContatos]);
    printf("Digite o telefone: ");
    scanf("%s", telefones[*numContatos]);

    (*numContatos)++;
}

void listarContatos(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int numContatos){
    if(numContatos > 0) {
        printf("Contatos na agenda:\n");

        for(int i = 0; i < numContatos; i++){
            printf("%d. Nome: %s, Telefone: %s\n", i + 1, nomes[i], telefones[i]);
        }
    } else {
        printf("A agenda está vazia.\n");
        }
}

void excluirContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *numContatos ){
    if (*numContatos > 0) {
        printf("Contatos na agenda:\n");

        for(int i = 0; i < *numContatos; i++){
            printf("%d. Nome: %s, Telefone: %s\n", i + 1, nomes[i], telefones[i]);
        }

        int indice;
        printf("Digite o número do contato a ser excluído: ");
        scanf ("%d", &indice);

        if(indice > 0 && indice <= &numContatos) {
                for(int i = indice - 1; i < *numContatos - 1; i++){
                    strcpy(nomes[i], nomes[i + 1]);
                    strcpy(telefones[i], telefones[i + 1]);
                } (*numContatos)--;
        } else {
            printf("Índice inválido.\n");
        }
} else {
            printf("Agenda vazia.\n");
}}

void alterarContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *numContatos) {
    if (numContatos > 0){
        printf("Contatos na agenda:\n");
        for(int i = 0; i < numContatos; i++) {
            printf("%d. Nome: %s, Telefone: %s\n", i + 1, nomes[i], telefones[i]);
        }

        int indice;
        printf("Digite o indice para ser alterado: ");
        scanf("%d", &indice);

        if (indice > 0 && indice <= numContatos){
            printf("Digite o novo nome:");
            scanf("%s", nomes[indice - 1]);
            printf("Digite o novo numero:");
            scanf("%s", telefones[indice - 1]);
            printf("Contato alterado com sucesso.\n");
            }
        } else {
                printf("Indice inexiste.\n");
            }
}


int main() {
    char nomes[MAX_CONTATOS][TAM_NOME];
    char telefones[MAX_CONTATOS][TAM_TELEFONE];
    int numContatos = 0;
    int opcao;

    printf("Selecione uma opcao: ");

    do{
        printf("\n1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Excluir Contato\n");
        printf("4. Alterar Contato\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            adicionarContato(nomes, telefones, &numContatos);
            break;
        case 2:
            listarContatos(nomes, telefones, numContatos);
            break;
        case 3:
            excluirContato(nomes, telefones, &numContatos);
            break;
        case 4:
            alterarContato(nomes, telefones, numContatos);
            break;
        default:
            printf("opcao invalida");
        }
    } while (opcao != 5);
    return 0;
}
