#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
  char firstname[15];
  char lastname[15];
  int idade;
  char cpf[11];
  struct Pessoa *prox;
} Pessoa;

typedef struct ListaNomes
{
  char nome[15];
  Pessoa *pessoa;
  struct ListaNomes *prox;
} ListaNomes;

typedef struct IndiceNome
{
  char letra;
  ListaNomes *nomes;
  struct IndiceNome *proximo;
} IndiceNome;

typedef struct ListaPessoas
{
  IndiceNome *inicio;
  IndiceNome *fim;
} ListaPessoas;

Pessoa* alocaInfo (char firstname[], char lastname[], int idade, char cpf[])
{
  Pessoa *pessoa = (Pessoa *) malloc (sizeof (Pessoa));
  if (!pessoa)
	 return NULL;

  strcpy (pessoa->firstname, firstname);
  strcpy (pessoa->lastname, lastname);
  pessoa->idade = idade;
  strcpy (pessoa->cpf, cpf);
  pessoa->prox = NULL;
  return pessoa;
}

IndiceNome* criar_indice_nome (char letra, Pessoa * pessoa)
{
  IndiceNome *novo_indice = (IndiceNome *) malloc (sizeof (IndiceNome));
  novo_indice->letra = letra;
  novo_indice->nomes = NULL;
  novo_indice->proximo = NULL;
  return novo_indice;
}

//ListaPessoas é a pilha inicial
void adicionar_pessoa (ListaPessoas * lista, Pessoa * pessoa)
{
IndiceNome* perc = lista->inicio;

  if (lista->inicio == NULL)  //se não tiver letra, cria
	 {
		lista->inicio = criar_indice_nome (pessoa->firstname[0], pessoa);
		lista->fim = lista->inicio;
		lista->inicio->nomes = (ListaNomes *) malloc (sizeof (ListaNomes));
		strcpy(lista->inicio->nomes->nome, pessoa->firstname);
		lista->inicio->nomes->pessoa = pessoa;
		lista->inicio->nomes->prox = NULL;
	 }else{    //se tiver letra

   	 //else para percorrer a letra aprocurando letra igual
   	 while(perc->letra != pessoa->firstname[0] && perc->proximo != NULL) perc = perc->proximo;
   	 // perc está na letra / está no caso de não ter a letra correta
      	 if(perc->letra != pessoa->firstname[0]){
      	      perc->proximo = criar_indice_nome (pessoa->firstname[0], pessoa);
      	      perc->proximo->nomes = (ListaNomes *) malloc (sizeof (ListaNomes));
      	      strcpy(perc->proximo->nomes->nome, pessoa->firstname);
   		      perc->proximo->nomes->pessoa = pessoa;
   		      perc->proximo->nomes->prox = NULL;
   		      lista->fim = perc->proximo;
      	   } else if(perc->letra == pessoa->firstname[0]){
      	      //se perc letra for exatamente igual a primeira letra tem 2 casos, ou nome é igual ou apenas ainicial é igual

      	      Pessoa* perc2 = perc->nomes->pessoa;
      	      while(perc2->prox != NULL) perc2 = perc2->prox;
      	      if(strcmp(perc->nomes->nome, pessoa->firstname) == 0){ //se o primeiro nome completo for igual
         	      perc2->prox = pessoa;
      	      }else { //somente a letra
      	      ListaNomes* perc3 = perc->nomes;
      	      while(perc3->nome[0] == pessoa->firstname[0] && perc3->prox != NULL) perc3 = perc3->prox;
      	         perc3->prox = (ListaNomes *) malloc (sizeof (ListaNomes));
      	         strcpy(perc3->prox->nome, pessoa->firstname);
      	         perc3->prox->prox = NULL;
      	         perc3->prox->pessoa = pessoa;
      	      }
      	   }
   }
}

Pessoa *buscar_pessoa(ListaPessoas *lista, char nome[], char sobrenome[]) {
    IndiceNome *indiceAtual = lista->inicio;

    while(indiceAtual != NULL) {
        if (indiceAtual->letra == nome[0]) {
            ListaNomes *nomes = indiceAtual->nomes;
            while (nomes != NULL) {
                Pessoa *pessoaAtual = nomes->pessoa;
                while (pessoaAtual != NULL) {
                    if (strcmp(pessoaAtual->firstname, nome) == 0 && strcmp(pessoaAtual->lastname, sobrenome) == 0) {
                        return pessoaAtual;
                    }
                    pessoaAtual = pessoaAtual->prox;
                }
                nomes = nomes->prox;
            }
        }
        indiceAtual = indiceAtual->proximo;
    }
    return NULL;
}

int main ()
{
  ListaPessoas lista;
  lista.inicio = lista.fim = NULL;

  int n, idade;
  char firstname[15], lastname[15], cpf[12];

  do {
     printf("\nDigite 1/2/3: \n");
      printf("1 - Registrar pessoa \n");
      printf("2 - Buscar pessoa \n");
      printf("3 - Sair \n\n");
      scanf("%d", &n);

     switch(n){
        case 1:
        printf("\nDigite o Primeiro Nome:  \n");
        scanf("%s", firstname);
        while(firstname[0] < 65 || firstname[0] > 90 ){
            printf("Digite com a primeira letra maiuscula: \n");
            scanf("%s", firstname);
        }
        printf("Digite o Último Nome: \n");
        scanf("%s", lastname);
        while(lastname[0] < 65 || lastname[0] > 90 ){
            printf("Digite com a primeira letra maiuscula: \n");
            scanf("%s", lastname);
        }
        printf("Digite a idade: \n");
        scanf("%d", &idade);
        printf("Digite o CPF: \n");
        scanf("%s", cpf);
        adicionar_pessoa (&lista, alocaInfo (firstname, lastname, idade, cpf));
        break;
     case 2:
      printf("Digite o primeiro nome da pessoa buscada: \n");
      scanf("%s", firstname);
      while(firstname[0] < 65 || firstname[0] > 90 ){
            printf("Digite com a primeira letra maiuscula: \n");
            scanf("%s", firstname);
        }
      printf("Digite o último nome da pessoa buscada: \n");
      scanf("%s", lastname);
      while(lastname[0] < 65 || lastname[0] > 90 ){
            printf("Digite com a primeira letra maiuscula: \n");
            scanf("%s", lastname);
        }
      Pessoa* pessoabuscada = buscar_pessoa(&lista, firstname, lastname);
      if (pessoabuscada != NULL) {
         printf("\nNome: %s\nSobrenome: %s\nCPF: %s\nIdade: %d\n\n", pessoabuscada->firstname, pessoabuscada->lastname, pessoabuscada->cpf,    pessoabuscada->idade);
         } else {
         printf("Pessoa não encontrada.\n");
                }
         break;
      case 3:
         return 0;
      default:
         printf("Opção inválida. Digite novamente.\n");
         break;
     }
  } while(n != 3 );
   return 0;
}
