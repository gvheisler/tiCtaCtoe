#include <stdio.h>
#include <stdbool.h>

#define TAM 3
#define TAB TAM*TAM

#define X 88
#define O 79
int tabuleiro[TAB];
int vez = X;
int vezIn = 0;
bool fim = 0;

void printM(){
    for(int i = 0; i<TAB; i++){
        if(i%3==0&&i!=0){
            printf("\n\n");
        }
        printf("\t[%c]", tabuleiro[i]);
    }
    printf("\n\n");
}

void preencheM(){
    for(int i = 0; i<TAB; i++){
        tabuleiro[i]=126;
    }
}

void printVez(){
    printf("\n");
    if(vez == X){
        printf("Vez do jogador X.\n------------------------------\n");
    }
    else{
        printf("Vez do jogador O.\n------------------------------\n");
    }
}

void pegaJogada(){
    int jogada = -1;
    bool posInv = 0;
    do{
        printf("Insira sua jogada [0-8]: ");
        scanf("%d", &jogada);
        if(jogada>=TAB||jogada<0||tabuleiro[jogada]!=126){
            printf("Posicao invalida! Jogue novamente!\n");
            posInv = 1;
        }else{
            posInv = 0;
        }
    }while(posInv);
    tabuleiro[jogada]=vez;
    if(vez==X){
        vez = O;
    }else{
        vez = X;
    }
}

printMatNum(){
    printf("\n\t------------------\n\tTabuleiro do jogo:\n\n");
    for(int i = 0; i<TAB; i++){
        if(i%3==0&&i!=0){
            printf("\n\n");
        }
        printf("\t[%d]", i);
    }
    printf("\n\n\n------------------------------\n");

}

void checaVitoria(){
    if(tabuleiro[0]==X&&tabuleiro[1]==X&&tabuleiro[2]==X
       ||tabuleiro[3]==X&&tabuleiro[4]==X&&tabuleiro[5]==X
       ||tabuleiro[6]==X&&tabuleiro[7]==X&&tabuleiro[8]==X
       ||tabuleiro[0]==X&&tabuleiro[4]==X&&tabuleiro[8]==X
       ||tabuleiro[2]==X&&tabuleiro[4]==X&&tabuleiro[6]==X
       ||tabuleiro[0]==X&&tabuleiro[3]==X&&tabuleiro[6]==X
       ||tabuleiro[1]==X&&tabuleiro[4]==X&&tabuleiro[7]==X
       ||tabuleiro[2]==X&&tabuleiro[5]==X&&tabuleiro[8]==X){

        printf("Vitoria de %c!\n", X);
        fimJogo();
    }
    if(tabuleiro[0]==O&&tabuleiro[1]==O&&tabuleiro[2]==O
       ||tabuleiro[3]==O&&tabuleiro[4]==O&&tabuleiro[5]==O
       ||tabuleiro[6]==O&&tabuleiro[7]==O&&tabuleiro[8]==O
       ||tabuleiro[0]==O&&tabuleiro[4]==O&&tabuleiro[8]==O
       ||tabuleiro[2]==O&&tabuleiro[4]==O&&tabuleiro[6]==O
       ||tabuleiro[0]==O&&tabuleiro[3]==O&&tabuleiro[6]==O
       ||tabuleiro[1]==O&&tabuleiro[4]==O&&tabuleiro[7]==O
       ||tabuleiro[2]==O&&tabuleiro[5]==O&&tabuleiro[8]==O){

        printf("Vitoria de %c!\n", O);
        fimJogo();
    }
}

void fimJogo(){
    bool opcao;
    do{
        printf("\nDeseja reiniciar o jogo? [Sim -> 1][Nao -> 0]");
        scanf("%d", &opcao);
    }while(opcao!=1&&opcao!=0);
    if(opcao==1){
        reiniciaJogo();
    }else{
        printf("Obrigado por jogar!\n");
        fim = 1;
    }
}

void reiniciaJogo(){
    if(vezIn==0){
        vez = O;
        vezIn = 1;
    }else{
        vez = X;
        vezIn = 0;
    }
    preencheM();
    if(vez == X){
        printM();
    }
}

void pegaJogadaPlayer(){
    int jogada = -1;
    bool posInv = 0;
    do{
        printf("Insira sua jogada [0-8]: ");
        scanf("%d", &jogada);
        if(jogada>=TAB||jogada<0||tabuleiro[jogada]!=126){
            printf("Posicao invalida! Jogue novamente!\n");
            posInv = 1;
        }else{
            posInv = 0;
        }
    }while(posInv);
    tabuleiro[jogada]=X;
}


void pegaJogadaMaquina(){
    int jogada = -1;
    bool posInv = 0;
    do{
        jogada = (rand() % 9);
        if(jogada>=TAB||jogada<0||tabuleiro[jogada]!=126){
            posInv = 1;
        }else{
            posInv = 0;
        }
    }while(posInv);
    tabuleiro[jogada]=O;
}

int main(){
    preencheM();
    srand(time(NULL));
    bool modo;
    do{
        printf("\tEscolha o modo de jogo!: \n\t[0]Player vs Player | [1]Player vs IA\n");
        scanf("%d", &modo);
        if(modo!=1&&modo!=0){
            printf("Modo inexistente!\n");
        }
    }while(modo!=1&&modo!=0);

    if(modo == 0){
        while(!fim){
            system("cls");
            printMatNum();
            printVez();
            printM();
            pegaJogada();
            checaVitoria();
        }
    }else{
        while(!fim){
            system("cls");
            printMatNum();
            checaVitoria();
            if(vez == X){
                printM();
                pegaJogadaPlayer();
                pegaJogadaMaquina();
            }else{
                pegaJogadaMaquina();
                printM();
                pegaJogadaPlayer();
            }
        }
    }
}
