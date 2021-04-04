#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

int pontosJogador;
int pontosComputador;

void jogo();
void imprimeItem(int item);
int verifica(int p1, int p2);

int main(){

    srand(time(NULL)); //gera numeros aleatorios diferentes

    printf("*******************************************************************************\n");
    printf("*                           PEDRA - PAPEL - TESOURA                           *\n");
    printf("*******************************************************************************\n");

    int i;
    for(i=0; i<3; i++){
        jogo();
        printf("*******************************************************************************\n");
    }

    printf(" Total de Pontos\n");
    printf("         Voce: %d \n", pontosJogador);
    printf("   Computador: %d \n", pontosComputador);
    printf("\n Obrigado por jogar!");

    system("pause>nul");
    return 0;
}


void jogo(){

    int itemJogador;
    int itemComputador;

    printf("\n Escolha 1 = Pedra 2 = Papel 3 = Tesoura \n Item: ");
    scanf("%d", &itemJogador); //jogador faz sua escolha

    itemComputador = rand()%3+1; //computador faz sua escolha

    //mostra quem escolheu oque
    printf("\n Voce -> ");
    imprimeItem(itemJogador);
    printf(" x ");
    imprimeItem(itemComputador);
    printf(" <- Computador.\n");

    //verifica quem ganhou
    int ganhador = verifica(itemJogador, itemComputador);

    //mostra o ganhador
    printf("\n");
    if(ganhador == 1){
        printf(" VOCE GANHOU!\n");
        pontosJogador++;
    }
    else if(ganhador == 2){
        printf(" COMPUTADOR GANHOU!\n");
        pontosComputador++;
    }
    else{
        printf(" EMPATOU!\n");
    }
    printf("\n");
}


void imprimeItem(int item){
    if(item == PEDRA){
        printf("PEDRA");
    }
    else if(item == PAPEL){
        printf("PAPEL");
    }
    else{
        printf("TESOURA");
    }
}


/*
    Funcao que verifica qual jogador ganhou e retorna 1 ou 2
    retorna 0 ao empatar
*/
int verifica(int p1, int p2){

    int ganhador;
    if(p1 == p2){ //empate
        ganhador = 0;
    }

    if(p1==PEDRA && p2==TESOURA){ ganhador = 1; }
    if(p1==PEDRA && p2==PAPEL){ ganhador = 2; }

    if(p1==PAPEL && p2==PEDRA){ ganhador = 1; }
    if(p1==PAPEL && p2==TESOURA){ ganhador = 2; }

    if(p1==TESOURA && p2==PAPEL){ ganhador = 1; }
    if(p1==TESOURA && p2==PEDRA){ ganhador = 2; }

    return ganhador;
}
