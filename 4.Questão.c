#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contaBancaria {
    int numeroConta;
    char nomeTitular[200];
    float saldo;
    char tipoConta[50]; 
};

struct contaBancaria depositar(struct contaBancaria conta, float valor) {
    conta.saldo += valor;
    printf("Depósito de %.2f foi realizado. \n", valor);
    return conta;
}

struct contaBancaria saque (struct contaBancaria conta, float valor) {
    if (valor <= conta.saldo) {
        conta.saldo -= valor;
        printf("Saque de %.2f foi realizado.\n", valor);
    } else {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
    return conta;
}

void calculandoSaldo (struct contaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
    
    struct contaBancaria Conta;
    int opcao;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &Conta.numeroConta);

    fflush(stdin);
    printf("Digite o nome do titular: ");
    gets(Conta.nomeTitular);

    printf("Digite o saldo inicial: ");
    scanf("%f", &Conta.saldo);

    fflush(stdin);
    printf("Digite o tipo da conta (Poupança ou Corrente): ");
    gets(Conta.tipoConta);

    do {
        printf("\n------ Menu ------ \n");
        printf("1 - Depositar dinheiro \n");
        printf("2 - Realizar saque \n");
        printf("3 - Imprimir saldo bancário \n");
        printf("4 - Encerrar \n");

        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                Conta = depositar(Conta, valor);
                break;
            case 2:
                printf("Digite o valor do saque: ");
                scanf("%f", &valor);
                Conta = saque(Conta, valor);
                break;
            case 3:
                calculandoSaldo (Conta);
                break;
            case 4:
                printf("Encerrando.. \n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
