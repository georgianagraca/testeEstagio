#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_CONTAS 100

typedef struct {
    char cpf[12];
    char nome[50];
    char endereco[100];
    char profissao[50];
} Cliente;

typedef struct {
    Cliente cliente;
    int numero;
    int agencia;
    float saldo;
    float limite;
    int tipo; // 0 para conta corrente, 1 para conta poupança
} Conta;

Cliente clientes[MAX_CLIENTES];
Conta contas[MAX_CONTAS];
int numClientes = 0;
int numContas = 0;

void cadastrarCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;

    printf("Digite o CPF do cliente: ");
    scanf("%s", novoCliente.cpf);
    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);
    printf("Digite o endereco do cliente: ");
    scanf("%s", novoCliente.endereco);
    printf("Digite a profissao do cliente: ");
    scanf("%s", novoCliente.profissao);

    clientes[numClientes++] = novoCliente;
}

void cadastrarConta() {
    if (numContas >= MAX_CONTAS) {
        printf("Limite de contas atingido.\n");
        return;
    }

    Conta novaConta;
    int tipoConta;

    printf("Digite o CPF do cliente: ");
    scanf("%s", novaConta.cliente.cpf);

    printf("Digite o numero da conta: ");
    scanf("%d", &novaConta.numero);
    printf("Digite o numero da agencia: ");
    scanf("%d", &novaConta.agencia);
    printf("Digite o saldo da conta: ");
    scanf("%f", &novaConta.saldo);

    printf("Escolha o tipo de conta (0 para corrente, 1 para poupanca): ");
    scanf("%d", &tipoConta);

    if (tipoConta == 0) {
        novaConta.tipo = 0;
        printf("Digite o limite da conta corrente: ");
        scanf("%f", &novaConta.limite);
    } else if (tipoConta == 1) {
        novaConta.tipo = 1;
        novaConta.limite = 0;
    } else {
        printf("Tipo de conta invalido.\n");
        return;
    }

    contas[numContas++] = novaConta;
}

void depositar() {
    int numeroConta;
    float valor;

    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numeroConta) { // verificar se o número da conta é igual ao número informado pelo usuário 
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor);
            contas[i].saldo += valor; // Adiciona o valor depositado ao saldo da conta encontrada
            printf("Deposito realizado com sucesso. Saldo atual: %.2f\n", contas[i].saldo);
            return;
        }
    }

    printf("Conta nao encontrada.\n");
}

void sacar() {
    int numeroConta;
    float valor;

    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numeroConta) {
            printf("Digite o valor a ser sacado: ");
            scanf("%f", &valor);

            if (valor > (contas[i].saldo + contas[i].limite)) {
                printf("Saldo insuficiente.\n");
                return;
            }

            if (contas[i].tipo == 0 && valor > (contas[i].saldo + contas[i].limite)) {
                printf("Saque nao permitido. Saldo insuficiente.\n");
                return;
            }

            contas[i].saldo -= valor;
            printf("Saque realizado com sucesso. Saldo atual: %.2f\n", contas[i].saldo);
        }
    }
    printf("Conta nao encontrada.\n");
}


// função para calcular o rendimento

void calcularRendimento(){
    int numeroConta;
    float taxaJuros;

    printf("Informe o numero da conta: ");
    scanf("%d", &numeroConta);

    printf("Informe a taxa de juros: ");
    scanf("%f", &taxaJuros);

    for(int i = 0; i < numContas; i++){
        if(contas[i].numero == numeroConta && contas[i].tipo == 1){
            float rendimento = contas[i].saldo * (taxaJuros / 100);
            contas[i].saldo += rendimento;
            printf("Rendimento calculado com sucesso. Saldo atual: %.2f\n", contas[i].saldo);
            return;
        }
    }
    printf("Conta poupanca nao encontrada.\n");
}

void verificarStatusConta(){
    char cpf[12];

    printf("Informe o CPF do cliente: ");
    scanf("%s", cpf);

    int encontradas = 0;

    for(int i = 0; i < numContas; i++){
        if(strcmp(contas[i].cliente.cpf, cpf) == 0){
            encontradas++;
            printf("%d - Conta %s\n", encontradas, contas[i].tipo == 0 ? "Corrente" : "Poupança");
        }
    }
    if(encontradas == 0){
        printf("Cliente não encontrado.\n");
        return;
    }

    int opcaoConta;
    printf("Escolha a conta: ");
    scanf("%d", &opcaoConta);

    int encontradasNovamente = 0;

    for(int i = 0; i < numContas; i++){
        if(strcmp(contas[i].cliente.cpf, cpf) == 0){
            encontradasNovamente++;
            if(encontradasNovamente == opcaoConta){
                printf("Nome do cliente: %s\n", contas[i].cliente.nome);
                printf("Saldo da conta: %.2f\n", contas[i].saldo);
                printf("Limite da conta: %.2f\n", contas[i].limite);
                return;
            }
        }
    }
    printf("Erro ao selecionar conta.\n");
}

int main() {
    int opcao;

    do {
        printf("\n=== Menu ===\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar conta\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Calcular rendimento da poupanca\n");
        printf("6 - Verificar status da conta\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarConta();
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                calcularRendimento();
                break;
            case 6:
                verificarStatusConta();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao !=0);

    return 0;
}