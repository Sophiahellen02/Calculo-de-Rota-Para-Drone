#include <stdio.h>
#include <math.h>
    
int main() {
        float partida[3], destino[3], deslocamento[3];
        float distancia;
    
        printf("=== PLANEJAMENTO DE ROTA PARA DRONE ===\n\n");
    
        // Entrada da posicao inicial com validação
        while (1) {
            printf("Informe a POSICAO INICIAL do drone (x y z): ");
            if (scanf("%f %f %f", &partida[0], &partida[1], &partida[2]) == 3) {
                break; // Sai do loop se a entrada for válida
            } else {
                printf("Erro: Entrada invalida. Certifique-se de inserir tres numeros separados por espacos.\n");
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }
        }
    
        // Entrada da posicao final com validação
        while (1) {
            printf("Informe a POSICAO FINAL (DESTINO) do drone (x y z): ");
            if (scanf("%f %f %f", &destino[0], &destino[1], &destino[2]) == 3) {
                break; // Sai do loop se a entrada for v�lida
            } else {
                printf("Erro: Entrada invalida. Certifique-se de inserir tres numeros separados por espacos.\n");
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }
        }
    
        // Calcular vetor deslocamento
        for (int i = 0; i < 3; i++) {
            deslocamento[i] = destino[i] - partida[i];
        }
    
        // Calcular distancia (modulo do vetor deslocamento)
        distancia = sqrt(
            deslocamento[0] * deslocamento[0] +
            deslocamento[1] * deslocamento[1] +
            deslocamento[2] * deslocamento[2]
        );
    
        // Mostrar informacoes para o usuario
        printf("\n=== INFORMACOES DE VOO ===\n");
        printf("Deslocamento vetor: (%.2f, %.2f, %.2f)\n", deslocamento[0], deslocamento[1], deslocamento[2]);
        printf("Distancia a ser percorrida: %.2f metros\n", distancia);
    
        // Informar direcao geral (para simplificar)
        printf("\nDirecao geral do movimento:\n");
        if (deslocamento[0] > 0) printf("- Leste\n");
        if (deslocamento[0] < 0) printf("- Oeste\n");
        if (deslocamento[1] > 0) printf("- Norte\n");
        if (deslocamento[1] < 0) printf("- Sul\n");
        if (deslocamento[2] > 0) printf("- Para cima\n");
        if (deslocamento[2] < 0) printf("- Para baixo\n");
    
        printf("\nBoa viagem!\n");
    
        return 0;
}