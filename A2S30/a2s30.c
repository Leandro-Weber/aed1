#include <stdio.h>
#include <stdlib.h>

int menu(void);

int ** criaMatriz(int nrow, int ncol);

void leiaMatriz(int **mat, int nrow, int ncol);

int somaMatriz(int **mat, int m, int n);

int* colunaMatriz(int ** mat, int m, int n, int ncoluna);

void liberaMatriz(int **mat, int ncoluna);

void imprimeMatriz(int **mat, int m, int n);

void imprimeVetor (int *vet, int n);


int main()
{
    int i, x, nrow=0, ncol=0, **m, soma, nvet, *vetor;

    while(1)
    {
        x = menu();
        switch (x)
        {
        case 1:
            liberaMatriz(m, nrow);
            printf("Informe o numero de linhas e colunas desejados: ");
            scanf("%d %d",&nrow, &ncol); 
            setbuf(stdin, NULL);
            m = criaMatriz(nrow, ncol);
            break;
        case 2:
            leiaMatriz(m, nrow, ncol);
            break;
        case 3:
            soma = somaMatriz(m, nrow, ncol);
            printf("A soma dos valores da matriz sao: %d", soma);
            break;
        case 4:
            printf("Qual coluna deseja imprimir?");
            scanf("%d",&nvet);
            setbuf(stdin, NULL);
            vetor = colunaMatriz(m, nrow, ncol, nvet);
            imprimeVetor(vetor, nrow);
            free(vetor);
            break;
        case 5:
            imprimeMatriz(m, nrow, ncol);
            break;
        case 6:
            liberaMatriz(m, nrow);
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}

int menu (void)
{
    int x;
    printf("\nMenu de opcoes:\n1.Criar uma matriz\n2.Inserir elementos na matriz\n3.Imprimir a soma dos elementos\n4.Imprimir uma coluna\n5.Imprimir a matriz\n6.Sair\n");
    scanf("%d",&x);
    setbuf(stdin, NULL);
    return x;
}

int ** criaMatriz(int nrow, int ncol)
{
    int i,**mat;

    mat = (int **)malloc(nrow * sizeof(int));

    for(i=0; i<nrow; i++)
        mat[i] = (int *)malloc(ncol * sizeof(int));

    return mat;
}

void leiaMatriz(int **mat, int nrow, int ncol)
{
    int i=0, j=0;

    for(i=0; i<nrow; i++)
    {
        for (j = 0; j < ncol; j++)
        {
            printf("Linha %i/%i coluna %i/%i: ",i,nrow-1,j,ncol-1);
            scanf("%d",&mat[i][j]);
            setbuf(stdin, NULL);
        }
    }
}

int somaMatriz(int **mat, int m, int n)
{
    int soma=0, i, j;

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            soma = soma + mat[i][j];
        }
        
    }
    return soma;
}

void liberaMatriz(int **mat, int ncoluna)
{
    if (ncoluna!=0 && mat!=NULL)
    {
        for (int i=0; i<ncoluna; i++)
        {
            free (mat[i]);
        }
        free (mat);
        
    }
}

int* colunaMatriz(int ** mat, int m, int n, int ncoluna)
{
    int *vetor, i;
    vetor = (int*)malloc(sizeof(int) * m);
    for(i=0; i<m; i++)
    {
        vetor[i]=mat[i][ncoluna];
    }
    return vetor;
}

void imprimeVetor (int *vet, int n)
{
    int i;
    printf("Vetor de colunas: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ",vet[i]);
    }
}

void imprimeMatriz(int **mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        printf("Linha %d: ",i);
        for (j = 0; j < n; j++)
        {
            printf("%d ",mat[i][j]);
        }   
    }
}