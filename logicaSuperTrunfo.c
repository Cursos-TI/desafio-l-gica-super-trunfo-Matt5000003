#include <stdio.h>

int main() {
    // ===========================
    // Cadastro das Cartas
    // ===========================
    char codigo1[5], codigo2[5];
    char estado1[30], estado2[30];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float dens1, dens2;
    int opcao1, opcao2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Código da carta: ");
    scanf("%s", codigo1);
    printf("Nome do estado: ");
    scanf("%s", estado1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Código da carta: ");
    scanf("%s", codigo2);
    printf("Nome do estado: ");
    scanf("%s", estado2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // ===========================
    // Cálculo da Densidade Demográfica
    // ===========================
    dens1 = populacao1 / area1;
    dens2 = populacao2 / area2;

    // ===========================
    // Exibição das Cartas
    // ===========================
    printf("\n=== CARTA 1 ===\n");
    printf("Código: %s\nEstado: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           codigo1, estado1, populacao1, area1, pib1, pontos1, dens1);

    printf("\n=== CARTA 2 ===\n");
    printf("Código: %s\nEstado: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           codigo2, estado2, populacao2, area2, pib2, pontos2, dens2);

    // ===========================
    // Menu Interativo - Primeiro Atributo
    // ===========================
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida! Encerrando programa.\n");
        return 0;
    }

    // ===========================
    // Menu Interativo Dinâmico - Segundo Atributo
    // ===========================
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opção inválida! Os dois atributos devem ser diferentes.\n");
        return 0;
    }

    // ===========================
    // Comparação dos Atributos
    // ===========================
    float valor1a = 0, valor2a = 0; // primeiro atributo
    float valor1b = 0, valor2b = 0; // segundo atributo
    float soma1 = 0, soma2 = 0;

    // Função auxiliar de comparação via switch
    switch (opcao1) {
        case 1: valor1a = populacao1; valor2a = populacao2; break;
        case 2: valor1a = area1; valor2a = area2; break;
        case 3: valor1a = pib1; valor2a = pib2; break;
        case 4: valor1a = pontos1; valor2a = pontos2; break;
        case 5: valor1a = dens1; valor2a = dens2; break;
    }

    switch (opcao2) {
        case 1: valor1b = populacao1; valor2b = populacao2; break;
        case 2: valor1b = area1; valor2b = area2; break;
        case 3: valor1b = pib1; valor2b = pib2; break;
        case 4: valor1b = pontos1; valor2b = pontos2; break;
        case 5: valor1b = dens1; valor2b = dens2; break;
    }

    // Regras (densidade: menor vence)
    soma1 = ((opcao1 == 5) ? (1 / valor1a) : valor1a) + ((opcao2 == 5) ? (1 / valor1b) : valor1b);
    soma2 = ((opcao1 == 5) ? (1 / valor2a) : valor2a) + ((opcao2 == 5) ? (1 / valor2b) : valor2b);

    // ===========================
    // Exibição do Resultado
    // ===========================
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Comparando %s (Carta 1) x %s (Carta 2)\n\n", estado1, estado2);

    // Exibir valores dos dois atributos
    printf("Atributo 1: ");
    switch (opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", estado1, valor1a, estado2, valor2a);

    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", estado1, valor1b, estado2, valor2b);

    // Soma final
    printf("Soma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", estado1, soma1, estado2, soma2);

    // Operador ternário para definir vencedor
    (soma1 > soma2) ? printf("\nVencedor: %s\n", estado1) :
    (soma2 > soma1) ? printf("\nVencedor: %s\n", estado2) :
                      printf("\nEmpate!\n");

    return 0;
}
