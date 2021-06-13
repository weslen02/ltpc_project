#include <stdio.h>
#include <stdlib.h>

//"constantes"
#define TAM 10

float valorCompra = 0.0;

int main()
{
    //ponteiro para fazer alocação das strings (O nome não pode ter mais que 9 chars quando digitado)
    char *nome[TAM];
    int codigo[TAM];
    float valorVenda[TAM];
    int i=0, n=0, sair = 0;

    //contador para adicioanar dados
    for(i = 0 ; i < TAM; i++) {
        nome[i] = malloc(sizeof(char)*20); //tratando string em C
        printf("Codigo .......................#%d: ", i+1), scanf("%d", &codigo[i]);
		fflush(stdin); //limpa lixo na memória
        //não se usa o caractere & em strings em C
		printf("Nome ............................: "), scanf("%s", nome[i]);
		fflush(stdin);
		printf("Valor de compra .................: "), scanf("%f", &valorCompra);
		fflush(stdin);

		do{
            sair = 0;
            printf("\nTipos de produto = |1|2|3|4|5|6|\n");
            printf("Entre com o tipo do produto .....: "), scanf("%d", &n);
            fflush(stdin);
            //if para as condiçoes do tipo de 1-6
            if(n > 0 && n < 7){
                valorVenda[i] = tipoProd(n, valorCompra);
                sair = 1;
            } else {
                printf("\nValor do tipo invalido, entre com o valor correto!!!\n");
            }
		}while(sair != 1);
        puts("\n\n--------------------------------------------");
    }

    for(i = 0; i < TAM; i++){
        printf("|Codigo: %d| |Nome: %s| | Valor de venda: %.2f|\n", codigo[i], nome[i], valorVenda[i]);
    }


    return 0;
}

//funcao para manipulor os tipos de produtos e calculos primarios
int tipoProd (int n){
    float ipi = 0;
    float icms = 0;
    float lucro = 0.0;
    float calc = 0.0;
    switch(n)
    {
        case 1:
            ipi = (valorCompra * 0.1);
            icms = ( (valorCompra + ipi) * 0.12 );
            lucro = ( valorCompra * 0.2) * 0.05;
        break;

        case 2:
            ipi = (valorCompra * 0.12);
            icms = ( (valorCompra + ipi) * 0.15 );
            lucro = ( valorCompra * 0.25) * 0.05;
        break;

        case 3:
            ipi = (valorCompra * 0.15);
            icms = ( (valorCompra + ipi) * 0.18 );
            lucro = ( valorCompra * 0.2) * 0.05;
        break;

        case 4:
            ipi = (valorCompra * 0.2);
            icms = ( (valorCompra + ipi) * 0.12 );
            lucro = ( valorCompra * 0.25) * 0.05;
        break;

        case 5:
            ipi = (valorCompra * 0.25);
            icms = ( (valorCompra + ipi) * 0.15 );
            lucro = ( valorCompra * 0.2) * 0.05;
        break;

        case 6:
            ipi = (valorCompra * 0.3);
            icms = ( (valorCompra + ipi) * 0.18 );
            lucro = ( valorCompra * 0.25) * 0.05;
        break;
    }

    return calc = valorCompra + ipi + icms + lucro;
}
