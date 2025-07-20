#include <stdio.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função que calcula a densidade
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1490.0, 60, 0};
    Carta carta2 = {"Argentina", 45100000, 2780400.0, 500.0, 40, 0};

    // Cálculo das densidades
    carta1.densidade = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidade = calcularDensidade(carta2.populacao, carta2.area);

    int opcao;

    // Menu de escolha
    printf("===== COMPARADOR DE CARTAS - SUPER TRUNFO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n", carta1.nome, carta2.nome);

    switch (opcao) {
        case 1:
            printf("População:\n%s: %d\n%s: %d\n", carta1.nome, carta1.populacao, carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Área:\n%s: %.2f km²\n%s: %.2f km²\n", carta1.nome, carta1.area, carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("PIB:\n%s: %.2f bilhões\n%s: %.2f bilhões\n", carta1.nome, carta1.pib, carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Pontos Turísticos:\n%s: %d\n%s: %d\n", carta1.nome, carta1.pontosTuristicos, carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Densidade Demográfica:\n%s: %.2f hab/km²\n%s: %.2f hab/km²\n", carta1.nome, carta1.densidade, carta2.nome, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta1.nome); // Menor vence
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opção inválida! Por favor, escolha de 1 a 5.\n");
    }

    return 0;
}
