#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionar (void);
void remover (void);
void listar (void);


char *lista, *nome;

int main()
{
	int x=0;

	lista = malloc(sizeof(char));
	nome = malloc(sizeof(char));

	strcpy(lista, "\0");

	while(1)
	{
		printf("Escolha uma opcao:\n\n1.Adicionar nome\n2.Remover nome\n3.Listar nomes\n4.Sair\n");
		scanf("%i",&x);
		setbuf(stdin, NULL);
		switch (x)
		{
		case 1:
			adicionar();
			break;
		case 2:
			remover();
			break;
		case 3:
			listar();
			break;
		case 4:
			free(lista);
			exit(0);
			break;
		default:
			break;
		}
		
	}
	return 0;
}

void adicionar (void)
{
	char aux[50], *temp;
	int n;

	printf("Dgite o nome: ");
	scanf("%[^\n]",aux);
	setbuf(stdin, NULL);

	n = strlen(aux);
	temp = realloc(lista, _msize(lista) + (sizeof(char)* (n+2)));

	if(temp != NULL) 		//Verifica se há espaço para a realoacação
	{
		lista = temp;
	}
	else
	{
		printf("\n*Nao ha espaco de memoria suficiente para adicionar mais um nome.*\n");
	}

	strcat(lista, aux);
	strcat(lista, ",");		//Separação para o token
}

void listar (void)
{
    char *temp, *tkn;
	int i=1;

	temp = (char *)malloc(_msize(lista));		//string temporária para printar os nomes

	memcpy(temp, lista, _msize(lista));

	tkn = strtok(temp, ",");

	if(tkn == NULL)
		printf("Nao ha nomes.\n");
	else
		printf("Lista de nomes:\n");
	
	while(tkn != NULL)
	{
		printf("%i - %s\n", i, tkn);
		tkn = strtok(NULL, ",");
		i++;
	}
	free(temp);
}

void remover (void)
{
	char *temp, *tkn, *nova, *lixo;
	int i, x, rmv;
	temp = (char *)malloc(_msize(lista));		//string temporária para não mexer na principal

	memcpy(temp, lista, _msize(lista));

	printf("\n");
	listar();
	printf("Qual nome deseja remover?\n");
	scanf("%i",&x);
	setbuf(stdin, NULL);
	x = x-1;			//x-1 pois a opção começa em 1 e não em 0

	tkn = strtok(temp, ",");
	for(i=0; tkn != NULL; i++)
	{
		if(i == x) 		
		{
			rmv = sizeof(tkn) * sizeof(char);
		}
		tkn = strtok(NULL, ",");
	}

	nova = (char *)malloc(_msize(lista) - (rmv * sizeof(char)));		//aloca memoria p/ nova string com menos espaço
    strcpy (nova, "\0");

	memcpy(temp, lista, _msize(lista));		//recupera os dados de lista para temp
    tkn = strtok(temp, ",");

    for (i=0; tkn != NULL; i++)
    {
        if (i != x)				//copia para a string nova as tokens que vão ficar
        {
            strcat(nova, tkn);
            strcat(nova, ",");
        }
        tkn = strtok(NULL, ",");
    }

    lixo = lista;
    lista = nova;

    free (lixo);
    free (temp);
}