#include<stdio.h>
#include <math.h>
/*O Progra permite que o usu�rio entre com uma sequ�ncia bin�ria com 64 elementos
essa sequencia ent�o ser� convertida em um n�mero que, quando convertido em bin�rio, retorna a sequ�ncia.
*/

void printchar(unsigned char c)//fun��o para para checar se o n�mero obtido corresponde a sequencia bin�ria
{
    unsigned char bit, cont;
    bit = 128;
    for(cont =0;cont<8;cont++)
    {
        if((c&bit)>0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        bit=bit/2;
    }
}

int main ()
{
    //para converter de bin�rio para decimal
    char matriz [65];//uma string que receber� os 64 elementos;
    int i;
    unsigned char *pt;
    unsigned long long codigo=0;//O n�mero convertido ser� atribuido a essa vari�vel;
    unsigned long long a=0;
    pt=&matriz;//o ponteiro ir� receber o endere�o do primeiro elemento da sequencia
    printf("-----QUEST�O 1-----\n");
    printf("Insira uma sequencia com 64 elementos (0 ou 1):\n");
    scanf("%64[^\n]", matriz);//O usu�rio entra com a sequencia de 64 elementos;

    //para converter de decimal em bin�rio
    int x;
    unsigned char *pc;
    pc=&codigo;

    //scanf("%64[^\n]", matriz);
    /*for(i=0;i<65;i++)
    {
        printf("%c\n", pt[i]);
    }*/

    //Nas pr�ximas linhas ser� obtido o n�mero desejado
    for(i=0;i<64;i++)
    {/*Para que a sequ�ncia seja a mesma da digitada (da esquerda para a direita),
    o ponteiro a ponta para o endere�o do ultimo elemento*/
        if((pt[63-i])=='1')//ent�o verifica se o elemento � igual a 1
        {
            a=pow(2,i);//se for igual a 1 ent�o obt�m uma potencia de base 2, e expoente igual a posi��o do elemento na sequencia
            codigo=codigo+a;//a cada ciclo o valor obtido anteriormente � adicionado a v�riavel que ir� representar� a sequencia bin�ria
            //printf("%llu\n", a);
        }
        /*else
        printf("0\n");*/
    }
    printf("A sequencia convertida em unsigned long long �:\n");
    printf("%llu\n", codigo);//O n�mero obitido que quando convertido em bin�rio retorna a sequencia inicial

    /*for(i=7;i>=0;i--)
    {
        printchar(pc[i]);
        printf("|");
    }*/

    return 0;

}
