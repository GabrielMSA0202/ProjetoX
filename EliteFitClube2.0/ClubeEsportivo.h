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
    int Reserva;
    int Horario;
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
 * Inicializa todas as posições da biblioteca com NULL.
 * @param pos Posição a ser inicializada.
 * @return Status da inicialização.
 */
int inicializa(int pos);

/**
 * Inicializa posições específicas para administradores.
 * @param pos Posição a ser inicializada.
 * @return Status da inicialização.
 */
int inicializaADM(int pos);

/**
 * Cadastra um novo membro em uma posição disponível.
 * @param pos Posição onde o membro será cadastrado.
 */
void CadastrarMembro(int pos);

/**
 * Verifica se o usuário está digitando os dados de login corretamente.
 * @param pos Posição do membro.
 * @param posADM Posição do administrador para validação.
 */
void Login(int pos, int posADM);

/**
 * Lista os dados de um membro específico.
 * @param pos Posição do membro a ser listado.
 */
void ListarMembroUnico(int pos);

/**
 * Lista todos os membros cadastrados no programa.
 * @param pos Posição inicial para verificação.
 */
void ListarMembros(int pos);

/**
 * Permite alterar os dados de um membro específico.
 * @param pos Posição do membro a ser alterado.
 */
void AlterarDados(int pos);

/**
 * Exclui o cadastro de um membro específico com base na matrícula.
 * @param pos Posição do membro a ser excluído.
 */
void ExcluirCadastro(int pos);

/**
 * Exibe o menu de login para usuários e administradores.
 * @param pos Posição atual do login.
 */
void MenuLogin(int pos);

/**
 * Exibe e solicita aceitação de um termo de responsabilidade.
 * @param pos Posição do membro que aceita o termo.
 */
void TermoResponsabilidade(int pos);

/**
 * Mostra informações sobre a aplicação ou o clube.
 */
void SobreNos();

/**
 * Cadastra um administrador no sistema.
 * @param pos Posição onde o administrador será cadastrado.
 */
void CadastrarADM(int pos);

/**
 * Lista todos os administradores e funcionários cadastrados.
 * @param pos Posição inicial para verificação.
 */
void ListarFuncionarios(int pos);

/**
 * Aplica uma advertência a um membro específico.
 * @param pos Posição do membro a ser advertido.
 */
void AdvertirMembro(int pos);

/**
 * Atualiza o arquivo com os dados mais recentes do sistema.
 * @param pos Posição inicial para verificação e atualização.
 */
void AtualizarArquivo(int pos);

/**
 * Aplica uma multa a um membro específico.
 * @param pos Posição do membro a ser multado.
 */
void AplicarMulta(int pos);

/**
 * Reserva uma quadra para um membro ou grupo de contas.
 * @param pos Posição do membro ou grupo a ser reservado.
 * @param Contas Número de contas envolvidas na reserva.
 */
void RservarQuadra(int pos, int Contas);

/**
 * Define ou exibe horários disponíveis para atividades.
 * @param pos Posição do membro que solicita o horário.
 * @param Contas Número de contas verificadas para o horário.
 */
void Horario(int pos, int Contas);
