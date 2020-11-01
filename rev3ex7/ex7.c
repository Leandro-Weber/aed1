#include <stdio.h>
#include <stdlib.h>

int* vetor(int *vet, int j, int n);

int main()
{
    int n,i=0, *vet, j=0;
    

    printf("Quantos numeros deseja inserir? ");
    scanf("%d",&n);
    setbuf(stdin, NULL);

    vet = ( int*) malloc(n * sizeof(int));

    printf("insira seus numeros: ");
    while(i<n)
    {
        scanf("%d",&vet[i]);
        setbuf(stdin, NULL);
        i++;
    }

    for ( i = 0; i < n; i++)
    {
        j=i;
        while(j<n)
        {
            if (vet[i]==vet[j+1])
            {
                vet = vetor(vet, j+1, n);
                j=i;
                n--;
            }
            else if (j<n)
            {
                j++;
            }
        }
        
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ",vet[i]);
    }
    free(vet);
    return 0;
} 

int* vetor(int *vet, int j, int n)
{
    int *temp, i,k=0;

    temp = (int*)malloc((n-1) * sizeof(int));

    for(i=0; i<n; i++)
    {
        if (i!=j)
        {
            temp[k]=vet[i];
            k++;
        }
    }
    free(vet);
    return temp;
}