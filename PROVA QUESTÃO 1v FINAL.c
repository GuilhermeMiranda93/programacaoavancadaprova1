#include<stdio.h>
#include <math.h>
/*O Progra permite que o usuário entre com uma sequência binária com 64 elementos
essa sequencia então será convertida em um número que, quando convertido em binário, retorna a sequência.
*/

void printchar(unsigned char c)//função para para checar se o número obtido corresponde a sequencia binária
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
    //para converter de binário para decimal
    char matriz [65];//uma string que receberá os 64 elementos;
    int i;
    unsigned char *pt;
    unsigned long long codigo=0;//O número convertido será atribuido a essa variável;
    unsigned long long a=0;
    pt=&matriz;//o ponteiro irá receber o endereço do primeiro elemento da sequencia
    printf("-----QUESTÃO 1-----\n");
    printf("Insira uma sequencia com 64 elementos (0 ou 1):\n");
    scanf("%64[^\n]", matriz);//O usuário entra com a sequencia de 64 elementos;

    //para converter de decimal em binário
    int x;
    unsigned char *pc;
    pc=&codigo;

    //scanf("%64[^\n]", matriz);
    /*for(i=0;i<65;i++)
    {
        printf("%c\n", pt[i]);
    }*/

    //Nas próximas linhas será obtido o número desejado
    for(i=0;i<64;i++)
    {/*Para que a sequência seja a mesma da digitada (da esquerda para a direita),
    o ponteiro a ponta para o endereço do ultimo elemento*/
        if((pt[63-i])=='1')//então verifica se o elemento é igual a 1
        {
            a=pow(2,i);//se for igual a 1 então obtém uma potencia de base 2, e expoente igual a posição do elemento na sequencia
            codigo=codigo+a;//a cada ciclo o valor obtido anteriormente é adicionado a váriavel que irá representará a sequencia binária
            //printf("%llu\n", a);
        }
        /*else
        printf("0\n");*/
    }
    printf("A sequencia convertida em unsigned long long é:\n");
    printf("%llu\n", codigo);//O número obitido que quando convertido em binário retorna a sequencia inicial

    /*for(i=7;i>=0;i--)
    {
        printchar(pc[i]);
        printf("|");
    }*/

    return 0;

}
