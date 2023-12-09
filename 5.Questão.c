#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dadosFuncionarios {
    char nome[200];
    char cargo[200];
    float salario;
};

float calcularMediaSalario (struct dadosFuncionarios funcionario[], int qntFuncionarios, char cargo[]) {
    int contador = 0;
    int somaSalario = 0;

     for (int i = 0; i < qntFuncionarios; ++i) {
        if (strcmp(funcionario[i].cargo, cargo) == 0) {
            somaSalario += funcionario[i].salario;
            contador++;
        }
    }

    if (contador > 0 ) {
        return somaSalario / (float)contador;
    }else{
        return 0.0;
    }
}
    
int main () {

    int qntFuncionarios;
    int i;
    char cargoDesejado[30];
    float mediaSalarial;

    printf("Digite a quantidade de funcionários: ");
    scanf("%d", &qntFuncionarios);

    struct dadosFuncionarios funcionario[qntFuncionarios];

    for (i = 0; i < qntFuncionarios; i++) {
        printf("\n--- Funcionário %d --- \n", i + 1);

        fflush(stdin);
        printf("Nome: ");
        gets(funcionario[i].nome);

        printf("Cargo: ");
        gets(funcionario[i].cargo);

        printf("Salário: ");
        scanf("%f", &funcionario[i].salario);
    }

    printf("\nDigite o cargo para calcular a media salarial: ");
    scanf("%s", cargoDesejado);

    mediaSalarial = calcularMediaSalario(funcionario, qntFuncionarios, cargoDesejado);

    printf("\nMédia salarial do cargo de %s na empresa é: %.2f\n", cargoDesejado, mediaSalarial);

    return 0;
}