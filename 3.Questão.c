#include <stdio.h>
#include <stdlib.h>

struct dadosProduto {
    char nome[200];
    float preco;
    int qntEstoque;
};

float calcularTotalEstoque (struct dadosProduto produto) {
    return produto.preco * produto.qntEstoque;
}

struct dadosProduto atualizarEstoque (struct dadosProduto produto) {
    int quantidade;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade); 

  if (quantidade > 0 && quantidade <= produto.qntEstoque) {
    produto.qntEstoque -= quantidade;
    printf("Compra realizada com sucesso. Total: R$ %.2f\n", quantidade * produto.preco);
    } else {
    printf("Quantidade insuficiente em estoque.\n");
}
   return produto;
}

void consultaEstoque(struct dadosProduto produto) {
    printf("Nome do produto :%s \n", produto.nome);
    printf("Preço :%.2f \n", produto.preco);
    printf("Quantidade em estoque: %d \n", produto.qntEstoque);
    printf("Valor total em estoque: R$ %.2f \n", calcularTotalEstoque(produto));
}

int main () {

    struct dadosProduto Produto;
    int opcao;

    printf("Digite o nome do produto: ");
    gets(Produto.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &Produto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &Produto.qntEstoque);

    do {
    printf("\n------ MENU ------ \n");
    printf("1 - Realizar uma compra \n");
    printf("2 - Consultar estoque \n");
    printf("3 - Sair do programa. \n");

    printf("Digite a opção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1 :
        Produto = atualizarEstoque(Produto);
        break;

        case 2 :
        consultaEstoque(Produto);
        break;

        case 3 :
        printf("Saindo do programa... \n");
        break;
    
    default:
    printf("Opção inválida. \n");
        break;
    }
    
    } while (opcao != 3);

    return 0;
}