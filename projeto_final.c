#include <stdio.h>
#include <stdlib.h>

int main() {
    // Menu principal

    int opcao;
    double num1, num2, resultado;
    char continuar;
    char entrada[100];
    char *fim;

    do {
        printf("===============================\n    Simple Calculator\n===============================\n");

        // Solicita ao usuário que escolha uma operação
        printf("Select an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\nOption: ");

        // Valida a opção escolhida
        do {
            if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
                return 0;
            }

            long valor = strtol(entrada, &fim, 10);

            while (*fim == ' ' || *fim == '\t' || *fim == '\n' || *fim == '\r') {
                fim++;
            }

            if (fim == entrada || *fim != '\0' || valor < 1 || valor > 5) {
                printf("Invalid option.\n");
                printf("Option: ");
            } else {
                opcao = (int)valor;
                break;
            }

        } while (1);

        // Solicita ao usuário que insira dois números
        if (opcao >= 1 && opcao <= 4) {

            printf("Enter the first number: ");

            if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
                return 0;
            }

            num1 = strtod(entrada, &fim);

            while (*fim == ' ' || *fim == '\t' || *fim == '\n' || *fim == '\r') {
                fim++;
            }

            if (fim == entrada || *fim != '\0') {
                printf("Invalid number.\n");
                continue;
            }

            printf("Enter the second number: ");

            if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
                return 0;
            }

            num2 = strtod(entrada, &fim);

            while (*fim == ' ' || *fim == '\t' || *fim == '\n' || *fim == '\r') {
                fim++;
            }

            if (fim == entrada || *fim != '\0') {
                printf("Invalid number.\n");
                continue;
            }

        } else if (opcao == 5) {
            printf("Thank you for using the calculator! See you next time.\n");
            break;
        }

        // Realiza a operação selecionada
        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Result: %g + %g = %g\n", num1, num2, resultado);
                break;

            case 2:
                resultado = num1 - num2;
                printf("Result: %g - %g = %g\n", num1, num2, resultado);
                break;

            case 3:
                resultado = num1 * num2;
                printf("Result: %g * %g = %g\n", num1, num2, resultado);
                break;

            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Result: %g / %g = %g\n", num1, num2, resultado);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
        }

        // Continuar ou sair do programa
        do {
            printf("Do you want to perform another operation? (y/n): ");

            if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
                return 0;
            }

            char *resposta = entrada;

            while (*resposta == ' ' || *resposta == '\t') {
                resposta++;
            }

            continuar = *resposta;

            if (continuar == 'Y') {
                continuar = 'y';
            } else if (continuar == 'N') {
                continuar = 'n';
            }

            resposta++;

            while (*resposta == ' ' || *resposta == '\t' ||
                   *resposta == '\n' || *resposta == '\r') {
                resposta++;
            }

            if ((continuar != 'y' && continuar != 'n') || *resposta != '\0') {
                printf("Invalid response. Please type 'y' for yes or 'n' for no.\n");
                continuar = '\0';
            }

        } while (continuar != 'y' && continuar != 'n');

        if (continuar == 'n') {
            printf("Thank you for using the calculator! See you next time.\n");
        }

    } while (continuar == 'y');

    return 0;
}
