#define MAX 1000

typedef struct Login{
    char Nome[81];
    int Idade;
    char CPF[50];
    char Email[51];
    char Senha[51];
    char VerificacaoDeSenha[51];
    int Matricula;
    int Advertencias;
    float Pendencia;
    char Observacao[51];
}login;

typedef struct ADM{
    char Nome[81];
    char CPF[50];
    char Senha[51];
    char VerificacaoDeSenha[51];
}adm;

typedef adm *p_ADM;
extern p_ADM administrador[MAX];

typedef login *p_login;
extern p_login projetox[MAX];

/**
* Função inicializa - inicializa todas as posições da biblioteca com
NULL.
*/
int inicializa(int pos);

/**LIMITADO A 100 MEMBROS
 * Para cadastrar membros novos, em ponteiros disponíveis para cadastro
 */
 int inicializaADM(int pos);
void CadastrarMembro(int pos);

/**
 * também verificar se o usuario vai digitar os dados de login correto
 * @param pos verifica o ponteiro para ver se o usuario tem login
 */
void Login(int pos, int posADM);

/**
 * Precisara digitar algum dado do membro para encontra-lo
 * @param pos imprimi os dados de um membro específico
 */
void ListarMembroUnico(int pos);

/**
 * Imprimi todos os membros cadastrados no programa
 * @param pos verifica todos os ponteiros e lista todos o membros cadastrados
 */
void ListarMembros(int pos);

/**
 * Digite uma caracteristica do membro para cadastrar
 * @param pos procura um membro específico para alterar os dados
 */
void AlterarDados(int pos);

/**
 *
 * @param pos Digite a matriculo do Membro para excluir o mesmo
 */
void ExcluirCadastro(int pos);

void MenuLogin(int pos);

void TermoResponsabilidade(int pos);

void SobreNos();

void CadastrarADM(int pos);

void ListarFuncionarios(int pos);

void AdvertirMembro(int pos);

void AtualizarArquivo(int pos);

void AplicarMulta(int pos);
