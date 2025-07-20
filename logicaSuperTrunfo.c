
        #include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para exibir atributos numéricos
void mostrarValor(Carta c, int opcao) {
    switch(opcao) {
        case 1: printf("%d", c.populacao); break;
        case 2: printf("%.2f", c.area); break;
        case 3: printf("%.2f", c.pib); break;
        case 4: printf("%d", c.pontosTuristicos); break;
        case 5: printf("%.2f", c.densidade); break;
    }
}

// Função que retorna o valor do atributo para soma
float obterValor(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Nome do atributo para exibir
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "";
    }
}

int main() {
    // Cartas fixas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1490.0, 60, 0};
    Carta carta2 = {"Argentina", 45100000, 2780400.0, 500.0, 40, 0};

    // Cálculo das densidades
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int opcao1, opcao2;

    // MENU 1 - Primeiro atributo
    printf("===== SUPER TRUNFO - COMPARAÇÃO DUPLA =====\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    if(opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida!\n");
        return 1;
    }

    // MENU 2 - Segundo atributo (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1)
            printf("%d. %s\n", i, nomeAtributo(i));
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if(opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opção inválida ou repetida!\n");
        return 1;
    }

    printf("\nComparando %s e %s:\n", carta1.nome, carta2.nome);

    // Mostrar valores
    printf("\nAtributo 1 - %s:\n", nomeAtributo(opcao1));
    printf("%s: ", carta1.nome); mostrarValor(carta1, opcao1); printf("\n");
    printf("%s: ", carta2.nome); mostrarValor(carta2, opcao1); printf("\n");

    printf("\nAtributo 2 - %s:\n", nomeAtributo(opcao2));
    printf("%s: ", carta1.nome); mostrarValor(carta1, opcao2); printf("\n");
    printf("%s: ", carta2.nome); mostrarValor(carta2, opcao2); printf("\n");

    // Comparação por atributo 1
    int resultado1;
    if (opcao1 == 5) { // densidade
        resultado1 = carta1.densidade < carta2.densidade ? 1 : (carta2.densidade < carta1.densidade ? 2 : 0);
    } else {
        float v1 = obterValor(carta1, opcao1);
        float v2 = obterValor(carta2, opcao1);
        resultado1 = v1 > v2 ? 1 : (v2 > v1 ? 2 : 0);
    }

    // Comparação por atributo 2
    int resultado2;
    if (opcao2 == 5) {
        resultado2 = carta1.densidade < carta2.densidade ? 1 : (carta2.densidade < carta1.densidade ? 2 : 0);
    } else {
        float v1 = obterValor(carta1, opcao2);
        float v2 = obterValor(carta2, opcao2);
        resultado2 = v1 > v2 ? 1 : (v2 > v1 ? 2 : 0);
    }

    // Soma total
    float soma1 = obterValor(carta1, opcao1) + obterValor(carta1, opcao2);
    float soma2 = obterValor(carta2, opcao1) + obterValor(carta2, opcao2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    // Resultado final
    printf("\nResultado Final:\n");
    if (soma1 > soma2) {
        printf("%s venceu a rodada!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu a rodada!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
