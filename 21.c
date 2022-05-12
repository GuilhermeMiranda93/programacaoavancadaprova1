#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
Considra��es iniciais:
1#O elipsoide cetrando numa matriz seguir� a formula (x-a)^2/a^2+(y-b)^2/b^2+z^2/c^2=1;
2#Toma-se a = 4 e b = 4 e c=9;
3#Para obter as curvas de linha ou cortes dado um z usa-se: (x-4)^2/4^2+(y-4)^2/b^4=1-z^2/9^2;
4#Se (x-4)^2/4^2+(y-4)^2/b^4 <= 1-z^2/9^2 ent�o ser� parte do interior da elipse e atribui 1, se n�o � exterior e atribui 0;
*/
int main()
{
    char ****matriz;
    int i,z,m1,m2,m3,j,m;
    float x, y,count=0,Z=0;
    //aloca��o din�mica
    //ser�o 9 planos, cada plano � uma matriz, os valores atribuidos a 'a' e 'b' indicam q essa matriz seria no max 8x8, para aumentar a precis�o (0,25) faz obtem-se uma matriz 24*24, essa matriz receber� 0 e 1's dependendo da express�o de compara��o em 4
    /*um array de 9 ponteiros, cada um aponta para um outro array de 8 ponteiros,
    cada um desses arrays apontam para um outro array de 4 ponteiros
    e cada um desses ponteiros apontam para um array de 32 char q pode ser 0 ou 1.*/
    //int a=8,b=8,c=9;

    matriz = malloc(91*sizeof(char***));

    if(matriz==NULL)
    {
        fprintf(stderr, "Out of memory");
        exit(0);
    }

    for(i=0;i<91;i++)
    {
        matriz[i] = malloc(8*sizeof(char**));
        if(matriz[i]==NULL)
        {
            fprintf(stderr, "Out of memory");
            exit(0);
        }
        for(j=0;j<8;j++)
        {
            matriz[i][j]=malloc(10*sizeof(char*));
            if(matriz[i][j]==NULL)
            {
                fprintf(stderr, "Out of memory");
                exit(0);
            }
            for(m=0;m<10;m++)
            {
                matriz[i][j][m]=malloc(80*sizeof(char));
                if(matriz[i][j][m]==NULL)
                {
                    fprintf(stderr, "Out of memory");
                    exit(0);
                }
            }
        }
    }

    //atribui��o dos 0 e 1

    for(z=0;z<91;z++)
    {
        for(m1=0;m1<8;m1++)
        {
                m2=0;
                count=0;
                for(x=m1;count<1;x+=0.1)
                {
                    count+=0.1;
                    m3=0;
                    if(m2<10)
                    {
                        for(y=0;y<8;y+=0.1)
                        {
                            if((pow(x-4.0,2.0)/16.0+pow(y-4.0,2.0)/16.0)<(1.0-(pow(Z,2.0)/81.0)))
                                matriz[z][m1][m2][m3]='1';
                            else
                                matriz[z][m1][m2][m3]='0';
                            m3+=1;//assegura a mudan�a em m3, come�a com 0 e vai at� 32
                        }
                        m2+=1;
                    }
                }
            }
            Z+=0.1;
        }

printf("------QUEST�O 2------\n");
printf("O presente elipsoide tem raio em x=4 em y=4 e em z=9\n");
printf("Para obter uma proje��o no plano XY, digite um valor para z, tal que z varia de -90 a +90, e que z/10 representa o valor real de z.\n");
scanf("%d", &z);
if(z<0)
{
   z=z*(-1);
}
if(z>=0)
{
     for(m1=0;m1<8;m1++)
    {
        for(m2=0;m2<10;m2++)
        {
            for(m3=0;m3<80;m3++)
            {
                printf("%c ", matriz[z][m1][m2][m3]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

/*
Imprime todas as elipses
Z=0;
for(z=0;z<91;z++)
{
    printf("%f e %d\n", Z,z);
    for(m1=0;m1<8;m1++)
    {
        for(m2=0;m2<10;m2++)
        {
            for(m3=0;m3<80;m3++)
            {
                printf("%c ", matriz[z][m1][m2][m3]);
            }
            printf("\n");
        }
    }
    //system("cls");
    printf("\n");
Z+=0.1;
}
*/

//desaloca
    for(i=0;i<91;i++)
    {
        for(j=0;j<8;j++)
        {
            for(m=0;m<4;m++)
            {
                free(matriz[i][j][m]);
            }
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

