#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Sauro.Domain\Aluno.c"

#define DATABASE_FILE "DbAluno.txt"

#define MAX_NOME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_ANIVERSARIO_LEN 50

void GravarAluno(Aluno *aluno) {
    FILE *database = fopen(DATABASE_FILE, "a");

    if (database == NULL) {
        printf("Falha ao abrir o banco de dados\n");
        return;
    }
    
    fprintf(database, "%d,%s,%s\n", *aluno->matricula, *aluno->nome, *aluno->dataAniversario);
    printf("%d,%s,%s\n", *aluno->matricula, *aluno->nome, *aluno->dataAniversario);
    fclose(database);
}

int main() {
    //FUNÇÕES DE TESTE

    //AdicionarAluno
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));

    strcpy(aluno->matricula, "800061709");
    strcpy(aluno->nome, "Vinicius de Oliveira Chapula");
    strcpy(aluno->dataAniversario, "20/03/2003");

    GravarAluno(aluno);
    return 0;
}
