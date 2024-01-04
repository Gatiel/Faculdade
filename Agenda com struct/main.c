#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

void adicionarContato(struct Contato agenda[], int *numContatos) {
    printf("\nDigite o Nome: ");
    scanf("%s", agenda[*numContatos].nome);
    printf("Digite o telefone: ");
    scanf("%s", agenda[*numContatos].telefone);
    (*numContatos)++;
}

void listarContatos(struct Contato agenda[], int numContatos) {
    if (numContatos > 0){
        printf("\nContatos na agenda:\n");
        for (int i=0 ; i < numContatos; i++){
            printf("%d. Nome: %s, Telefone: %s\n", i + 1, agenda[i].nome, agenda[i].telefone);
        }
    } else {
        printf("A agenda esta vazia.\n");
    }
}

void excluirContatos(struct Contato agenda[], int *numContatos){
    if (*numContatos > 0) {
        printf("\nContatos na agenda:\n");
        for(int i = 0; i < *numContatos; i++){
            printf("%d. Nome: %s, Telefone:%s\n", i + 1, agenda[i].nome, agenda[i].telefone);
        }
        int indice;
        printf("\nDigite o indice para excluir: ");
        scanf("%d", &indice);

        if(indice > 0 && indice <= *numContatos){
            for(int i = indice - 1; i < *numContatos - 1; i++){
                strcpy(agenda[i].nome, agenda[i + 1].nome);
                strcpy(agenda[i].telefone, agenda[i + 1].telefone);
            } (*numContatos)--;
            printf("Contato excluido com sucesso.\n");
        } else {
            printf("Indice invalido.\n");
        }
    } else {
    printf("A agenda esta vazia.\n");
    }
}

void alterarContato(struct Contato agenda[], int *numContatos){
    if (*numContatos > 0){
        printf("\nContatos na agenda:\n");
    for(int i = 0; i < *numContatos; i++){
        printf("%d. Nome: %s, Telefone: %s\n", i + 1, agenda[i].nome, agenda[i].telefone);

    }
        int indice;
        printf("\nDigite o indice para alterar o contato: ");
        scanf("%d", &indice);
        if(indice > 0 && indice <= *numContatos){
            printf("Digite o novo nome: ");
            scanf("%s", agenda[indice-1].nome);
            printf("Digite o novo telefone: ");
            scanf("%s", agenda[indice-1].telefone);
            printf("\nContato alterado com sucesso.\n");
        }
    }
}

int main()
{
        struct Contato agenda[100];
        int numContatos = 0;
        int opcao;
    do {
        printf("\n1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Excluir Contato\n");
        printf("4. Alterar Contato\n");
        printf("5. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            adicionarContato(agenda, &numContatos);
            break;
        case 2:
            listarContatos(agenda, numContatos);
            break;
        case 3:
            excluirContatos(agenda, &numContatos);
            break;
        case 4:
            alterarContato(agenda, &numContatos);
            break;
        default:
            printf("Alternativa inexistente\n");
        }
        } while (opcao != 5);
    }
