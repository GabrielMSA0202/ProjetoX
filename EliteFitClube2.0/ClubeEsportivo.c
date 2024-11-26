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
void AdvertirMembro(int pos);
void AplicarMulta(int pos);
void ReservarQuadra(int pos, int Contas);
void Horario(int pos, int Contas);


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
        char Reserva[51];
        char Horario[51];
    } Membro;
    for (int i = 0; i < MAX; ++i) {
        projetox[i] = malloc(sizeof(Membro));
        if (projetox[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return -1;
        }
    }
    char linha[256];
    FILE *p_projeto = fopen("projeto.txt", "r");
    if (p_projeto == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    while (pos < MAX && fgets(linha, sizeof(linha), p_projeto) != NULL) {
        if (sscanf (linha, "Nome: %[^;];Idade: %i;CPF: %11[^;];Email: %[^;];Matricula: %d;Senha: %[^;];Advertencias: %i;Pendencia: %f;Reserva: %d;Horario: %d;\n",
            projetox[pos]->Nome,
            &projetox[pos]->Idade,
            projetox[pos]->CPF,
            projetox[pos]->Email,
            &projetox[pos]->Matricula,
            projetox[pos]-> Senha,
            &projetox[pos]->Advertencias,
            &projetox[pos]->Pendencia,
            &projetox[pos]->Reserva,
            &projetox[pos]->Horario) != EOF) {
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

    printf("\n\t\t\t\t\t\t\t___________________________________________\n");
    printf("\t\t\t\t\t\t\t|                                         |\n");
    printf("\t\t\t\t\t\t\t|            CADASTRAR CLIENTE            |\n");
    printf("\t\t\t\t\t\t\t|                                         |\n");
    printf("\t\t\t\t\t\t\t|                                         |");



    printf("\n\t\t\t\t\t\t\t|NOME COMPLETO: ");
    fgets(projetox[pos]->Nome, sizeof(projetox[pos]->Nome), stdin);
    projetox[pos]->Nome[strcspn(projetox[pos]->Nome, "\n")] = '\0';
    p_Nome = projetox[pos]->Nome;
    for (int i = 0; i < strlen(projetox[pos]->Nome); ++i) {
        if (*p_Nome == '1' || *p_Nome == '2' || *p_Nome == '3' || *p_Nome == '4' || *p_Nome == '5' || *p_Nome == '6'
            ||*p_Nome == '7' || *p_Nome == '8' || *p_Nome == '9'){
            printf("\n\t\t\t\t\t\t\t|NOME INVALIDO!                           |");
            printf("\n\t\t\t\t\t\t\t|ENCERRANDO......                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
        }
        p_Nome++;
    }

    printf("\n\t\t\t\t\t\t\t|IDADE: ");
    scanf("%d", &projetox[pos]->Idade);
    getchar();

    if (projetox[pos]->Idade <= 0 || projetox[pos]->Idade > 120){
        printf("\n\t\t\t\t\t\t\t|IDADE INVALIDA!                          |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    if (projetox[pos]->Idade < 18 || projetox[pos]->Idade > 90){
        printf("\n\t\t\t\t\t\t\t|IDADE IMPROPIA PARA CADASTRO!            |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }


    int ContadorCPF;
    int VerificacaoCPF;
    char *Verificador_CPF_Igual;
    do {
        ContadorCPF = 0;
        VerificacaoCPF = 1;
        printf("\n\t\t\t\t\t\t\t|CPF:");
        fgets(projetox[pos]->CPF, sizeof(projetox[pos]->CPF), stdin);
        projetox[pos]->CPF[strcspn(projetox[pos]->CPF, "\n")] = '\0';
        Verificador_CPF_Igual = projetox[pos]->CPF;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(projetox[i]->CPF, Verificador_CPF_Igual)==0) {
                printf("\n\t\t\t\t\t\t\t|CPF JA CADASTRADO!                       |");
                printf("\n\t\t\t\t\t\t\t|ENCERRANDO.........                      |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
            }

        }
        ContadorCPF = strlen(projetox[pos]->CPF);

        if (ContadorCPF == 11){
            for (int i = 0; i < ContadorCPF; ++i) {
                if (projetox[pos]->CPF[i] < '0' || projetox[pos]->CPF[i] > '9'){
                    printf("\n\t\t\t\t\t\t\t|CPF INVALIDO!                            |");
                    VerificacaoCPF = 0;
                    break;
                }
            }
        }else {
            printf("\n\t\t\t\t\t\t\t|CPF INVALIDO!                            |");
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

        printf("\n\t\t\t\t\t\t\t|E-MAIL:");
        fgets(projetox[pos]->Email, sizeof(projetox[pos]->Email), stdin);
        projetox[pos]->Email[strcspn(projetox[pos]->Email, "\n")] = '\0';
        p_Email = projetox[pos]->Email;
        Verificador_Email_Igual = projetox[pos]->Email;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(projetox[i]->Email, Verificador_Email_Igual)==0) {
                printf("\n\t\t\t\t\t\t\t|EMAIL JA ESTA SENDO UTILIDADO!           |");
                printf("\n\t\t\t\t\t\t\t|ENCERRANDO..........                     |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
            }

        }
        do {
            if (*p_Email == ' ') {
                printf("\n\t\t\t\t\t\t\t|EMAIL INVALIDO!                          |");
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
            printf("\n\t\t\t\t\t\t\t|EMAIL INVALIDO!                          |");
        }else if (VerificadorEmail3 != 1){
            printf("\n\t\t\t\t\t\t\t|EMAIL INVALIDO!                          |");
        }


    } while (VerificadorEmail == - 1 || VerificadorEmail2 == 0 || VerificadorEmail3 == 0);
    printf("\n\t\t\t\t\t\t\t|EMAIL REGISTRADO COM SUCESSO!            |");

    printf("\n\t\t\t\t\t\t\t|SENHA:");
    fgets(projetox[pos]->Senha, sizeof(projetox[pos]->Senha), stdin);
    projetox[pos]->Senha[strcspn(projetox[pos]->Senha, "\n")] = '\0';

    do {
        printf("\n\t\t\t\t\t\t\t|CONFIRMAR SENHA:");
        fgets(projetox[pos]->VerificacaoDeSenha, sizeof(projetox[pos]->VerificacaoDeSenha), stdin);
        projetox[pos]->VerificacaoDeSenha[strcspn(projetox[pos]->VerificacaoDeSenha, "\n")] = '\0';
        if(strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0){
            printf("\n\t\t\t\t\t\t\t|SENHAS NAO CONFEREM!                     |");
        }
    } while (strcmp(projetox[pos]->Senha, projetox[pos]->VerificacaoDeSenha)!=0); // compara as duas strings

    printf("\n\t\t\t\t\t\t\t|CADASTRO REALIZADO COM SUCESSO!          |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");

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
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|DECLARO QUE LI E ACEITO OS TERMOS - 1    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|NAO ACEITO OS TERMOS - 2                 |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|DIGITE SUA OPCAO: ");
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
                printf("\n\t\t\t\t\t\t\t|CADASTRO CANCELADO!                      |");
                printf("\n\t\t\t\t\t\t\t|ENCERRANDO..........                     |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
                break;
            default:
                printf("\n\t\t\t\t\t\t\t|Opcao invalida!!                         |");
                break;
        }
    }while (Termo != 1);

    projetox[pos]->Horario = 0;
    projetox[pos]->Reserva = 0;
    projetox[pos]->Advertencias = 0;
    projetox[pos]->Pendencia = 0.0;
    printf("\n\t\t\t\t\t\t\t|SUA MATRICULA: %d                       |", projetox[pos]->Matricula);
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|             BEM VINDO AO CLUBE!         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    fprintf(p_projeto, "Nome: %s;Idade: %d;CPF: %s;Email: %s;Matricula: %d;Senha: %s;Advertencias: %d;Pendencia: %.2f;Reserva: %d;Horario: %d;\n",
            projetox[pos]->Nome,
            projetox[pos]->Idade,
            projetox[pos]->CPF,
            projetox[pos]->Email,
            projetox[pos]->Matricula,
            projetox[pos]->Senha,
            projetox[pos]->Advertencias,
            projetox[pos]->Pendencia,
            projetox[pos]->Reserva,
            projetox[pos]->Horario);
    fclose(p_projeto);
}

void Login(int pos, int posADM){
    char Login[51];
    int Verificador = 0;
    int GuardarPosicao = 0;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|              TELA DE LOGIN              |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|CPF ou E-mail:");
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
        printf("\n\t\t\t\t\t\t\t|CPF ou EMAIL invalido!                   |");
        printf("\n\t\t\t\t\t\t\t|ENCERRANDO..........                     |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }

    printf("\n\t\t\t\t\t\t\t|Digite a senha:");
    fgets(Login, sizeof(Login), stdin);
    Login[strcspn(Login, "\n")] = '\0';
    if (strcmp(Login, projetox[GuardarPosicao]->Senha) == 0){
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|ENTRANDO.............                    |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    } else if (strcmp(Login, administrador[GuardarPosicao]->Senha) == 0){
        printf("\n\t\t\t\t\t\t\t|ENTRANDO COMO ADMINISTRADOR........      |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        Verificador = 2;
    }else {
        printf("\n\t\t\t\t\t\t\t|SENHA INVALIDA!                          |");
        printf("\n\t\t\t\t\t\t\t|ENCERRANDO..........                     |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    int opcao = 0;
    do {
        if (Verificador == 1) {
            printf("\n\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| MEMBRO: %s            ", projetox[GuardarPosicao]->Nome);
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 1 - ALUGAR QUADRA                       |\n");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 2 - TERMOS E REGRAS                     |\n");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 3 - SOBRE NOS                           |\n");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 9 - SAIR                                |\n");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|O QUE VOCE DESEJA ACESSAR: ");
            scanf("%d", &opcao);
            getchar();
            switch (opcao) {
                case 1:
                    if (projetox[GuardarPosicao]->Advertencias >= 10){
                        printf("\n\t\t\t\t\t\t\t|                                         |");
                        printf("\n\t\t\t\t\t\t\t|VOCE TEM %d ADVERTENCIAS                 |", projetox[GuardarPosicao]->Advertencias);
                        printf("\n\t\t\t\t\t\t\t|PAGUE A MULTA DE: R$ 1.500 PARA LIBERAR  |");
                        printf("\n\t\t\t\t\t\t\t|SEU CPF PARA ALUGAR NOVAMENTE            |");
                        printf("\n\t\t\t\t\t\t\t|                                         |");
                        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
                        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                        return;
                    }
                    ReservarQuadra(GuardarPosicao, pos);
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
            printf("\n\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|ADMINISTRADOR: %s.", administrador[GuardarPosicao]->Nome);
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 1 - LISTAR TODOS OS MEMBROS             |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 2 - ALTERAR DADOS DE CADASTRO           |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 3 - ADVERTIR MEMBRO                     |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 4 - EXCLUIR CADASTRO                    |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 5 - PROCURAR MEMBRO                     |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 6 - CADASTRAR ADMINISTRADOR             |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 7 - LISTAR FUNCIONARIOS                 |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 8 - APLICAR MULTA                       |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 9 - SAIR                                |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|O QUE VOCE DESEJA ACESSAR: ");
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
                    AdvertirMembro(pos);
                    break;
                case 4:
                    ExcluirCadastro(pos);
                    break;
                case 5:
                    printf("\n\t\t\t\t\t\t\t___________________________________________");
                    printf("\n\t\t\t\t\t\t\t|                                         |");
                    printf("\n\t\t\t\t\t\t\t|             ENCONTRAR MEMBRO            |");
                    printf("\n\t\t\t\t\t\t\t|                                         |");
                    printf("\n\t\t\t\t\t\t\t|                                         |");
                    printf("\n\t\t\t\t\t\t\t|Digite a matricula do membro: ");
                    scanf("%d", &Membro);
                    getchar();
                    if (Membro < 1 || Membro > 1000) {
                        fflush(stdin);
                        printf("\n\t\t\t\t\t\t\t|MATRICULA INVALIDA!");
                        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
                        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
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
                    AplicarMulta(pos);
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
    int Membro = 0;
    for (int i = 0; i <= MAX; ++i) {
        if (projetox[i] != NULL) {
            Membro++;
        }
        ContadorCPF = 0;
        if (projetox[i] != NULL && projetox[i]->Matricula == pos){
            printf("\n");
            p_CPF = projetox[i]->CPF;
            printf("\n\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|          DADOS DO MEMBRO: %d             |", Membro);
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|NOME: %s", projetox[i]->Nome);
            printf("\n\t\t\t\t\t\t\t|IDADE: %d", projetox[i]->Idade);
            printf("\n\t\t\t\t\t\t\t|CPF: ");
            for (int j = 0; j < strlen(projetox[i]->CPF); ++j) {
                printf("%c", p_CPF[j]);
                ContadorCPF++;
                if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
                if (ContadorCPF == 9) printf("-");
            }
            printf("\n\t\t\t\t\t\t\t|E-MAIL: %s", projetox[i]->Email);
            printf("\n\t\t\t\t\t\t\t|MATRICULA: %d", projetox[i]->Matricula);
            printf("\n\t\t\t\t\t\t\t|ADVERTENCIAS: %d", projetox[i]->Advertencias);
            printf("\n\t\t\t\t\t\t\t|PENDENCIA: R$ %.2f", projetox[i]->Pendencia);
            if (projetox[i]->Reserva < 1 || projetox[i]->Reserva > 15){
                printf("\n\t\t\t\t\t\t\t|QUADRA RESERVADA: SEM RESERVA            |");
                printf("\n\t\t\t\t\t\t\t|                                         |");
            }else if (projetox[i]->Reserva == 1 || projetox[i]->Reserva == 2 || projetox[i]->Reserva == 3){
                printf("\n\t\t\t\t\t\t\t|QUADRA RESERVADA: %d - FUTEBOL            |", projetox[i]->Reserva);
                if (projetox[i]->Horario == 1){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 08:00 AS 09:00                  |");
                } else if (projetox[i]->Horario == 2){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 09:10 AS 10:10                  |");
                }else if (projetox[i]->Horario == 3){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 10:20 AS 11:20                  |");
                }else if (projetox[i]->Horario == 4){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 11:30 AS 12:30                  |");
                }else if (projetox[i]->Horario == 5){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 12:40 AS 13:40                  |");
                }else if (projetox[i]->Horario == 6){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 13:50 AS 14:50                  |");
                }else if (projetox[i]->Horario == 7){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 15:00 AS 16:00                  |");
                }else if (projetox[i]->Horario == 8){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 16:10 AS 17:10                  |");
                }else if (projetox[i]->Horario == 9){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 17:20 AS 18:20                  |");
                }else if (projetox[i]->Horario == 10){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 18:30 AS 19:30                  |");
                }else if (projetox[i]->Horario == 11){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 19:40 AS 20:40                  |");
                }else if (projetox[i]->Horario == 12){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 20:50 AS 21:50                  |");
                }else if (projetox[i]->Horario == 13){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 22:00 AS 23:00                  |");
                }else if (projetox[i]->Horario == 14){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 23:10 AS 00:10                  |");
                }
                printf("\n\t\t\t\t\t\t\t|                                         |");
            } else if (projetox[i]->Reserva == 4 || projetox[i]->Reserva == 5 || projetox[i]->Reserva == 6){
                printf("\n\t\t\t\t\t\t\t|QUADRA RESERVADA: %d - BASQUETE               |", projetox[i]->Reserva);
                if (projetox[i]->Horario == 1){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 08:00 AS 09:00                  |");
                } else if (projetox[i]->Horario == 2){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 09:10 AS 10:10                  |");
                }else if (projetox[i]->Horario == 3){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 10:20 AS 11:20                  |");
                }else if (projetox[i]->Horario == 4){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 11:30 AS 12:30                  |");
                }else if (projetox[i]->Horario == 5){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 12:40 AS 13:40                  |");
                }else if (projetox[i]->Horario == 6){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 13:50 AS 14:50                  |");
                }else if (projetox[i]->Horario == 7){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 15:00 AS 16:00                  |");
                }else if (projetox[i]->Horario == 8){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 16:10 AS 17:10                  |");
                }else if (projetox[i]->Horario == 9){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 17:20 AS 18:20                  |");
                }else if (projetox[i]->Horario == 10){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 18:30 AS 19:30                  |");
                }else if (projetox[i]->Horario == 11){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 19:40 AS 20:40                  |");
                }else if (projetox[i]->Horario == 12){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 20:50 AS 21:50                  |");
                }else if (projetox[i]->Horario == 13){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 22:00 AS 23:00                  |");
                }else if (projetox[i]->Horario == 14){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 23:10 AS 00:10                  |");
                }
                printf("\n\t\t\t\t\t\t\t|                                         |");
            } else if (projetox[i]->Reserva == 7 || projetox[i]->Reserva == 8 || projetox[i]->Reserva == 9){
                printf("\n\t\t\t\t\t\t\t|QUADRA RESERVADA: %d - VOLEI              |", projetox[i]->Reserva);
                if (projetox[i]->Horario == 1){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 08:00 AS 09:00                  |");
                } else if (projetox[i]->Horario == 2){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 09:10 AS 10:10                  |");
                }else if (projetox[i]->Horario == 3){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 10:20 AS 11:20                  |");
                }else if (projetox[i]->Horario == 4){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 11:30 AS 12:30                  |");
                }else if (projetox[i]->Horario == 5){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 12:40 AS 13:40                  |");
                }else if (projetox[i]->Horario == 6){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 13:50 AS 14:50                  |");
                }else if (projetox[i]->Horario == 7){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 15:00 AS 16:00                  |");
                }else if (projetox[i]->Horario == 8){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 16:10 AS 17:10                  |");
                }else if (projetox[i]->Horario == 9){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 17:20 AS 18:20                  |");
                }else if (projetox[i]->Horario == 10){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 18:30 AS 19:30                  |");
                }else if (projetox[i]->Horario == 11){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 19:40 AS 20:40                  |");
                }else if (projetox[i]->Horario == 12){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 20:50 AS 21:50                  |");
                }else if (projetox[i]->Horario == 13){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 22:00 AS 23:00                  |");
                }else if (projetox[i]->Horario == 14){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 23:10 AS 00:10                  |");
                }
                printf("\n\t\t\t\t\t\t\t|                                         |");
            } else if (projetox[i]->Reserva == 10 || projetox[i]->Reserva == 11 || projetox[i]->Reserva == 12) {
                printf("\n\t\t\t\t\t\t\t|QUADRA RESERVADA: %d - FUTSAL             |", projetox[i]->Reserva);
                if (projetox[i]->Horario == 1){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 08:00 AS 09:00                  |");
                } else if (projetox[i]->Horario == 2){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 09:10 AS 10:10                  |");
                }else if (projetox[i]->Horario == 3){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 10:20 AS 11:20                  |");
                }else if (projetox[i]->Horario == 4){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 11:30 AS 12:30                  |");
                }else if (projetox[i]->Horario == 5){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 12:40 AS 13:40                  |");
                }else if (projetox[i]->Horario == 6){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 13:50 AS 14:50                  |");
                }else if (projetox[i]->Horario == 7){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 15:00 AS 16:00                  |");
                }else if (projetox[i]->Horario == 8){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 16:10 AS 17:10                  |");
                }else if (projetox[i]->Horario == 9){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 17:20 AS 18:20                  |");
                }else if (projetox[i]->Horario == 10){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 18:30 AS 19:30                  |");
                }else if (projetox[i]->Horario == 11){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 19:40 AS 20:40                  |");
                }else if (projetox[i]->Horario == 12){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 20:50 AS 21:50                  |");
                }else if (projetox[i]->Horario == 13){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 22:00 AS 23:00                  |");
                }else if (projetox[i]->Horario == 14){
                    printf("\n\t\t\t\t\t\t\t|HORARIO: 23:10 AS 00:10                  |");
                }
                printf("\n\t\t\t\t\t\t\t|                                         |");
            }

            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            return;
            }
    }
    printf("\n\t\t\t\t\t\t\t|MATRICULA NAO TEM REGISTRO!!             |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");

    }

void ListarMembros(int pos){
    int Contador = 0;
    int Contas = pos;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|           MEMBROS  CADASTRADOS          |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|");

    for (int i = 0; i < Contas; ++i) {
        if (projetox[i] != NULL){
            pos = projetox[i]->Matricula;
            ListarMembroUnico(pos);
            Contador++;
        }
    }
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|TOTAL DE MEMBROS CADASTRADOS: %d          |", Contador);
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
}

void AlterarDados(int pos){
    int opcao;
    int Matricula;
    int Verificador;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|              ALTERAR DADOS              |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|Digite a matricula do membro: ");
    scanf("%d", &Matricula);
    getchar();
    if (Matricula < 1 || Matricula > 1000){
        printf("\n\t\t\t\t\t\t\t|MATRICULA INVALIDA!");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (Matricula == projetox[j]->Matricula) {
                Verificador = j;
                i = MAX;
                j = MAX;
                printf("\n\t\t\t\t\t\t\t|                                         |");
                printf("\n\t\t\t\t\t\t\t|MATRICULA ENCONTRADA                     |\n");
            }
        }
        if (Matricula != projetox[Verificador]->Matricula) {
            printf("\n\t\t\t\t\t\t\t|MATRICULA NAO ENCONTRADA!");
            printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            return;
        }
    }
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 1 - NOME                                |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 2 - IDADE                               |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 3 - E-MAIL                              |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 4 - SENHA                               |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 5 - SAIR                                |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|O QUE QUER ALTERAR?: ");

    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
        case 1:
            printf("\n\t\t\t\t\t\t\t|NOME: %s", projetox[Verificador]->Nome);
            printf("\n\t\t\t\t\t\t\t|NOME DELETADO!                           |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|Digite o nome:");
            fgets(projetox[Verificador]->Nome, sizeof(projetox[Verificador]->Nome), stdin);
            projetox[Verificador]->Nome[strcspn(projetox[Verificador]->Nome, "\n")] = '\0';
            printf("\n\t\t\t\t\t\t\t|NOME ALTERADO!                           |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|NOME: %s", projetox[Verificador]->Nome);
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            break;
        case 2:
            printf("\n\t\t\t\t\t\t\t|IDADE: %d", projetox[Verificador]->Idade);
            printf("\n\t\t\t\t\t\t\t|IDADE DELETADA!                          |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|Digite idade:");
            scanf("%d", &projetox[Verificador]->Idade);
            getchar();
            printf("\n\t\t\t\t\t\t\t|IDADE ALTERADA!                          |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|IDADE: %d", projetox[Verificador]->Idade);
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            break;
        case 3:
            printf("\n\t\t\t\t\t\t\t|E-MAIL: %s", projetox[Verificador]->Email);
            printf("\n\t\t\t\t\t\t\t|E-MAIL DELETADO!                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|Digite o e-mail:");
            fgets(projetox[Verificador]->Email, sizeof(projetox[Verificador]->Email), stdin);
            projetox[Verificador]->Email[strcspn(projetox[Verificador]->Email, "\n")] = '\0';
            printf("\n\t\t\t\t\t\t\t|E-MAIL ALTERADO!                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|E-MAIL: %s\n", projetox[Verificador]->Email);
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            break;
        case 4:
            printf("\n\t\t\t\t\t\t\t|SENHA: %s", projetox[Verificador]->Senha);
            printf("\n\t\t\t\t\t\t\t|SENHA DELETADA!                          |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|Digite a senha:");
            fgets(projetox[Verificador]->Senha, sizeof(projetox[Verificador]->Senha), stdin);
            projetox[Verificador]->Senha[strcspn(projetox[Verificador]->Senha, "\n")] = '\0';
            do {
                printf("\n\t\t\t\t\t\t\t|Confirmar senha:");
                fgets(projetox[Verificador]->VerificacaoDeSenha, sizeof(projetox[Verificador]->VerificacaoDeSenha), stdin);
                projetox[Verificador]->Senha[strcspn(projetox[Verificador]->Senha, "\n")] = '\0';
                if(strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0){
                    printf("\n\t\t\t\t\t\t\t|SENHAS NAO CONFEREM!                     |");
                    printf("\n\t\t\t\t\t\t\t|                                         |");
                }
            } while (strcmp(projetox[Verificador]->Senha, projetox[Verificador]->VerificacaoDeSenha)!=0);
            printf("\n\t\t\t\t\t\t\t|SENHA ALTERADA!                          |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|SENHA: %s", projetox[Verificador]->Senha);
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            break;
        case 5:
            printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            return;
        default:
            printf("\n\t\t\t\t\t\t\t|Opcao invalida!                          |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    }
    AtualizarArquivo(pos);
}

void ExcluirCadastro(int pos) {
    int Matricula;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|             EXCLUIR MEMBRO              |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|Digite a matricula do membro: ");
    scanf("%d", &Matricula);
    getchar();

    if (Matricula < 1 || Matricula > 1000) {
        printf("\n\t\t\t\t\t\t\t|MATRICULA INVALIDA!");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    int Escolha = 0;
    int Encontrado = 0;
    for (int i = 0; i < pos; ++i) {
        if (projetox[i] != NULL && projetox[i]->Matricula == Matricula) {
            ListarMembroUnico(Matricula);
            printf("\n\t\t\t\t\t\t\t|VOCE QUER DELETAR O CASDATRO ACIMA?      |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 1 - SIM                                 |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t| 2 - NAO                                 |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|Digite sua opcao: ");
            scanf("%d", &Escolha);
            if (Escolha == 1) {
                free(projetox[i]);
                projetox[i] = NULL;
                Encontrado = 1;
                break;
            }else if (Escolha == 2){
                printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
            }else {
                printf("\n\t\t\t\t\t\t\t|Opcao invalida!                          |");
                printf("\n\t\t\t\t\t\t\t|                                         |");
                printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
                printf("\n\t\t\t\t\t\t\t|                                         |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
            }
        }
    }

    if (!Encontrado) {
        printf("\n\t\t\t\t\t\t\t|Matricula nao encontrada!                |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    AtualizarArquivo(pos);
    printf("\n\t\t\t\t\t\t\t|CADASTRO DELETADO DO SISTEMA!            |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
}

void TermoResponsabilidade(int pos) {
    int ContadorCPF = 0;
    char *p_CPF = projetox[pos]->CPF;
    printf("\n\t\t\t\t\t\t\t   TERMO DE RESPONSABILIDADE DO CLUBE ESPORTIVO"
           "\n\t\t\t\t\tEu, %s, portador do CPF ", projetox[pos]->Nome);
    for (int i = 0; i <= strlen(projetox[pos]->CPF); ++i) {
        printf("%c", p_CPF[i]);
        ContadorCPF++;
        if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
        else if (ContadorCPF == 9) printf("-");
    }
    printf("\n\t\t\t\t\tdeclaro que li e estou de acordo "
           "com  as  condicoes  de  uso  das quadras e  \t\t\t\t\t\tequipamentos  do  EliteFitClube conforme descritas a seguir:"
           "\n\n\t\t\t\t\t1. USO DAS QUADRAS E TAXAS:"
           "\n\t\t\t\t\tO aluguel da quadra por um periodo de 1 hora tem o custo de R$40,00."
           "\n\n\t\t\t\t\t2. MANUTENCAO E LIMPEZA DAS QUADRAS:"
           "\n\t\t\t\t\tO usuario compromete-se a deixar a quadra em condicoes de limpeza apos o\t\t\t\t\t\tuso."
           " Caso a quadra seja deixada suja, sera aplicada uma ADVERTENCIA e o usuario \t\t\t\t\tficara impedido "
           "de alugar qualquer quadra por 1 mes."
           "\n\n\t\t\t\t\t3. QUEBRAS E DANOS A EQUIPAMENTOS:"
           "\n\t\t\t\t\tEm caso de quebra ou dano a quadra ou equipamentos, o usuario sera responsavel\n\t\t\t\t\tpor arcar com o valor total do prejuizo."
           " Caso o valor nao seja pago, serao \n\t\t\t\t\taplicadas 2 ADVERTENCIAS e o usuario ficara impedido de alugar quadras por 2 \n\t\t\t\t\tmeses."
           "\n\n\t\t\t\t\t4. ADVERTENCIAS E LIMITES:"
           "\n\t\t\t\t\tAo atingir 10 ADVERTENCIAS, o usuario ficara impedido de alugar quadras ate que \t\t\t\t\tpague uma multa"
           " no valor de R$1.500,00 ou o valor do prejuizo somado a multa,\n\t\t\t\t\tconforme  o  caso."
           " Apos  a quitacao  da multa  e  prejuizo, o  cadastro sera\n\t\t\t\t\tdesbloqueado, permitindo o uso das quadras novamente."
           "\n\n\t\t\t\t\t5. COMPROMISSO DO USUARIO:"
           "\n\t\t\t\t\tO usuario concorda em zelar pelo bom uso das instalacoes e respeitar os termos \n\t\t\t\t\tacima descritos."
           " O descumprimento das regras podera acarretar em advertencias e \t\t\t\t\trestricoes de acesso ao clube, conforme estipulado neste termo."
           " Ao realizar meu\t\t\t\t\t\tcadastro, declaro ciencia e concordancia com todas as condicoes apresentadas."
           "\n\t\t\t\t\tEsse ajuste mantem a regra clara e justa, evitando o bloqueio permanente e\n\t\t\t\t\tpermitindo que o usuario"
           " regularize sua situacao mediante o pagamento da multa e\t\t\t\t\tdo prejuizo.");

}
void SobreNos(){
    printf("\n\t\t\t\t\t\t\t\t\tSOBRE NOS  "
           "\n"
           "\n\t\t\t\t\t\tBem-vindo ao EliteFitClube, o lugar perfeito para voce se divertir\n\t\t\t\t\tpraticar esportes e viver momentos incriveis com amigos e familia! Aqui \n\t\t\t\t\tacreditamos que o esporte e mais do que uma atividade fisica; e uma forma de \n\t\t\t\t\tcriar conexoes, promover a saude e espalhar alegria."
           "\n"
           "\n\t\t\t\t\t\tOferecemos quadras impecaveis, cuidadosamente preparadas para\n\t\t\t\t\tproporcionar a melhor experiencia esportiva. Seja para futebol, volei, basquete\n\t\t\t\t\ttenis ou corrida, nossos espacos sao equipados com materiais de alta qualidade e\t\t\t\t\tmantidos com um rigoroso padrao de limpeza e seguranca."
           "\n"
           "\n\t\t\t\t\t\tNosso servico vai alem de alugar quadras: temos um ambiente pensado para \t\t\t\t\to seu lazer completo. Relaxe em nossas areas de convivencia, aproveite bebidas e\t\t\t\t\tsnacks em nossa cantina ou simplesmente aproveite a atmosfera vibrante que so um\t\t\t\t\tclube de esportes pode oferecer."
           "\n"
           "\n\t\t\t\t\t\tNosso diferencial esta no atendimento excepcional e na organizacao\n\t\t\t\t\timpecavel. Contamos com regras claras e justas para garantir que todos possam\n\t\t\t\t\taproveitar o espaco com tranquilidade e harmonia. Aqui, a ordem e a diversao\n\t\t\t\t\tcaminham  lado a lado."
           "\n"
           "\n\t\t\t\t\t\tNo Clube Ativa Esportes, sua experiencia e nossa prioridade. Seja voce\n\t\t\t\t\tum atleta experiente ou alguem apenas buscando um momento descontraido, estamos \t\t\t\t\tprontos para recebe-lo de bracos abertos."
           "\n"
           "\n\t\t\t\t\t\tVenha jogar, relaxar e se conectar. Nosso clube e o seu espaco!\n\n\n");
}

void CadastrarADM(int pos){
    FILE *p_ADM = fopen("ADM.txt", "a");
    if (p_ADM == NULL) {
        printf("|Erro ao abrir o arquivo para gravar os dados.\n");
        return;
    }
    char *p_Nome;
    printf("\n\t\t\t\t\t\t\t___________________________________________\n");
    printf("\t\t\t\t\t\t\t|                                         |\n");
    printf("\t\t\t\t\t\t\t|              CADASTRAR ADM              |\n");
    printf("\t\t\t\t\t\t\t|                                         |\n");
    printf("\t\t\t\t\t\t\t|                                         |");

    printf("\n\t\t\t\t\t\t\t|NOME COMPLETO: ");
    fgets(administrador[pos]->Nome, sizeof(administrador[pos]->Nome), stdin);
    administrador[pos]->Nome[strcspn(administrador[pos]->Nome, "\n")] = '\0';
    p_Nome = administrador[pos]->Nome;
    for (int i = 0; i < strlen(administrador[pos]->Nome); ++i) {
        if (*p_Nome == '1' || *p_Nome == '2' || *p_Nome == '3' || *p_Nome == '4' || *p_Nome == '5' || *p_Nome == '6'
            ||*p_Nome == '7' || *p_Nome == '8' || *p_Nome == '9'){
            printf("\n\t\t\t\t\t\t\t|NOME INVALIDO!                           |");
            printf("\n\t\t\t\t\t\t\t|ENCERRANDO......                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
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
        printf("\n\t\t\t\t\t\t\t|CPF: ");
        fgets(administrador[pos]->CPF, sizeof(administrador[pos]->CPF), stdin);
        administrador[pos]->CPF[strcspn(administrador[pos]->CPF, "\n")] = '\0';
        Verificador_CPF_Igual = administrador[pos]->CPF;
        for (int i = 0; i < pos; ++i) {
            if (strcmp(administrador[i]->CPF, Verificador_CPF_Igual)==0) {
                printf("\n\t\t\t\t\t\t\t|CPF JA CADASTRADO!                       |");
                printf("\n\t\t\t\t\t\t\t|ENCERRANDO.........                      |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                return;
            }

        }
        ContadorCPF = strlen(administrador[pos]->CPF);

        if (ContadorCPF == 11){
            for (int i = 0; i < ContadorCPF; ++i) {
                if (administrador[pos]->CPF[i] < '0' || administrador[pos]->CPF[i] > '9'){
                    printf("\n\t\t\t\t\t\t\t|CPF INVALIDO!                            |");
                    printf("\t\t\t\t\t\t\t|                                         |");
                    VerificacaoCPF = 0;
                    break;
                }
            }
        }else {
            printf("\n\t\t\t\t\t\t\t|CPF INVALIDO!                            |");
            printf("\t\t\t\t\t\t\t|                                         |");
            VerificacaoCPF = 0;
        }
    } while (VerificacaoCPF != 1);
    printf("\n\t\t\t\t\t\t\t|Crie uma senha:");
    fgets(administrador[pos]->Senha, sizeof(administrador[pos]->Senha), stdin);
    administrador[pos]->Senha[strcspn(administrador[pos]->Senha, "\n")] = '\0';

    do {
        printf("\n\t\t\t\t\t\t\t|Confirmar senha:");
        fgets(administrador[pos]->VerificacaoDeSenha, sizeof(administrador[pos]->VerificacaoDeSenha), stdin);
        administrador[pos]->VerificacaoDeSenha[strcspn(administrador[pos]->VerificacaoDeSenha, "\n")] = '\0';
        if(strcmp(administrador[pos]->Senha, administrador[pos]->VerificacaoDeSenha)!=0){
            printf("\n\t\t\t\t\t\t\t|SENHAS NAO CONFEREM!                     |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
        }
    } while (strcmp(administrador[pos]->Senha, administrador[pos]->VerificacaoDeSenha)!=0);
    fprintf(p_ADM, "\nNome: %s;CPF: %s;Senha: %s;",
            administrador[pos]->Nome,
            administrador[pos]->CPF,
            administrador[pos]->Senha);
    fclose(p_ADM);
    printf("\n\t\t\t\t\t\t\t|CADASTRO REALIZADO COM SUCESSO!\n");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    return;
}

void ListarFuncionarios(int pos){
    int Cadastros = 0;
    int ContadorCPF = 0;
    char *p_CPF;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|           LISTAR FUNCIONARIOS           |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    for (int i = 0; i < pos; ++i) {
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|%s\n\t\t\t\t\t\t\t|CPF: ", administrador[i]->Nome);
        p_CPF = administrador[i]->CPF;
        for (int j = 0; j < strlen(administrador[i]->CPF); ++j) {
            printf("%c", p_CPF[j]);
            ContadorCPF++;
            if (ContadorCPF == 3 || ContadorCPF == 6) printf(".");
            if (ContadorCPF == 9) printf("-");
        }
        ContadorCPF = 0;
        Cadastros++;
    }

    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|FUNCIONARIOS CADASTRADOS: %d", Cadastros);
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
}

void AdvertirMembro(int pos){
    int Membro = 0;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|           APLICAR ADVERTENCIA           |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|Digite a matricula do membro: ");
    scanf("%d", &Membro);
    getchar();
    if (Membro < 1 || Membro > 1000) {
        fflush(stdin);
        printf("\n\t\t\t\t\t\t\t|Matricula invalida!                      |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    int GuardarPosicao = 0;
    int Advertencia = 0;
    for (int i = 0; i < pos; ++i) {
        if (projetox[i] != NULL && projetox[i]->Matricula == Membro){
            GuardarPosicao = i;
            printf("\n\t\t\t\t\t\t\t|Membro encontrado:                       |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            ListarMembroUnico(Membro);
            break;
        }
    }
    if (GuardarPosicao == -1){
        printf("\n\t\t\t\t\t\t\t|Matricula sem registro!                  |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    printf("\n\t\t\t\t\t\t\t|Digite o numero de advertencia: ");
    scanf("%d", &Advertencia);
    getchar();

    projetox[GuardarPosicao]->Advertencias += Advertencia;
    printf("\n\t\t\t\t\t\t\t|Advertencia aplicada!                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    AtualizarArquivo(pos);
}
void AtualizarArquivo(int pos){
    FILE *p_projeto = fopen("projeto.txt", "w");
    if (p_projeto == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (int i = 0; i < pos; ++i) {
        if (projetox[i] != NULL) {
            fprintf(p_projeto, "Nome: %s;Idade: %d;CPF: %s;Email: %s;Matricula: %d;Senha: %s;Advertencias: %d;Pendencia: %.2f;Reserva: %d;Horario: %d;\n",
                    projetox[i]->Nome,
                    projetox[i]->Idade,
                    projetox[i]->CPF,
                    projetox[i]->Email,
                    projetox[i]->Matricula,
                    projetox[i]->Senha,
                    projetox[i]->Advertencias,
                    projetox[i]->Pendencia,
                    projetox[i]->Reserva,
                    projetox[i]->Horario);
        }
    }
    fclose(p_projeto);
}

void AplicarMulta(int pos){
    int Membro = 0 ;
    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|              APLICAR MULTA              |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|Digite a matricula do membro: ");
    scanf("%d", &Membro);
    getchar();
    if (Membro < 1 || Membro > 1000) {
        fflush(stdin);
        printf("\n\t\t\t\t\t\t\t|Matricula invalida!                      |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    float ValorMulta = 0.0;
    int GuardarPosicao = -1;
    for (int i = 0; i < pos; ++i) {
        if (projetox[i] != NULL && projetox[i]->Matricula == Membro){
            GuardarPosicao = i;
            printf("\n\t\t\t\t\t\t\t|Membro encontrado:                       |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            ListarMembroUnico(Membro);
            break;
        }
    }
    if (GuardarPosicao == -1){
        printf("\n\t\t\t\t\t\t\t|Matricula sem registro!                  |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    printf("\n\t\t\t\t\t\t\t|Digite o valor da multa: ");
    scanf("%f", &ValorMulta);
    getchar();

    projetox[GuardarPosicao]->Pendencia += ValorMulta;
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|Multa no valor de R$ %.2f aplicada!\n", ValorMulta);
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    AtualizarArquivo(pos);
}
void ReservarQuadra(int pos, int Contas){
    int opcao = 0;

    printf("\n\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|             RESERVAR QUADRA             |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|QUADRAS DISPONIVEIS:                     |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| 1 - FUTEBOL                             |");
    printf("\n\t\t\t\t\t\t\t| 2 - FUTEBOL                             |");
    printf("\n\t\t\t\t\t\t\t| 3 - FUTEBOL                             |");
    printf("\n\t\t\t\t\t\t\t| 4 - BASQUETE                            |");
    printf("\n\t\t\t\t\t\t\t| 5 - BASQUETE                            |");
    printf("\n\t\t\t\t\t\t\t| 6 - BASQUETE                            |");
    printf("\n\t\t\t\t\t\t\t| 7 - VOLEI                               |");
    printf("\n\t\t\t\t\t\t\t| 8 - VOLEI                               |");
    printf("\n\t\t\t\t\t\t\t| 9 - VOLEI                               |");
    printf("\n\t\t\t\t\t\t\t| 10 - TENIS                              |");
    printf("\n\t\t\t\t\t\t\t| 11 - TENIS                              |");
    printf("\n\t\t\t\t\t\t\t| 12 - TENIS                              |");
    printf("\n\t\t\t\t\t\t\t| 13 - FUTSAL                             |");
    printf("\n\t\t\t\t\t\t\t| 14 - FUTSAL                             |");
    printf("\n\t\t\t\t\t\t\t| 15 - FUTSAL                             |");
    printf("\n\t\t\t\t\t\t\t| ESCOLHA UMA QUADRA:");
    scanf("%d", &opcao);
    getchar();

    if (opcao < 1 || opcao > 15){
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|OPCAO INVALIDA!                          |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
        printf("\n\t\t\t\t\t\t\t|                                         |");
        printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
        return;
    }
    projetox[pos]->Reserva = opcao;
    Horario(pos,Contas);
}
void Horario(int pos, int Contas){
    int Horario = 0;
    int Contador = 0;
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|%s", projetox[pos]->Nome);
    printf("\n\t\t\t\t\t\t\t|ESCOLHA UM HORARIO PARA RESERVA:         |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|  1 - 08:00 AS 09:00 ; 2 - 09:10 AS 10:10|");
    printf("\n\t\t\t\t\t\t\t|  3 - 10:20 AS 11:20 ; 4 - 11:30 AS 12:30|");
    printf("\n\t\t\t\t\t\t\t|  5 - 12:40 AS 13:40 ; 6 - 13:50 AS 14:50|");
    printf("\n\t\t\t\t\t\t\t|  7 - 15:00 AS 16:00 ; 8 - 16:10 AS 17:10|");
    printf("\n\t\t\t\t\t\t\t|  9 - 17:20 AS 18:20 ;10 - 18:30 AS 19:30|");
    printf("\n\t\t\t\t\t\t\t| 11 - 19:40 AS 20:40 ;12 - 20:50 AS 21:50|");
    printf("\n\t\t\t\t\t\t\t| 13 - 22:00 AS 23:00 ;14 - 23:10 AS 00:10|");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t| ESCOLHA UM HORARIO:");
    scanf("%d", &Horario);
    getchar();

    if(Horario < 0 || Horario > 14){
            printf("\n\t\t\t\t\t\t\t|Horario invalido.                        |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
            printf("\n\t\t\t\t\t\t\t|                                         |");
            printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
            return;
    }

    Contador = 0;
    projetox[pos]->Horario = Horario;
    for (int i = 0; i < Contas; ++i) {
        if (projetox[i]->Reserva == projetox[pos]->Reserva && projetox[i]->Horario == projetox[pos]->Horario){
            Contador++;
            if (Contador == 2) {
                projetox[pos]->Reserva = 0;
                projetox[pos]->Horario = 0;
                printf("\n\t\t\t\t\t\t\t|HORARIO INDISPONIVEL!                    |");
                printf("\n\t\t\t\t\t\t\t|                                         |");
                printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
                printf("\n\t\t\t\t\t\t\t|                                         |");
                printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
                Contador = 0;
                return;
            }
        }
    }
    Contador = 0;
    printf("\n\t\t\t\t\t\t\t|Horario %d reservado!                     |", Horario);
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|VOLTANDO AO MENU.....                    |");
    printf("\n\t\t\t\t\t\t\t|                                         |");
    printf("\n\t\t\t\t\t\t\t|_________________________________________|\n\n");
    AtualizarArquivo(Contas);
}