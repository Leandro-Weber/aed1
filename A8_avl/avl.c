#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Registro {
int chave;
} Registro;


typedef struct Noh {
Registro Reg;
struct Noh *pEsq, *pDir;
} No;

int FB (No* pRaiz);
int Altura(No* pRaiz);
void RSE(No** ppRaiz);
void RSD(No** ppRaiz);
int BalancaEsquerda(No** ppRaiz);
int BalancaDireita(No** ppRaiz);
int Balanceamento(No** ppRaiz);
int Insere(No** ppRaiz,int x);
int EhArvoreArvl(No* pRaiz);
void desaloca(No* pRaiz);

int main()
{
    int n, i,x,
    caso1a[]={20,4,15},
    caso2a[]={20,4,26,3,9,15},
    caso3a[]={20,4,26,3,9,21,30,2,7,11,15},
    caso1b[]={20,4,8},
    caso2b[]={20,4,26,3,9,8},
    caso3b[]={20,4,26,3,9,21,30,2,7,11,8};
    No** ppRaiz;

    ppRaiz=(No**)malloc(sizeof(No));
    *ppRaiz=NULL;

    if(ppRaiz==NULL)
    {
        printf("Erro! Nao ha memoria suficiente.");
        exit(0);
    }

    srand(time(0));

    printf("\n----------Arvore com numeros aleatorios----------\n\n");
    printf("Quantos numeros? ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        x=rand();
        Insere(ppRaiz, x);
        //printf("%d ", x);
    }


    if(EhArvoreArvl(*ppRaiz))
        printf("a arvore com numeros aleatorios eh avl");
    else
        printf("a arvore com numeros aleatorios nao eh avl");
    
    desaloca(*ppRaiz);
    *ppRaiz=NULL;
    
    printf("\n----------Arvore com numeros do caso 1a do stackoverflow----------\n\n");

    for(i=0; i<3; i++)
    {
        Insere(ppRaiz, caso1a[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4 e 15: ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    *ppRaiz=NULL;
    
    printf("\n----------Arvore com numeros do caso 2a do stackoverflow----------\n\n");
    for(i=0; i<5; i++)
    {
        Insere(ppRaiz, caso2a[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4, 26, 3, 9 e 15: ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    *ppRaiz=NULL;

    printf("\n----------Arvore com numeros do caso 3a do stackoverflow----------\n\n");
    for(i=0; i<10; i++)
    {
        Insere(ppRaiz, caso3a[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4, 26, 3, 9 , 21, 30, 2, 7, 11 e 15: ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    *ppRaiz=NULL;

    printf("\n----------Arvore com numeros do caso 1b do stackoverflow----------\n\n");
    for(i=0; i<3; i++)
    {
        Insere(ppRaiz, caso1b[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4 e 8 : ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    *ppRaiz=NULL;

    printf("\n----------Arvore com numeros do caso 2b do stackoverflow----------\n\n");
    for(i=0; i<5; i++)
    {
        Insere(ppRaiz, caso2b[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4, 26, 3, 9 e 8 : ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    *ppRaiz=NULL;

    printf("\n----------Arvore com numeros do caso 3b do stackoverflow----------\n\n");
    for(i=0; i<10; i++)
    {
        Insere(ppRaiz, caso3b[i]);
    }
    printf("Teste apos  inserir os numeros 20, 4, 26, 3, 9, 21, 30, 2, 7, 11 e 8 : ");
    if(EhArvoreArvl(*ppRaiz))
        printf("Eh avl\n");
    else
        printf("Nao eh avl\n");

    desaloca(*ppRaiz);
    free(ppRaiz);

return 0;
}



int FB (No* pRaiz)
{
    if (pRaiz == NULL)
        return 0;
    return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}


int Altura(No* pRaiz)
{
    int iEsq,iDir;
    if (pRaiz == NULL)
        return 0;

    iEsq = Altura(pRaiz->pEsq);
    iDir = Altura(pRaiz->pDir);
    if ( iEsq > iDir )
        return iEsq + 1;
    else
        return iDir + 1;
}


void RSE(No** ppRaiz)
{
    No *pAux;

    pAux = (*ppRaiz)->pDir;

    (*ppRaiz)->pDir = pAux->pEsq;

    pAux->pEsq = (*ppRaiz);

    (*ppRaiz) = pAux;
}


void RSD(No** ppRaiz)
{
    No *pAux;

    pAux = (*ppRaiz)->pEsq;

    (*ppRaiz)->pEsq = pAux->pDir;

    pAux->pDir = (*ppRaiz);

    (*ppRaiz) = pAux;
}


int BalancaEsquerda(No** ppRaiz)
{
    int fbe = FB ( (*ppRaiz)->pEsq );

    if ( fbe > 0 )
    {
        RSD(ppRaiz);
        return 1;
    }
    else if (fbe < 0 )
    { /* Rotação Dupla Direita */
        RSE( &((*ppRaiz)->pEsq) );
        RSD( ppRaiz ); /* &(*ppRaiz) */
        return 1;
    }
    return 0;
}


int BalancaDireita(No** ppRaiz)
{
    int fbd = FB( (*ppRaiz)->pDir);

    if ( fbd < 0 )
    {
        RSE (ppRaiz);
        return 1;
    }
    else if (fbd > 0 )
    { /* Rotação Dupla Esquerda */
        RSD( &((*ppRaiz)->pDir) );
        RSE( ppRaiz ); /* &(*ppRaiz) */
        return 1;
    }
    return 0;
}

int Balanceamento(No** ppRaiz)
{
    int fb = FB(*ppRaiz);
    if ( fb > 1)
        return BalancaEsquerda(ppRaiz);
    else if (fb < -1 )
        return BalancaDireita(ppRaiz);
    else
        return 0;
}

int Insere(No** ppRaiz, int x)
{
    if (*ppRaiz == NULL)
    {
        *ppRaiz = (No*)malloc(sizeof(No));
        if(*ppRaiz==NULL)                                               //teste para ver se há memória suficiente
        {
            printf("nao ha memoria suficiente. Encerrando programa.");
            exit(0);
        }
        (*ppRaiz)->Reg.chave = x;
        (*ppRaiz)->pEsq = NULL;
        (*ppRaiz)->pDir = NULL;
        return 1;
    }
    else if ( (*ppRaiz)->Reg.chave > x )
    {
        if ( Insere(&(*ppRaiz)->pEsq , x) )
        {
            if (Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
        {
                return 0;
        }
        
    }
    else if ( (*ppRaiz)->Reg.chave < x )
    {
        if ( Insere(&(*ppRaiz)->pDir , x) )
        {
            if (Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
        return 0; /* valor jah presente */
}

int EhArvoreArvl(No* pRaiz)
{
    int fb;
    if (pRaiz == NULL)
        return 1;
    if (!EhArvoreArvl(pRaiz->pEsq))
        return 0;
    if (!EhArvoreArvl(pRaiz->pDir))
        return 0;
    fb = FB (pRaiz);
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

void desaloca(No* pRaiz)
{
    if (pRaiz == NULL)
        return;

    desaloca(pRaiz->pEsq);
    desaloca(pRaiz->pDir);
    free(pRaiz);
}