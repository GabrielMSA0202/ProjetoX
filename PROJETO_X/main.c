#include <stdio.h>
#include "Projeto_x.h"

p_login projetox[MAX] = {NULL};
int main(void) {
    int Escolha = 0;
    int Posicao = 0;

    do {
        Escolha = 0;
        printf("\n---------------TELA INICIAL---------------\n");
        printf("|1 - FAZER CADASTRO\n");
        printf("|2 - LOGIN\n");
        printf("|3 - PROCURAR MEMBRO\n");
        printf("|4 - LISTAR TODOS OS MEMBROS\n");
        printf("|9 - SAIR\n");
        printf("|Digite sua opcao: ");
        scanf("%d", &Escolha);
        fflush(stdin);

        switch (Escolha) {
            case 1:
                CadastrarMembro(Posicao);
                Posicao++;
                break;
            case 2:
                break;
            case 3:
                printf("----------------ENCONTRAR MEMBRO---------------\n");
                printf("|Digite a matricula do membro: ");
                scanf("%d",&Posicao);
                getchar();
                if (Posicao <= 0 || Posicao > 100){
                    fflush(stdin);
                    printf("|Matricula invalida!\n");
                    printf("------------------------------------------------\n\n");
                    Posicao = 0;
                    break;
                }
                ListarMembroUnico(Posicao);
                break;
            case 4:
                ListarMembros(Posicao);
                break;
            case 9:
                break;
            default:
                printf("|Opcao invalida. Escolha novamente.\n");
                printf("|Digite sua opcao: ");
        }
    } while (Escolha != 9);
    return 0;
}
