#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realoca(void *pont, size_t newSize)
{
    void *newEnd;
    int tam;
    tam = _msize(pont);

    newEnd = (void *)malloc(newSize);

    if (newEnd != NULL)
    {
        memcpy(newEnd, pont, tam);
        free(pont);
        return newEnd;
    }
    else
    {
        printf("Nao ha memoria livre suficiente");
        return newEnd;
    }
}


int main(){
    int *num, x, cont=1, i;

    num = (int *)malloc(sizeof(int));

    printf("Insira um numero: ");
    scanf("%d",num);
    setbuf(stdin, NULL);
    printf("Deseja inserir outro numero? (1.Sim 2.Nao): ");
    scanf("%d",&x);
    setbuf(stdin, NULL);
    while (x != 2)
    {
        cont++;
        num = (int *)realoca(num, sizeof(int) * cont);
        printf("Pois bote: ");
        scanf("%d",&num[cont-1]);
        setbuf(stdin, NULL);

        printf("Deseja inserir outro numero? (1.Sim 2.Nao): ");
        scanf("%d",&x);
        setbuf(stdin, NULL);
    }

    printf("\nOs numeros adicionados foram: ");

    for (i=0; i<cont; i++)
    {
        printf ("%d ",num[i]);
    }
    free(num);
    return(0);
}