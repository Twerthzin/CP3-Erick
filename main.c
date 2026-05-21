#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char tipo[10];
    float valor;
} Operacao;


Operacao historico[3];
int totalOperacoes = 0;


void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void registrarOperacao(const char *tipo, float valor);
void exibirExtrato(float saldoAtual);
void limparBuffer();
void pausarTela();

int main() {
    float saldo = 1250.50; 
    int opcao;
    
   
    for(int i = 0; i < 3; i++) {
        historico[i].tipo[0] = '\0';
        historico[i].valor = 0.0;
    }
    
    do {
        system("cls"); 
        
        
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo);
                break;
            case 3:
                saldo = realizarDeposito(saldo);
                break;
            case 4:
                exibirExtrato(saldo);
                break;
            case 0:
                printf("\n================================\n");
                printf("  OBRIGADO POR USAR NOSSO ATM!\n");
                printf("================================\n");
                break;
            default:
                printf("\n*** OPCAO INVALIDA! ***\n");
                printf("Digite uma opcao entre 0 e 4.\n");
        }
        
        if(opcao != 0) {
            pausarTela();
        }
        
    } while(opcao != 0);
    
    return 0;
}


void exibirMenu() {
    printf("\n================================\n");
    printf("       CAIXA ELETRONICO         \n");
    printf("================================\n");
    printf("                               \n");
    printf("    1 - CONSULTAR SALDO         \n");
    printf("    2 - REALIZAR SAQUE          \n");
    printf("    3 - REALIZAR DEPOSITO       \n");
    printf("    4 - EXTRATO                 \n");
    printf("    0 - SAIR                    \n");
    printf("                               \n");
    printf("================================\n");
    printf("    ESCOLHA UMA OPCAO: ");
}


void consultarSaldo(float saldo) {
    printf("\n+------------------------------+\n");
    printf("|        SALDO ATUAL           |\n");
    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|    R$ %10.2f             |\n", saldo);
    printf("|                              |\n");
    printf("+------------------------------+\n");
}


float realizarSaque(float saldo) {
    float valor;
    const float LIMITE_DIARIO = 1000.00;
    
    printf("\n+------------------------------+\n");
    printf("|        OPERACAO DE SAQUE     |\n");
    printf("+------------------------------+\n");
    printf("| Saldo disponivel: R$ %.2f    |\n", saldo);
    printf("| Limite por saque: R$ %.2f   |\n", LIMITE_DIARIO);
    printf("+------------------------------+\n");
    printf("| Digite o valor do saque: R$ ");
    scanf("%f", &valor);
    limparBuffer();
    
    
    if(valor <= 0) {
        printf("\n*** OPERACAO NEGADA! ***\n");
        printf("Valor invalido. Digite um valor positivo.\n");
    }
    else if(valor > LIMITE_DIARIO) {
        printf("\n*** OPERACAO NEGADA! ***\n");
        printf("Valor excede o limite diario de R$ %.2f\n", LIMITE_DIARIO);
    }
    else if(valor > saldo) {
        printf("\n*** OPERACAO NEGADA! ***\n");
        printf("Saldo insuficiente.\n");
        printf("Saldo atual: R$ %.2f\n", saldo);
    }
    else {
        saldo -= valor;
        printf("\n*** SAQUE REALIZADO COM SUCESSO! ***\n");
        printf("Valor sacado: R$ %.2f\n", valor);
        printf("Novo saldo: R$ %.2f\n", saldo);
        
        
        registrarOperacao("Saque", valor);
    }
    
    return saldo;
}


float realizarDeposito(float saldo) {
    float valor;
    
    printf("\n+------------------------------+\n");
    printf("|      OPERACAO DE DEPOSITO    |\n");
    printf("+------------------------------+\n");
    printf("| Digite o valor do deposito: R$ ");
    scanf("%f", &valor);
    limparBuffer();
    
    if(valor <= 0) {
        printf("\n*** OPERACAO NEGADA! ***\n");
        printf("Valor invalido. Digite um valor positivo.\n");
    }
    else {
        saldo += valor;
        printf("\n*** DEPOSITO REALIZADO COM SUCESSO! ***\n");
        printf("Valor depositado: R$ %.2f\n", valor);
        printf("Novo saldo: R$ %.2f\n", saldo);
        
        
        registrarOperacao("Deposito", valor);
    }
    
    return saldo;
}


void registrarOperacao(const char *tipo, float valor) {

    for(int i = 2; i > 0; i--) {
        strcpy(historico[i].tipo, historico[i-1].tipo);
        historico[i].valor = historico[i-1].valor;
    }
    
  
    strcpy(historico[0].tipo, tipo);
    historico[0].valor = valor;
    
    if(totalOperacoes < 3) {
        totalOperacoes++;
    }
}


void exibirExtrato(float saldoAtual) {
    printf("\n+================================+\n");
    printf("|           EXTRATO              |\n");
    printf("+================================+\n");
    printf("|                                |\n");
    printf("|   ULTIMAS %d OPERACOES:          |\n", totalOperacoes);
    printf("|                                |\n");
    
    if(totalOperacoes == 0) {
        printf("|   Nenhuma operacao realizada    |\n");
    } else {
        for(int i = 0; i < totalOperacoes; i++) {
            printf("|   %d. %-8s  R$ %8.2f    |\n", 
                   i+1, historico[i].tipo, historico[i].valor);
        }
    }
    
    printf("|                                |\n");
    printf("+--------------------------------+\n");
    printf("|   SALDO ATUAL: R$ %8.2f    |\n", saldoAtual);
    printf("+================================+\n");
}


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void pausarTela() {
    printf("\n================================\n");
    printf("   Pressione Enter para continuar...");
    limparBuffer();
    getchar();
}