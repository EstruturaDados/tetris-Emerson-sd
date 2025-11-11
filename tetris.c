

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_FILA 5

// Estrutura que representa uma peça
typedef struct {
    char nome;  // Tipo da peça ('I', 'O', 'T', 'L')
    int id;     // Identificador único
} Peca;

// Estrutura de Fila
typedef struct {
    Peca fila[TAMANHO_FILA];
    int inicio;
    int fim;
    int qtd;
} Fila;

// Inicializa a fila vazia
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->qtd = 0;
}

// Verifica se está cheia
int filaCheia(Fila *f) {
    return f->qtd == TAMANHO_FILA;
}

// Verifica se está vazia
int filaVazia(Fila *f) {
    return f->qtd == 0;
}

// Adiciona nova peça ao final da fila (enqueue)
void enfileirar(Fila *f, char nome, int id) {
    if (filaCheia(f)) {
        printf("\n Fila cheia! Não é possível adicionar nova peça.\n");
        return;
    }
    f->fim = (f->fim + 1) % TAMANHO_FILA;
    f->fila[f->fim].nome = nome;
    f->fila[f->fim].id = id;
    f->qtd++;
    printf("\nPeça %c (id=%d) adicionada à fila.\n", nome, id);
}

// Remove peça da frente (dequeue)
void desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("\nFila vazia! Nenhuma peça para jogar.\n");
        return;
    }
    Peca p = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_FILA;
    f->qtd--;
    printf("\n🎮 Peça %c (id=%d) jogada!\n", p.nome, p.id);
}

// Exibe o estado atual da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("\n[Fila vazia]\n");
        return;
    }

    printf("\nPeças na fila:\n");
    int i, idx;
    for (i = 0; i < f->qtd; i++) {
        idx = (f->inicio + i) % TAMANHO_FILA;
        printf(" → Peça %c (id=%d)\n", f->fila[idx].nome, f->fila[idx].id);
    }
}

// Programa principal
int main() {
    Fila fila;
    inicializarFila(&fila);

    // Inicializa com 5 peças fixas
    enfileirar(&fila, 'I', 1);
    enfileirar(&fila, 'O', 2);
    enfileirar(&fila, 'T', 3);
    enfileirar(&fila, 'L', 4);
    enfileirar(&fila, 'Z', 5);

    int opcao, idContador = 6;
    char tipo;

    do {
        printf("\n===== MENU TETRIS STACK =====\n");
        printf("1 - Jogar próxima peça\n");
        printf("2 - Adicionar nova peça\n");
        printf("3 - Exibir fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desenfileirar(&fila);
                break;
            case 2:
                printf("Informe o tipo da peça (I, O, T, L): ");
                scanf(" %c", &tipo);
                enfileirar(&fila, tipo, idContador++);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 0:
                printf("\nEncerrando o jogo.\n");
                break;
            default:
                printf("\n❌ Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}