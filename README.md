# Avaliação para Estágio em Desenvolvedor Back-End

## DESCRIÇÃO DO CASO: Conta Bancária 

Uma cooperativa de crédito foi criada e você foi designado para criar um sistema de gerenciamento de contas. Então o sistema deverá fazer o cadastro dos correntistas possuindo os dados de cpf, nome, endereço e profissão. Sendo assim, cada correntista pode ter diversas contas e para conta é mantido o cliente ao qual a conta pertence, a conta possui um número, o número da agência e o saldo.

## Regras que o sistema deverá atender:

1. O sistema deve possuir dois tipos de conta, Conta Corrente e Conta Poupança.

2. A conta corrente possui um atributo extra que é o limite da conta.

3. As contas deverão realizar operações de depósito e saque, todas estas operações deverão atualizar o saldo da conta.

4. Para os saques da conta poupança não poderá sacar mais que o saldo total.

5. Para os saques da conta corrente não poderá sacar mais que o saldo + limite.

6. Conta Poupança deverá existir uma operação que calcula o juros mensal de rendimento e aplique no saldo da conta, a taxa de juros será enviado por parâmetro.

7. Conta Corrente deverá existir uma operação que calcula o juros caso saldo seja negativo e aplique no saldo da conta, a taxa de juros será enviado por parâmetro.

