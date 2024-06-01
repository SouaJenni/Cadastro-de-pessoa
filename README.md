# Cadastro-de-pessoa
1- Escreva um programa que cadastre uma pessoa usando Structure
   - O cadastro (Structure) deve conter: Nome, CPF, Email e Telefone. Todos são vetores de char
   - No final do programa, imprima os dados cadastrados 
2- Modifique o programa anterior:
   - Adicione uma função de validação de CPF, confira como fazer no link: https://www.macoratti.net/alg_cpf.htm
https://www.4devs.com.br/gerador_de_cpf
https://www.youtube.com/watch?v=_ApTnRHYnyw
   - Adicione uma função para validação de email. Para o email, deve permitir qualquer numero de caracteres iniciais, seguido por @, seguido por qualquer numero de caracteres, seguido por ".com"
3- Modifique o programa anterior para utilizar um vetor de usuarios, permitindo cadastrar mais de um ao mesmo tempo
4- Adicione uma validação para que o CPF nem o email seja repetidos entre os usuarios do vetor
5- Adicione um menu com as opções "Inserir usuario, Buscar usuario por CPF, buscar usuario por email, Excluir usuario, atualizar email do usuario e sair"
6- Mude a alocação do vetor de usuarios para alocação dinamica, utilizando pra isso o Malloc e ponteiro.
7- Ao iniciar o programa pergunte quantos usuarios deverão ser alocados, então faça a alocação de memória conforme o tamanho solicitado pelo usuário