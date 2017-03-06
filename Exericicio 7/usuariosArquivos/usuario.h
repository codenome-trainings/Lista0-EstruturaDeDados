typedef struct Usuario {
    char nome[101];
    char rg[10];
    char cpf[12];
    char endereco[101];
} Usuario;

void menu();
void cadastrarUsuario();
void listarUsuarios();
void numeroDeUsuariosCadastrados();
void sair();
void insereUsuario(Usuario *pUsuario);
int numeroDeUsuarios();
void removerUltimoUsuario();
