#include "ClubeEsportivo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


void CadastrarMembro(int pos);
void Login(int pos, int posADM);
void ListarMembroUnico(int pos);
void ListarMembros(int pos);
void AlterarDados(int pos);
void ExcluirCadastro(int pos);
void TermoResponsabilidade(int pos);
void SobreNos();
void CadastrarADM(int pos);
void ListarFuncionarios(int pos);
void AtualizarArquivo(int pos);

int inicializa(int pos){
    typedef struct Membro{
        int Matricula;
        char Nome[81];
        int Idade;
        char CPF[12];
        char Email[51];
        char Senha[51];
        int Advertencia;
        float Pendencia;
    } Membro;
    for (int i = 0; i < MAX; ++i) {
        projetox[i] = NULL;

    }
    char linha[256];
    FILE *p_projeto = fopen("projeto.txt", "r");
    if (p_projeto == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    while (pos < MAX && fgets(linha, sizeof(linha), p_projeto) != NULL) {
        if (sscanf (linha, "Nome: %[^;];Idade: %i;CPF: %11[^;];Email: %[^;];Matricula: %d;Senha: %[^;];Advertencias: %i;Pendencia: %f\n",
            projetox[pos]->Nome,
            &projetox[pos]->Idade,
            projetox[pos]->CPF,
            projetox[pos]->Email,
            &projetox[pos]->Matricula,
            projetox[pos]-> Senha,
            &projetox[pos]->Advertencias,
            &projetox[pos]->Pendencia) != EOF) {
            pos++;
        }
    }
    fclose(p_projeto);

    return pos;

}
int inicializaADM(int pos){
    typedef struct ADM{
        char Nome[81];
        char CPF[12];
        char Senha[51];
    } ADM;
    FILE *p_admin = fopen("ADM.txt", "r");
    if (p_admin == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    for (int i = 0; i < MAX; ++i) {
        administrador[i] = malloc(sizeof(ADM));
        if (administrador[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return -1;
        }
    }
    char linha[256];
    while (pos < MAX && fgets(linha, sizeof(linha), p_admin) != NULL){
        if (sscanf(linha, "Nome: %[^;];CPF: %11[^;];Senha: %[^;]\n",
                   administrador[pos]->Nome,
                   administrador[pos]->CPF,
                   administrador[pos]->Senha) != EOF){
            pos ++;
        }
    }
    fclose(p_admin);
    return pos;
}


void CadastrarMembro(int pos){
    FILE *p_projeto = fopen("projeto.txt", "a");
    if (p_projeto == NULL) {
        printf("|Erro ao abrir o arquivo para gravar os dados.\n");
        return;
    }
    char *p_Email;
    char *p_Nome;


    if (projetox[pos] == NULL){
        projetox[pos] = (p_login) malloc(sizeof(login));
    }else {
        printf("Vetor ja com matricula!\n");
    }
    printf("----------------CADASTRO DE MEMBRO-----------------\n");
    printf("|Preencha os dados para cadastro.\n");

    printf("|Nome completo:");
    fgets(projetox[pos]->Nome, sizeof(projetox[pos]->Nome), stdin);
    projetox[pos]->Nome[strcspn(projetox[pos]->Nome, "\n")] = '\0';
    p_Nome = projetox[pos]->Nome;
    for (int i = 0; i < strlen(projetox[pos]->Nome); ++i) {
        if (*p_Nome == '1' || *p_Nome == '2' || *p_Nome == '3' || *p_Nome == '4' || *p_Nome == '5' || *p_Nome == '6'
            ||*p_Nome == '7' || *p_Nome == '8' || *p_Nome == '9'){
            printf("|Nome invalido!\n");
            printf("|Encerrando......\n\n");
            projetox[pos] = NULL;
        return;
        }
        p_Nome++;
    }


    printf("|Idade:");
    scanf("%d", &projetox[pos]->Idade);
    getchar();

    if (projetox[pos]->Idade <= 0 || projetox[pos]->Idade > 120){
        printf("|IDADE INVALIDA!\n");
        projetox[pos] = NULL;
        return;
    }
    if (projetox[pos]->Idade < 18 || projetox[pos]->Idade > 90){
        printf("|Idade imprópia para cadastro!\n");
        projetox[pos] = NULL;
        return;
    }


    int ContadorCPF;
    int VerificacaoCPF;
    char *Verificador_CPF_Igual;
    do {
        ContadorCPF = 0;
        VerificacaoCPF = 1;
        printf("|CPF:");
        fgets(projetox[pos]->CPF, sizeof(projetox[pos]->CPF), stdin);
        projetox[pos]->CPF[strcspn(projetox[pos]->CPF, "\n")] = '\0';
        Verificador_CPF_Igual = projetox[pos]->CPF;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(projetox[i]->CPF, Verificador_CPF_Igual)==0) {
                printf("|CPF JA CADASTRADO!\n");
                printf("|Encerrando.........\n\n");
                projetox[pos] = NULL;
                return;
            }

        }
        ContadorCPF = strlen(projetox[pos]->CPF);

        if (ContadorCPF == 11){
            for (int i = 0; i < ContadorCPF; ++i) {
                if (projetox[pos]->CPF[i] < '0' || projetox[pos]->CPF[i] > '9'){
                    printf("|CPF invalido!\n");
                    VerificacaoCPF = 0;
                    break;
                }
            }
        }else {
            printf("|CPF invalido!\n");
            VerificacaoCPF = 0;
        }
    } while (VerificacaoCPF != 1);

    char *Verificador_Email_Igual;
    int VerificadorEmail = 0;
    int VerificadorEmail2 = 0;
    int VerificadorEmail3 = 0;
    do {
        VerificadorEmail = 1;
        VerificadorEmail2 = 0;
        VerificadorEmail3 = 0;

        printf("|E-mail:");
        fgets(projetox[pos]->Email, sizeof(projetox[pos]->Email), stdin);
        projetox[pos]->Email[strcspn(projetox[pos]->Email, "\n")] = '\0';
        p_Email = projetox[pos]->Email;
        Verificador_Email_Igual = projetox[pos]->Email;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(projetox[i]->Email, Verificador_Email_Igual)==0) {
                printf("|Email ja esta sendo utilizado!\n");
                printf("|Encerrando..........\n\n");
                projetox[pos] = NULL;
                return;
            }

        }
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
    projetox[pos]->Senha[strcspn(projetox[pos]->Senha, "\n")] = '\0';

    do {
        printf("|Confirmar senha:");
        fgets(projetox[pos]->VerificacaoDeSenha, sizeof(projetox[pos]->VerificacaoDeSenha), stdin);
        projetox[pos]->VerificacaoDeSenha[strcspn(projetox[pos]->VerificacaoDeSenha, "\n")] = '\0';
        if(strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0){
            printf("|SENHAS NAO CONFEREM!\n");
        }
    } while (strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0); // compara as duas strings

    printf("|CADASTRO REALIZADO COM SUCESSO!\n");

    srand(time(NULL));
    int ContadorMatricula = 0;
    projetox[pos]->Matricula = (rand() % 1000) + 1;
    for (int i = 0; i < pos; ++i) {
        if (projetox[pos]->Matricula == projetox[i]->Matricula){
            ContadorMatricula++;
        }
        if (ContadorMatricula == 2){
            projetox[pos]->Matricula = (rand() % 1000) + 1;
            ContadorMatricula = 0;
        }
    }

    TermoResponsabilidade(pos);
    printf("\nDECLARO QUE LI E ACEITO OS TERMOS - 1\n");
    printf("\nNAO ACEITO OS TERMOS - 2\n");
    int opcao = 0;
    scanf("%d", &opcao);
    getchar();
    int Termo = 0;
    do {
        switch (opcao) {
            case 1:
                Termo++;
                break;
            case 2:
                printf("\nCADASTRO CANCELADO!\n");
                printf("encerrando.......\n");
                projetox[pos] = NULL;
                return;
                break;
            default:
                printf("\nOpcao invalida!!");
                break;
        }
    }while (Termo != 1);

    projetox[pos]->Advertencias = 0;
    projetox[pos]->Pendencia = 0.0;
    printf("|Numero de matricula: %d\n", projetox[pos]->Matricula);
    fprintf(p_projeto, "Nome: %s;Idade: %d;CPF: %s;Email: %s;Matricula: %d;Senha: %s;Advertencias: %d;Pendencia: %.2f;\n",
            projetox[pos]->Nome,
            projetox[pos]->Idade,
            projetox[pos]->CPF,
            projetox[pos]->Email,
            projetox[pos]->Matricula,
            projetox[pos]->Senha,
            projetox[pos]->Advertencias,
            projetox[pos]->Pendencia);
    fclose(p_projeto);
    printf("|-----------------BEM VINDO AO CLUBE!---------------\n\n\n");

}

void Login(int pos, int posADM){
    char Login[51];
    int Verificador = 0;
    int GuardarPosicao = 0;
    printf("\n---------------------------------------------------------\n");
    printf("---------------------Tela de login-----------------------\n");
    printf("---------------------------------------------------------\n");
    printf("|Digite CPF ou E-mail:");
    fgets(Login, sizeof(Login), stdin);
    Login[strcspn(Login, "\n")] = '\0';
    for (int i = 0; i < pos; ++i) {
        if (strcmp(Login, projetox[i]->CPF) == 0 || strcmp(Login, projetox[i]->Email) == 0){
            Verificador = 1;
            GuardarPosicao = i;
            break;
        }else if (strcmp(Login, administrador[i]->CPF) == 0){
            Verificador = 1;
            GuardarPosicao = i;
            break;
        }
    }
    if (Verificador != 1){
        printf("|CPF ou EMAIL invalido!\n");
        return;
    }

    printf("Digite a senha:");
    fgets(Login, sizeof(Login), stdin);
    Login[strcspn(Login, "\n")] = '\0';
    if (strcmp(Login, projetox[GuardarPosicao]->Senha) == 0){
        printf("ENTRANDO.............\n\n");
    } else if (strcmp(Login, administrador[GuardarPosicao]->Senha) == 0){
        printf ("ENTRANDO COMO ADMINISTRADOR........\n\n");
        Verificador = 2;
    }else {
        printf("|Senha invalida!\n");
        return;
    }
    int opcao = 0;
    do {
        if (Verificador == 1) {
            printf("|----------------MEMBRO: %s----------------------\n", projetox[GuardarPosicao]->Nome);
            printf("| 1 - ALUGAR QUADRA\n");
            printf("| 2 - TERMOS E REGRAS\n");
            printf("| 3 - SOBRE NOS\n");
            printf("| 9 - SAIR\n");
            printf("|O QUE VOCE DESEJA ACESSAR: ");
            scanf("%d", &opcao);
            getchar();
            switch (opcao) {
                case 1:
                    break;
                case 2:
                    TermoResponsabilidade(GuardarPosicao);
                    break;
                case 3:
                    SobreNos();
                    break;
                case 9:
                    return;
                    break;
            }
        } else if (Verificador == 2) {
            int Membro = 0;
            printf("|ADMINISTRADOR: %s.\n", administrador[GuardarPosicao]->Nome);
            printf("| 1 - LISTAR TODOS OS MEMBROS\n");
            printf("| 2 - ALTERAR DADOS DE CADASTRO\n");
            printf("| 3 - ADVERTIR MEMBRO\n");
            printf("| 4 - EXCLUIR CADASTRO\n");
            printf("| 5 - PROCURAR MEMBRO\n");
            printf("| 6 - CADASTRAR ADMINISTRADOR\n");
            printf("| 7 - LISTAR FUNCIONARIOS\n");
            printf("| 8 - APLICAR MULTA\n");
            printf("| 9 - SAIR\n");
            printf("|O QUE VOCE DESEJA ACESSAR: ");
            scanf("%d", &opcao);
            getchar();
            switch (opcao) {
                case 1:
                    ListarMembros(pos);
                    break;
                case 2:
                    AlterarDados(pos);
                    break;
                case 3:
                    printf("----------------ENCONTRAR MEMBRO---------------\n");
                    printf("|Digite a matricula do membro: ");
                    scanf("%d", &Membro);
                    getchar();
                    if (Membro < 1 || Membro > 1000) {
                        fflush(stdin);
                        printf("|Matricula invalida!\n");
                        printf("------------------------------------------------\n\n");
                        return;
                    }
                    AdvertirMembro(Membro);
                    Membro = 0;

                    break;
                case 4:
                    ExcluirCadastro(pos);
                    break;
                case 5:
                    printf("----------------ENCONTRAR MEMBRO---------------\n");
                    printf("|Digite a matricula do membro: ");
                    scanf("%d", &Membro);
                    getchar();
                    if (Membro < 1 || Membro > 1000) {
                        fflush(stdin);
                        printf("|Matricula invalida!\n");
                        printf("------------------------------------------------\n\n");
                        return;
                    }
                    ListarMembroUnico(Membro);
                    Membro = 0;
                    break;
                case 6:
                    CadastrarADM(posADM);
                    posADM ++;
                    break;
                case 7:
                    ListarFuncionarios(posADM);
                    break;
                case 8:
                    printf("----------------ENCONTRAR MEMBRO---------------\n");
                    printf("|Digite a matricula do membro: ");
                    scanf("%d", &Membro);
                    getchar();
                    if (Membro < 1 || Membro > 1000) {
                        fflush(stdin);
                        printf("|Matricula invalida!\n");
                        printf("------------------------------------------------\n\n");
                        return;
                    }
                    AplicarMulta(Membro);
                    Membro = 0;
                    break;
                case 9:
                    return;
                    break;

            }
        }
    } while (opcao != 9);

}

void ListarMembroUnico(int pos){
    int ContadorCPF;
    char *p_CPF;
    for (int i = 0; i <= MAX; ++i) {
        ContadorCPF = 0;
        if (projetox[i] != NULL && projetox[i]->Matricula == pos){
            printf("\n");
            p_CPF = projetox[i]->CPF;
            printf("------------------DADOS DO MEMBRO---------------------\n");
            printf("\tNOME: %s\n", projetox[i]->Nome);
            printf("\tIDADE: %d\n", projetox[i]->Idade);
            printf("\tCPF: ");
            for (int j = 0; j < strlen(projetox[i]->CPF); ++j) {
                printf("%c", p_CPF[j]);
                ContadorCPF++;
                if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
                if (ContadorCPF == 9) printf("-");
            }
            printf("\n");
            printf("\tE-MAIL: %s\n", projetox[i]->Email);
            printf("\tMATRICULA: %d\n", projetox[i]->Matricula);
            printf("\tADVERTENCIAS: %d\n", projetox[i]->Advertencias);
            printf("\tPENDENCIA: R$ %.2f\n", projetox[i]->Pendencia);
            printf("-----------------------------------------------------------\n\n");
            return;
            }
    }
    printf("|MATRICULA NAO TEM REGISTRO!!\n");
    }

void ListarMembros(int pos){
    int Contador = 0;
    int Contas = pos;
    printf("\n********************************************************\n");
    printf("*                                                      *\n");
    printf("*----------------MEMBROS CADASTRADOS-------------------*\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");

    for (int i = 0; i < Contas; ++i) {
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
    int Matricula;
    int Verificador;
    printf("----------------------ALTERAR DADO---------------------\n");
    printf("|Digite a matricula do membro para alterar: ");
    scanf("%d", &Matricula);
    getchar();
    if (Matricula < 1 || Matricula > 1000){
        printf("|MATRICULA INVALIDA!\n");
        printf("---------------------------------------------------------\n");
        return;
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (Matricula == projetox[j]->Matricula) {
                Verificador = j;
                i = MAX;
                j = MAX;
                printf("|MATRICULA ENCONTRADA\n");
            }
        }
        if (Matricula != projetox[Verificador]->Matricula) {
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
            projetox[Verificador]->Nome[strcspn(projetox[Verificador]->Nome, "\n")] = '\0';
            printf("|NOME ALTERADO!\n");
            printf("|NOME: %s\n", projetox[Verificador]->Nome);
            printf("---------------------------------------------------------\n");
            break;
        case 2:
            printf("|IDADE: %d\n", projetox[Verificador]->Idade);
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
            projetox[Verificador]->Email[strcspn(projetox[Verificador]->Email, "\n")] = '\0';
            printf("|E-MAIL ALTERADO!\n");
            printf("|E-MAIL: %s\n", projetox[Verificador]->Email);
            printf("---------------------------------------------------------\n");
            break;
        case 4:
            printf("|SENHA: %s\n", projetox[Verificador]->Senha);
            printf("|SENHA DELETADA!\n");
            printf("|Digite a senha:");
            fgets(projetox[Verificador]->Senha, sizeof(projetox[Verificador]->Senha), stdin);
            projetox[Verificador]->Senha[strcspn(projetox[Verificador]->Senha, "\n")] = '\0';
            do {
                printf("|Confirmar senha:");
                fgets(projetox[Verificador]->VerificacaoDeSenha, sizeof(projetox[Verificador]->VerificacaoDeSenha), stdin);
                projetox[Verificador]->Senha[strcspn(projetox[Verificador]->Senha, "\n")] = '\0';
                if(strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0){
                    printf("|SENHAS NAO CONFEREM!\n");
                }
            } while (strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0);
            printf("|SENHA ALTERADA!\n");
            printf("|SENHA: %s\n", projetox[Verificador]->Senha);
            printf("---------------------------------------------------------\n");
            break;
        case 5:
            printf("|Voltando ao menu.....\n");
            printf("---------------------------------------------------------\n");
            return;
        default:
            printf("|Opcao invalida!\n");
    }
    AtualizarArquivo(pos);
}

void ExcluirCadastro(int pos) {
    int Matricula;
    printf("----------------------EXCLUIR MEMBRO---------------------\n");
    printf("|Digite a matricula do membro para excluir: ");
    scanf("%d", &Matricula);
    getchar();

    if (Matricula < 1 || Matricula > 1000) {
        printf("|MATRICULA INVALIDA!\n");
        printf("---------------------------------------------------------\n");
        return;
    }
    int Escolha = 0;
    int Encontrado = 0;
    for (int i = 0; i < pos; ++i) {
        if (projetox[i] != NULL && projetox[i]->Matricula == Matricula) {
            ListarMembroUnico(Matricula);
            printf("|VOCE QUER DELETAR O CASDATRO ACIMA?\n");
            printf("| 1 - SIM\n");
            printf("| 2 - NAO\n");
            scanf("%d", &Escolha);
            if (Escolha == 1) {
                free(projetox[i]);
                projetox[i] = NULL;
                Encontrado = 1;
                break;
            }else if (Escolha == 2){
                printf("|Voltando ao menu......\n");
                return;
            }else {
                printf("|Opcao invalida!\n");
                return;
            }
        }
    }

    if (!Encontrado) {
        printf("|Matricula nao encontrada!\n");
        printf("---------------------------------------------------------\n");
        return;
    }
    AtualizarArquivo(pos);
    printf("|CADASTRO DELETADO DO SISTEMA!\n");
    printf("---------------------------------------------------------\n");
}

void TermoResponsabilidade(int pos) {
    int ContadorCPF = 0;
    char *p_CPF = projetox[pos]->CPF;
    printf("\t\t\tTERMO DE RESPONSABILIDADE DO CLUBE ESPORTIVO\n"
           "\tEu, %s, portador do CPF ", projetox[pos]->Nome);
    for (int i = 0; i <= strlen(projetox[pos]->CPF); ++i) {
        printf("%c", p_CPF[i]);
        ContadorCPF++;
        if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
        else if (ContadorCPF == 9) printf("-");
    }
    printf(", declaro que li e estou de acordo\n"
           "\tcom as condicoes de uso das quadras e equipamentos do EliteFitClube, conforme descritas a seguir:\n\n"
           "\t1. USO DAS QUADRAS E TAXAS:\n"
           "\t\t- O aluguel da quadra por um período de 1 hora tem o custo de R$20,00.\n\n"
           "\t2. MANUTENCAO E LIMPEZA DAS QUADRAS:\n"
           "\t\t- O usuario compromete-se a deixar a quadra em condicoes de limpeza apos o uso.\n"
           "\t\t- Caso a quadra seja deixada suja, sera aplicada uma ADVERTENCIA e o usuario ficara impedido \n"
           "\t\tde alugar qualquer quadra por 1 mes.\n\n"
           "\t3. QUEBRAS E DANOS A EQUIPAMENTOS:\n"
           "\t\t- Em caso de quebra ou dano a quadra ou equipamentos, o usuario sera responsavel por\n\t\tarcar com o valor total do prejuizo.\n"
           "\t\t- Caso o valor nao seja pago, serao aplicadas 2 ADVERTENCIAS e o\n\t\tusuario ficara impedido de alugar quadras por 2 meses.\n\n"
           "\t4. ADVERTENCIAS E LIMITES:\n"
           "\t\t- Ao atingir 10 ADVERTENCIAS, o usuario ficara impedido de alugar quadras ata que pague uma multa\n"
           "\t\tno valor de R$1.500,00 ou o valor do prejuizo somado a multa, conforme o caso.\n"
           "\t\t- Apos a quitacao da multa e prejuizo, o cadastro sera desbloqueado, permitindo o uso das quadras\n\t\tnovamente.\n\n"
           "\t5. COMPROMISSO DO USUARIO:\n"
           "\t\tO usuario concorda em zelar pelo bom uso das instalacoes e respeitar os termos acima descritos.\n"
           "\t\t- O descumprimento das regras podera acarretar em advertencias e restricoes de acesso\n\t\tao clube, conforme estipulado neste termo.\n"
           "\t\tAo realizar meu cadastro, declaro ciencia e concordancia com todas as condicoes apresentadas.\n"
           "\t\tEsse ajuste mantem a regra clara e justa, evitando o bloqueio permanente e permitindo que o usuario\n"
           "\t\tregularize sua situacao mediante o pagamento da multa e do prejuizo.\n\n");

}
void SobreNos(){
    printf("\t\t\t\t\t\t\tSOBRE NOS  \n"
           "\n"
           "\tBem-vindo ao EliteFitClube, o lugar perfeito para voce se divertir, praticar esportes e viver momentos incriveis com amigos e familia! Aqui, acreditamos que o esporte e mais do que uma atividade fisica; e uma forma de criar conexoes, promover a saude e espalhar alegria.  \n"
           "\n"
           "\tOferecemos quadras impecaveis, cuidadosamente preparadas para proporcionar a melhor experiencia esportiva. Seja para futebol, volei, basquete, tenis ou corrida, nossos espacos sao equipados com materiais de alta qualidade e mantidos com um rigoroso padrao de limpeza e seguranca.  \n"
           "\n"
           "\tNosso servico vai alem de alugar quadras: temos um ambiente pensado para o seu lazer completo. Relaxe em nossas areas de convivencia, aproveite bebidas e snacks em nossa cantina ou simplesmente aproveite a atmosfera vibrante que so um clube de esportes pode oferecer.  \n"
           "\n"
           "\tNosso diferencial esta no atendimento excepcional e na organizacao impecavel. Contamos com regras claras e justas para garantir que todos possam aproveitar o espaco com tranquilidade e harmonia. Aqui, a ordem e a diversao caminham  lado a lado.  \n"
           "\n"
           "\tNo Clube Ativa Esportes, sua experiencia e nossa prioridade. Seja voce um atleta experiente ou alguem apenas buscando um momento descontraido, estamos prontos para recebe-lo de bracos abertos.  \n"
           "\n"
           "\tVenha jogar, relaxar e se conectar. Nosso clube e o seu espaco!\n");
}

void CadastrarADM(int pos){
    FILE *p_ADM = fopen("ADM.txt", "a");
    if (p_ADM == NULL) {
        printf("|Erro ao abrir o arquivo para gravar os dados.\n");
        return;
    }
    char *p_Nome;
    printf("----------------CADASTRO DE ADM-----------------\n");
    printf("|Preencha os dados para cadastro.\n");

    printf("|Nome completo:");
    fgets(administrador[pos]->Nome, sizeof(administrador[pos]->Nome), stdin);
    administrador[pos]->Nome[strcspn(administrador[pos]->Nome, "\n")] = '\0';
    p_Nome = administrador[pos]->Nome;
    for (int i = 0; i < strlen(administrador[pos]->Nome); ++i) {
        if (*p_Nome == '1' || *p_Nome == '2' || *p_Nome == '3' || *p_Nome == '4' || *p_Nome == '5' || *p_Nome == '6'
            ||*p_Nome == '7' || *p_Nome == '8' || *p_Nome == '9'){
            printf("|Nome invalido!\n");
            printf("|Encerrando......\n\n");
            administrador[pos] = NULL;
            return;
        }
        p_Nome++;
    }
    int ContadorCPF;
    int VerificacaoCPF;
    char *Verificador_CPF_Igual;
    do {
        ContadorCPF = 0;
        VerificacaoCPF = 1;
        printf("|CPF:");
        fgets(administrador[pos]->CPF, sizeof(administrador[pos]->CPF), stdin);
        administrador[pos]->CPF[strcspn(administrador[pos]->CPF, "\n")] = '\0';
        Verificador_CPF_Igual = administrador[pos]->CPF;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(administrador[i]->CPF, Verificador_CPF_Igual)==0) {
                printf("|CPF JA CADASTRADO!\n");
                printf("|Encerrando.........\n\n");
                projetox[pos] = NULL;
                return;
            }

        }
        ContadorCPF = strlen(administrador[pos]->CPF);

        if (ContadorCPF == 11){
            for (int i = 0; i < ContadorCPF; ++i) {
                if (administrador[pos]->CPF[i] < '0' || administrador[pos]->CPF[i] > '9'){
                    printf("|CPF invalido!\n");
                    VerificacaoCPF = 0;
                    break;
                }
            }
        }else {
            printf("|CPF invalido!\n");
            VerificacaoCPF = 0;
        }
    } while (VerificacaoCPF != 1);
    printf("|Crie uma senha:");
    fgets(administrador[pos]->Senha, sizeof(administrador[pos]->Senha), stdin);
    administrador[pos]->Senha[strcspn(administrador[pos]->Senha, "\n")] = '\0';

    do {
        printf("|Confirmar senha:");
        fgets(administrador[pos]->VerificacaoDeSenha, sizeof(administrador[pos]->VerificacaoDeSenha), stdin);
        administrador[pos]->VerificacaoDeSenha[strcspn(administrador[pos]->VerificacaoDeSenha, "\n")] = '\0';
        if(strcmp(administrador[pos]->Senha, administrador[pos]->VerificacaoDeSenha)!=0){
            printf("|SENHAS NAO CONFEREM!\n");
        }
    } while (strcmp(administrador[pos]->Senha, administrador[pos]->VerificacaoDeSenha)!=0);
    fprintf(p_ADM, "\nNome: %s;CPF: %s;Senha: %s;",
            administrador[pos]->Nome,
            administrador[pos]->CPF,
            administrador[pos]->Senha);
    fclose(p_ADM);
    printf("|CADASTRO REALIZADO COM SUCESSO!\n");
    return;
}

void ListarFuncionarios(int pos){
    int Cadastros = 0;
    int ContadorCPF = 0;
    char *p_CPF;
    for (int i = 0; i < pos; ++i) {
        printf("-----------------------------------------------------------------------\n");
        printf("\tFUNCIONARIO:");
        printf(" %s\n\tCPF: ", administrador[i]->Nome);
        p_CPF = administrador[i]->CPF;
        for (int j = 0; j < strlen(administrador[i]->CPF); ++j) {
            printf("%c", p_CPF[j]);
            ContadorCPF++;
            if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
            if (ContadorCPF == 9) printf("-");
        }
        ContadorCPF = 0;
        printf("\n-----------------------------------------------------------------------\n");
        printf("\n");
        Cadastros++;
    }
    printf("FUNCIONARIOS CADASTRADOS: %d\n\n", Cadastros);
}

void AdvertirMembro(int pos){
    int GuardarPosicao = 0;
    int Advertencia = 0;
    for (int i = 0; i < MAX; ++i) {
        if (projetox[i]->Matricula == pos){
            GuardarPosicao = i;
            printf("Membro encontrado: ");
            ListarMembroUnico(pos);
            break;
        }else {
            printf("Matricula sem registro!\n");
            return;
        }
    }
    printf("|Digite o numero de advertencia: ");
    scanf("%d", &Advertencia);
    getchar();

    projetox[GuardarPosicao]->Advertencias = Advertencia;
    printf("|Advertencia aplicada!\n");
    AtualizarArquivo(pos);
}
void AtualizarArquivo(int pos){
    FILE *p_projeto = fopen("projeto.txt", "w");
    if (p_projeto == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (int i = 0; i < MAX; ++i) {
        if (projetox[i] != NULL) {
            fprintf(p_projeto, "Nome: %s;Idade: %d;CPF: %s;Email: %s;Matricula: %d;Senha: %s;Advertencias: %d;Pendencia %.2f;\n",
                    projetox[i]->Nome,
                    projetox[i]->Idade,
                    projetox[i]->CPF,
                    projetox[i]->Email,
                    projetox[i]->Matricula,
                    projetox[i]->Senha,
                    projetox[i]->Advertencias,
                    projetox[i]->Pendencia);
        }
    }
    fclose(p_projeto);
}

void AplicarMulta(int pos){
    float ValorMulta = 0.0;
    int GuardarPosicao = 0;
    for (int i = 0; i < MAX; ++i) {
        if (projetox[i]->Matricula == pos){
            GuardarPosicao = i;
            printf("Membro encontrado: ");
            ListarMembroUnico(pos);
            break;
        }else {
            printf("Matricula sem registro!\n");
            return;
        }
    }
    printf("Digite o valor da multa: ");
    scanf("%f", &ValorMulta);
    getchar();

    projetox[GuardarPosicao]->Pendencia = ValorMulta;
    printf("Multa no valor de R$ %.2f aplicada!\n", ValorMulta);
    AtualizarArquivo(pos);
}