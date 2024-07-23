#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<locale.h>

#define MAX 40
#define NUM_PESSOAS 2

struct pessoa
{
    char nome[MAX];
    char cpf[MAX];
    char email[MAX];
    char telefone[MAX];
    int (*verificaCPF) (char *);
    int (*verificaEmail) (char *);
};

int verificaCPF(char *cpf) {
    int i, verificador1, verificador2;
    int divisao = 0, soma = 0;
    int multiplicador1 [10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int multiplicador2 [11] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int resultado1 [11] = {0};
    int resultado2 [11] = {0};
    char CPFAux [12];

    strncpy(CPFAux, cpf, 11);

    for(i=0; i<11; i++) {
        CPFAux[i] = CPFAux[i] - 48;
    }

    for(i=0; i<9; i++) {
        resultado1[i] = CPFAux[i] * multiplicador1 [i];
        soma += resultado1[i];
    }

    divisao = soma % 11;
        if(divisao < 2) {
            verificador1 = 0;
        } else {
            verificador1 = 11 - divisao;
        }
    soma = 0;

    for(i=0; i<10; i++) {
        resultado2[i] = CPFAux[i] * multiplicador2 [i];
        soma += resultado2[i];
    }

    divisao = soma % 11;
        if(divisao < 2) {
            verificador2 = 0;
        } else {
            verificador2 = 11 - divisao;
        }

        if(verificador1 == CPFAux[9] && verificador2== CPFAux[10]) {
            return 1;
        } else {
            return 0;
        }
}

int verifCPFDuplicado(struct pessoa *p, int posicao, char *CPFAux) {
    for (int i = 0; i < NUM_PESSOAS; i++) {
        if (strcmp(p[i].cpf, CPFAux) == 0 && posicao != i ) {
            return 1;
        }
    }
    return 0;
}

int verifEmailDuplicado(struct pessoa *p, int posicao, char *email) {
    for (int i = 0; i < NUM_PESSOAS; i++) {
        if (strcmp(p[i].email, email) == 0 && posicao != i) {
            return 1;
        }
    }
    return 0;
}

int buscarPorCPF(struct pessoa *pessoas, int numPessoas, char *cpf) {
    for (int i = 0; i < numPessoas; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}


int verificaEmail (char *email) {
    int i;

        if(strstr(email, "@") != NULL && strstr(email, ".com") != NULL) {
            return 1;
        } else {
            return 0;
        }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct pessoa *p;
    int cpfValido;
    int emailValido;
    int i, repetido, qtdPessoas;
    int opcao;

    do{
    printf("Quantas pessoas você deseja cadastrar? ");
    scanf("%d", &qtdPessoas);
        if(qtdPessoas >0 &&  qtdPessoas <10){
        p = (struct pessoa*) malloc(qtdPessoas *sizeof (struct pessoa));
        }else{
        printf("Número inválido, tente algo entre 1 e 9");}
    }while (qtdPessoas <= 0 || qtdPessoas >= 10);

    getchar ();

    for(i=0; i<qtdPessoas; i++){
    printf("\nCADASTRO PESSOA %d: \n", i+1);

    printf("Qual o seu nome? \n");
    fgets(p[i].nome, sizeof(p[i].nome), stdin);
    p[i].nome[strcspn(p[i].nome, "\n")] = 0;
    system("cls");

    do{
    printf("Qual o seu CPF? (Apenas números )\n");
    fgets(p[i].cpf, sizeof(p[i].cpf), stdin);
    p[i].cpf[strcspn(p[i].cpf, "\n")] = 0;

    repetido = verifCPFDuplicado(p, i, p[i].cpf);
            if (repetido) {
                printf("CPF já cadastrado! Tente novamente.\n\n");
                cpfValido = 0;
                continue;
            }

    p[i].verificaCPF = verificaCPF;
    cpfValido = p[i].verificaCPF(p[i].cpf);

    system("cls");
        if(cpfValido){
            printf("CPF VÁLIDO!\n\n");
        }else{
            printf("CPF INVÁLIDO! Tente novamente: \n\n");
        }
    }while(!cpfValido);

    do{
    printf("Qual o seu E-mail? \n");
    fgets(p[i].email, sizeof(p[i].email), stdin);
    p[i].email[strcspn(p[i].email, "\n")] = 0;

    repetido = verifEmailDuplicado(p, i, p[i].email);
            if (repetido) {
                printf("Email já cadastrado! Tente novamente.\n\n");
                emailValido = 0;
                continue;
            }

    p[i].verificaEmail = verificaEmail;
    emailValido = p[i].verificaEmail(p[i].email);

    system("cls");
        if(emailValido){
            printf("EMAIL VÁLIDO!\n\n");
        }else{
            printf("EMAIL INVÁLIDO! Tente novamente: \n\n");
        }
    }while(!emailValido);

    printf("Qual o seu telefone? \n");
    fgets(p[i].telefone, sizeof(p[i].telefone), stdin);
    p[i].telefone[strcspn(p[i].telefone, "\n")] = 0;
    system("cls");
    }

    do {
        printf("\nMenu:\n");
        printf("1. Mostrar dados das pessoas\n");
        printf("2. Buscar pessoa por CPF\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\nSeus dados são: \n\n");
                for (i = 0; i < qtdPessoas; i++) {
                    printf("Pessoa %d: \n", i + 1);
                    printf("Nome: %s\n", p[i].nome);
                    printf("CPF: %s\n", p[i].cpf);
                    printf("E-mail: %s\n", p[i].email);
                    printf("Telefone: %s\n\n", p[i].telefone);
                }
                break;

                case 2: {
                char cpfBusca[MAX];
                printf("Digite o CPF a ser buscado: ");
                fgets(cpfBusca, sizeof(cpfBusca), stdin);
                cpfBusca[strcspn(cpfBusca, "\n")] = 0;
                int posicao = buscarPorCPF(p, qtdPessoas, cpfBusca);
                    if (posicao != -1) {
                        printf("\nPessoa encontrada:\n");
                        printf("Nome: %s\n", p[posicao].nome);
                        printf("CPF: %s\n", p[posicao].cpf);
                        printf("E-mail: %s\n", p[posicao].email);
                        printf("Telefone: %s\n\n", p[posicao].telefone);
                    } else {
                        printf("\nPessoa não encontrada com o CPF fornecido.\n");
                    }
                    break;
            }
                case 3:
                    printf("Saindo...\n");
                    break;
                    default:
                    printf("Opção inválida! Tente novamente.\n");
            }
    } while (opcao != 3);


    free (p);
    return 0;
}
