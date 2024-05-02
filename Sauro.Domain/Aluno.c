#define MAX_NOME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_ANIVERSARIO_LEN 50
#define MAX_MATRICULA_LEN 10

typedef struct Aluno{
    char matricula[MAX_MATRICULA_LEN];
    char nome[MAX_NOME_LEN];
    char dataAniversario[MAX_ANIVERSARIO_LEN];
} Aluno;