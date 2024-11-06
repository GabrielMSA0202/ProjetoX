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

    printf("|Email:");
    fgets(projetox[pos]->Email, sizeof(projetox[pos]->Email), stdin);

    printf("|Crie uma senha:");
    fgets(projetox[pos]->Senha, sizeof(projetox[pos]->Senha), stdin);

    do {
        printf("|Confirmar senha:");
        fgets(projetox[pos]->VerificacaoDeSenha, sizeof(projetox[pos]->VerificacaoDeSenha), stdin);
        if(strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0){
            printf("|SENHAS NAO CONFEREM!\n");
        }
    } while (strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0);

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
            printf("********************************************************\n");
            printf("*                                                      *\n");
            printf("*------------------DADOS DO MEMBRO---------------------*\n");
            printf("*                                                      *\n");
            printf("********************************************************\n");
            printf("|NOME: %s", projetox[i]->Nome);
            printf("|IDADE: %d\n", projetox[i]->Idade);
            printf("|EMAIL: %s", projetox[i]->Email);
            printf("|MATRICULA: %d\n", projetox[i]->Matricula);
            printf("---------------------------------------------------------\n\n\n");
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
            ListarMembroUnico(i);
            Contador++;
        }
    }
    printf("|TOTAL DE MEMBROS CADASTRADOS: %d", Contador);
    printf("\n---------------------------------------------------------\n");
}


void AlterarDados(int pos){

}