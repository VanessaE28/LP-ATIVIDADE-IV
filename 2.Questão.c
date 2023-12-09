#include <stdio.h>
#include <stdlib.h>

struct dadosAluno {
    char nome[200];
    char dataNascimento [200];
    float nota[2];
    float media;
};

float calcularMedia (struct dadosAluno aluno) {
    return (aluno.nota[0] + aluno.nota[1]) / 2;
}

void AprovadoReprovado (struct dadosAluno aluno) {
    if (aluno.media >= 7) {
        printf("Aprovado! \n");
    }else{
        printf("Reprovado! \n");
    }
}

int main () {

    struct dadosAluno aluno[5];
    int i, j;
    
    for ( i = 0; i < 2; i++) {
    
    printf("Digite o nome do aluno: ");
    gets(aluno[i].nome);

    printf("Digite a data de nascimento do aluno: ");
    gets(aluno[i].dataNascimento);

    for (j = 0; j < 2; j++) {
        printf("Digite a nota do aluno: ");
        scanf("%f", &aluno[i].nota[j]);
    }
    fflush(stdin);

    aluno[i].media = calcularMedia(aluno[i]);
    printf("\n");
    }

    system("cls || clear");

    for (i = 0; i < 2; i++) {
        printf("Nome aluno: %s \n", aluno[i].nome);
        printf("Data de nascimento: %s \n", aluno[i].dataNascimento);

    for (j = 0; j < 2; j++) {
        printf("Nota: %.2f \n", aluno[i].nota[j]);
    }
        printf("Média: %.2f \n", aluno[i].media);
        AprovadoReprovado(aluno[i]);
        printf("\n");
    }
    
    return 0;
}