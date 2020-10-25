#include <stdio.h>
#include <stdlib.h>

void menu (void);
void adicionar (int);
void listar (int);


typedef struct{
    char nome [30];
    int idade, altura;
}Pessoa;

Pessoa *p;


int main()
{
int x, i=0;
p=(Pessoa*)malloc(sizeof(Pessoa));

while (1)
{
    menu();
    scanf("%i",&x);
    setbuf(stdin,NULL);
    switch (x)
    {
    case 1:
        adicionar(i);
        break;
    case 2:
        listar(i);
        free(p);
        exit(0);
        break;
    default:
        break;
    }
    i++;
}

free(p);
return 0;
}

void menu (void)
{
    printf("\nSelecione uma opcao:\n1.Adicionar uma pessoa\n2.Sair\n");
}

void adicionar (int i)
{
    p=(Pessoa*)realloc(p, (i+1) * sizeof(Pessoa));

    printf("\nNome: ");
    scanf("%[^\n]",&p[i].nome);
    setbuf(stdin,NULL);

    printf("\nIdade: ");
    scanf("%i",&p[i].idade);
    setbuf(stdin,NULL);

    printf("\nAltura: ");
    scanf("%i",&p[i].altura);
    setbuf(stdin,NULL);
}

void listar (int i)
{
    int x=0;
    printf("\nLista de nomes adicionados:\n");
    for(x=0; x<i; x++)
    {
        printf("\nNome: %s\nIdade: %i\nAltura: %i\n",p[x].nome, p[x].idade, p[x].altura);
    }
}