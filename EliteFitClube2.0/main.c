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
        printf("\n\t\t\t\t\t\t\t___________________________________________\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|               TELA INICIAL              |\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|1 - FAZER CADASTRO                       |\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|2 - LOGIN                                |\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|3 - SOBRE NOS                            |\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|4 - SAIR                                 |\n");
        printf("\t\t\t\t\t\t\t|                                         |\n");
        printf("\t\t\t\t\t\t\t|Digite sua opcao: ");
        scanf("%d", &Escolha);
        getchar();

        switch (Escolha) {
            case 1:
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n\n");
                CadastrarMembro(Posicao);
                Posicao++;
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n\n");
                Login(Posicao, PosicaoADM);
                break;
            case 3:
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n\n");
                SobreNos();
                break;
            case 4:
                printf("\n\t\t\t\t\t\t\t|  :(                                     |\n");
                printf("\t\t\t\t\t\t\t|_________________________________________|\n\n\n");
                break;
            default:
                printf("\n\t\t\t\t\t\t\t|Opcao invalida. Escolha novamente.\n");
                printf("\t\t\t\t\t\t\t|_________________________________________|\n\n\n");
        }
    } while (Escolha != 4);
    return 0;
}
