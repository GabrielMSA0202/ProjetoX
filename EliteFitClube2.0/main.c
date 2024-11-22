#include <stdio.h>
#include "ClubeEsportivo.h"

p_ADM administrador[MAX] = {NULL};
p_login projetox[MAX] = {NULL};
int main(void) {
    int Escolha = 0;
    int Posicao = 0;
    int PosicaoADM = 0;
    int Membro;
    Posicao = inicializa(Posicao);
    PosicaoADM = inicializaADM(PosicaoADM);
    do {
        Escolha = 0;
        printf("\n---------------TELA INICIAL---------------\n");
        printf("|1 - FAZER CADASTRO\n");
        printf("|2 - LOGIN\n");
        printf("|3 - SOBRE NOS\n");
        printf("|4 - SAIR\n");
        printf("|Digite sua opcao: ");
        scanf("%d", &Escolha);
        getchar();

        switch (Escolha) {
            case 1:
                CadastrarMembro(Posicao);
                if (projetox[Posicao] != NULL) {
                    Posicao++;
                }
                break;
            case 2:
                Login(Posicao, PosicaoADM);
                break;
            case 3:
                SobreNos();
            case 4:
                break;
            default:
                printf("|Opcao invalida. Escolha novamente.\n");
                printf("|Digite sua opcao: ");
        }
    } while (Escolha != 4);
    return 0;
}
