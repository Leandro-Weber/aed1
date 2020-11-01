#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char linha[80], *tkn;
    int i;

    printf("Digite sua frase: ");
    scanf("%[^\n]",linha);
    
    tkn = strtok(linha," ");

    printf("\n");

    while(tkn != NULL)
    {
        printf("%s\n", tkn);
        tkn=strtok(NULL," ");
    }

    return 0;
}