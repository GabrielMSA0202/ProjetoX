#include "Projeto_x.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void inicializa(){
    for (int i = 0; i < MAX; ++i) {
        projetox[i] = NULL;
        projetox[i]->Matricula = 0;
    }
}


void CadastrarMembro(int pos){
    char *p_Email;
    if (projetox[pos] == NULL){
        projetox[pos] = (p_login) malloc(sizeof(login));
    }
    printf("----------------CADASTRO DE MEMBRO-----------------\n");
    printf("|Preencha os dados para cadastro.\n");

    printf("|Nome:");
    fgets(projetox[pos]->Nome, sizeof(projetox[pos]->Nome), stdin);

    printf("|Idade:");
    scanf("%d", &projetox[pos]->Idade);
    getchar();
    if (projetox[pos]->Idade <= 0 || projetox[pos]->Idade > 120){
        printf("|IDADE INVALIDA!\n");
        projetox[pos] = NULL;
        return;
    }
    if (projetox[pos]->Idade <= 18 || projetox[pos]->Idade > 99){
        printf("|Idade imprópia para cadastro!\n");
        projetox[pos] = NULL;
        return;
    }

    int VerificadorEmail = 0;
    int VerificadorEmail2 = 0;
    int VerificadorEmail3 = 0;
    do {
        VerificadorEmail = 1;
        VerificadorEmail2 = 0;
        VerificadorEmail3 = 0;

        printf("|E-mail:");
        fgets(projetox[pos]->Email, sizeof(projetox[pos]->Email), stdin);
        projetox[pos]->Email[strcspn(projetox[pos]->Email, "\n")] = '\0'; // remove o \n do fgets

        p_Email = projetox[pos]->Email;

        do {
            if (*p_Email == ' ') {
                printf("|EMAIL INVALIDO!\n");
                VerificadorEmail = -1;
            }
            if (*p_Email == '@') {
                VerificadorEmail2 = 1;
            }
            if (*p_Email == '.'){
                VerificadorEmail3 = 1;
            }
            p_Email++;
        } while (*p_Email != '\0');
        if (VerificadorEmail2 != 1){
            printf("|EMAIL INVALIDO!\n");
        }else if (VerificadorEmail3 != 1){
            printf("|EMAIL INVALIDO!\n");
        }

    } while (VerificadorEmail == - 1 || VerificadorEmail2 == 0 || VerificadorEmail3 == 0);
    printf("|EMAIL REGISTRADO COM SUCESSO!\n");

    printf("|Crie uma senha:");
    fgets(projetox[pos]->Senha, sizeof(projetox[pos]->Senha), stdin);

    do {
        printf("|Confirmar senha:");
        fgets(projetox[pos]->VerificacaoDeSenha, sizeof(projetox[pos]->VerificacaoDeSenha), stdin);
        if(strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0){
            printf("|SENHAS NAO CONFEREM!\n");
        }
    } while (strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0); // compara as duas strings

    printf("|CADASTRO REALIZADO COM SUCESSO!\n");

    projetox[pos]->Matricula = (rand() % 100) + 1;
    for (int i = 0; i < MAX; ++i) {
        if (projetox[pos]->Matricula == projetox[i]->Matricula){
            projetox[pos]->Matricula = (rand() % 100) + 1;
            break;
        }

    }
    printf("|Numero de matricula: %d\n", projetox[pos]->Matricula);

    printf("|-----------------BEM VINDO AO CLUBE!---------------\n\n\n");

}


void LoginMembro(int pos){

}


void ListarMembroUnico(int pos){
    for (int i = 0; i < 100; ++i) {
        if (projetox[i] != NULL && projetox[i]->Matricula == pos){
            printf("\n");
            printf("*------------------DADOS DO MEMBRO---------------------*\n");
            printf("|NOME: %s", projetox[i]->Nome);
            printf("|IDADE: %d\n", projetox[i]->Idade);
            printf("|E-MAIL: %s\n", projetox[i]->Email);
            printf("|MATRICULA: %d\n", projetox[i]->Matricula);
            printf("--------------------------------------------------------\n\n");
            return;
        }

    }
    printf("|MATRICULA NAO ENCONTRADA!\n");
    printf("---------------------------------------------------------\n\n\n");
}


void ListarMembros(int pos){
    int Contador = 0;

    printf("\n********************************************************\n");
    printf("*                                                      *\n");
    printf("*----------------MEMBROS CADASTRADOS-------------------*\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");

    for (int i = 0; i < MAX; ++i) {
        if (projetox[i] != NULL){
            pos = projetox[i]->Matricula;
            ListarMembroUnico(pos);
            Contador++;
        }
    }
    printf("|TOTAL DE MEMBROS CADASTRADOS: %d", Contador);
    printf("\n---------------------------------------------------------\n");
}


void AlterarDados(int pos){
    int opcao;
    int Verificador;
    printf("----------------------ALTERAR DADO---------------------\n");
    printf("|Digite a matricula do membro para alterar: ");
    scanf("%d", &pos);
    getchar();
    if (pos < 1 || pos > 100){
        printf("|MATRICULA INVALIDA!\n");
        printf("---------------------------------------------------------\n");
        return;
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (pos == projetox[j]->Matricula) {
                Verificador = j;
                i = MAX;
                j = MAX;
                printf("|MATRICULA ENCONTRADA\n");
            }
        }
        if (pos != projetox[Verificador]->Matricula) {
            printf("|MATRICULA NAO ENCONTRADA!\n");
            return;
        }
    }

    printf("| 1 - NOME\n");
    printf("| 2 - IDADE\n");
    printf("| 3 - E-MAIL\n");
    printf("| 4 - SENHA\n");
    printf("| 5 - SAIR\n");
    printf("| Digite: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
        case 1:
            printf("|NOME: %s\n", projetox[Verificador]->Nome);
            printf("|NOME DELETADO!\n");
            printf("|Digite o nome:");
            fgets(projetox[Verificador]->Nome, sizeof(projetox[Verificador]->Nome), stdin);
            printf("|NOME ALTERADO!\n");
            printf("|NOME: %s\n", projetox[Verificador]->Nome);
            printf("---------------------------------------------------------\n");
            break;
        case 2:
            printf("|IDADe: %d\n", projetox[Verificador]->Idade);
            printf("|IDADE DELETADA!\n");
            printf("|Digite idade:");
            scanf("%d", &projetox[Verificador]->Idade);
            getchar();
            printf("|IDADE ALTERADA!\n");
            printf("|IDADE: %d\n", projetox[Verificador]->Idade);
            printf("---------------------------------------------------------\n");
            break;
        case 3:
            printf("|E-MAIL: %s\n", projetox[Verificador]->Email);
            printf("|E-MAIL DELETADO!\n");
            printf("|Digite o e-mail:");
            fgets(projetox[Verificador]->Email, sizeof(projetox[Verificador]->Email), stdin);
            printf("|E-MAIL ALTERADO!\n");
            printf("|E-MAIL: %s\n", projetox[Verificador]->Email);
            printf("---------------------------------------------------------\n");
            break;
        case 4:
            printf("|SENHA: %s\n", projetox[Verificador]->Senha);
            printf("|SENHA DELETADA!\n");
            printf("|Digite a senha:");
            fgets(projetox[Verificador]->Senha, sizeof(projetox[Verificador]->Senha), stdin);
            do {
                printf("|Confirmar senha:");
                fgets(projetox[Verificador]->VerificacaoDeSenha, sizeof(projetox[Verificador]->VerificacaoDeSenha), stdin);
                if(strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0){
                    printf("|SENHAS NAO CONFEREM!\n");
                }
            } while (strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0);
            printf("|SENHA ALTERADA!\n");
            printf("|SENHA: %s\n", projetox[Verificador]->Senha);
            printf("---------------------------------------------------------\n");
            break;
        case 5:
            printf("---------------------------------------------------------\n");
            return;
            break;
        default:
            printf("|Opcao invalida!\n");
    }
}

void ExcluirCadastro(int pos){
    printf("----------------------EXCLUIR MEMRBO---------------------\n");
    printf("|Digite a matricula do membro para excluir: ");
    scanf("%d", &pos);
    getchar();
    if (pos < 1 || pos > 100){
        printf("|MATRICULA INVALIDA!\n");
        printf("---------------------------------------------------------\n");
        return;
    }
    for (int i = 0; i < MAX; ++i) {
        if (projetox[i] != NULL){
            ListarMembroUnico(pos);
            printf("|CADASTRO EXCLUIDO COM SUCESSO!\n");
            printf("---------------------------------------------------------\n");
            projetox[i] = NULL;
            return;
        }
    }
    printf("|MATRICULA JA ESTA VAZIA!\n");
    printf("---------------------------------------------------------\n");
    return;
}