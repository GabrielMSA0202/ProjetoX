#define MAX 100

typedef struct Login{
    char Nome[51];
    int Idade;
    char Email[51];
    char Senha[51];
    char VerificacaoDeSenha[51];
    int Matricula;
}login;

typedef login *p_login;
extern p_login projetox[MAX];

/**
* Função inicializa - inicializa todas as posições da biblioteca com
NULL.
*/
void inicializa();

/**LIMITADO A 100 MEMBROS
 * Para cadastrar membros novos, em ponteiros disponíveis para cadastro
 */
void CadastrarMembro(int pos);

/**
 * também verificar se o usuario vai digitar os dados de login correto
 * @param pos verifica o ponteiro para ver se o usuario tem login
 */
void LoginMembro(int pos);

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


