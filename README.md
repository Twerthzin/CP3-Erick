## 📋 Informações do Projeto

| Campo | Informação |
|-------|-------------|
| **Disciplina** | Data Structure and Algorithms |
| **Curso** | Ciência da Computação |
| **Desenvolvedor** | João Guilherme Figueiredo |
| **RM** | 572697 |
| **Tipo de Entrega** | Individual |

---

## 🎯 Descrição do Sistema

Este projeto consiste em um **simulador de Caixa Eletrônico (ATM - Automated Teller Machine)** desenvolvido em linguagem C, executado via terminal/console. O sistema permite realizar operações bancárias básicas de forma segura e intuitiva, aplicando os conceitos fundamentais da disciplina:

- ✅ Estruturas de decisão (`switch-case`)
- ✅ Estruturas de repetição (`do-while`)
- ✅ Funções e modularização
- ✅ Validação de dados
- ✅ Controle de estado da aplicação

---

## ⚙️ Funcionalidades Implementadas

| # | Funcionalidade | Descrição |
|---|----------------|------------|
| **1** | **Consultar Saldo** | Exibe o valor atual disponível na conta com formatação monetária (R$ xxx.xx) |
| **2** | **Realizar Saque** | Permite sacar valores com validações de: saldo disponível, valor mínimo (R$ 1,00) e limite diário (R$ 1.000,00) |
| **3** | **Realizar Depósito** | Permite depositar valores positivos, atualizando automaticamente o saldo |
| **4** | **Extrato Bancário** | Mostra o histórico das últimas 3 operações realizadas (tipo + valor) e o saldo final |
| **0** | **Sair** | Encerra o programa de forma controlada |

### 🔒 Regras de Negócio

- ❌ **Saque negado** quando:
  - Valor solicitado > saldo disponível
  - Valor solicitado <= 0
  - Valor solicitado > limite diário (R$ 1.000,00)

- ❌ **Depósito negado** quando:
  - Valor <= 0

- ✅ **Histórico**:
  - Armazena as últimas 3 operações (Saque ou Depósito)
  - Exibe na ordem cronológica inversa (mais recente primeiro)

---

## 🚀 Como Compilar e Executar

### Pré-requisitos (Eu só utilizei o Dev-C++)

- Ter um compilador C instalado (GCC, MinGW ou Dev-C++)

### Opção 1: Usando Dev-C++ (Eu usei e preferi!)

1. Baixe e instale o [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/)
2. Abra o programa e clique em `Arquivo > Novo > Código Fonte`
3. Cole todo o código do arquivo `main.c`
4. Salve o arquivo com extensão `.c` (ex: `atm.c`)
5. Compile: clique em `Executar > Compilar` ou pressione `F9`
6. Execute: clique em `Executar > Executar` ou pressione `F10`

### Opção 2: Usando GCC no Terminal (Windows)

```bash
# Compilar o programa
gcc main.c -o atm.exe

# Executar o programa
atm.exe
'''
### Observações finais:
#### Prof, utilizei IA para corrigir os códigos, porém conseguir usar uma lógica "autoritária", fiz de cabeça... espero que tenha dado certo!
#### Utilizei um compilador online para tentar ter um outra experiência rodando, como se fosse uma experiência de usuário MESMO...