#ifndef TRUCO_H
#define TRUCO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo as constantes do jogo
#define NUM_CARTAS_SUJO 40 // Número de cartas no baralho sujo
#define NUM_CARTAS_LIMPO 28 // Número de cartas no baralho limpo
#define NUM_JOGADORES 4 // Número de jogadores na partida
#define NUM_CARTAS_MAO 3 // Número de cartas na mão de cada jogador
#define NUM_PONTOS 12 // Número de pontos para ganhar a partida
#define NUM_NAIPES 4 // Número de naipes das cartas
#define NUM_NUMEROS_SUJO 10 // Número de números das cartas (baralho sujo)
#define NUM_NUMEROS_LIMPO 7 // Número de números das cartas (baralho limpo)

// Definindo as estruturas de dados
typedef struct carta {
    int numero; // Número da carta (4 a 7, Q, J, K, A, 2, 3)
    int naipe; // Naipe da carta (0 = ouros, 1 = espadas, 2 = copas, 3 = paus)
    int manilha; // Indica se a carta é manilha (0 = não, 1 = sim)
    int valor; // Valor da carta na ordem de força (0 a 9, sendo 9 a manilha mais fraca)
} Carta;

typedef struct jogador {
    Carta mao[NUM_CARTAS_MAO]; // Cartas na mão do jogador
    int pontos; // Pontos do jogador na partida
    int equipe; // Equipe do jogador (0 ou 1)
    int vez; // Indica se é a vez do jogador (0 = não, 1 = sim)
    int truco; // Indica se o jogador pode pedir truco (0 = não, 1 = sim)
} Jogador;

typedef struct mesa {
    Carta vira; // Carta que define as manilhas
    Carta rodada[NUM_JOGADORES]; // Cartas jogadas na rodada
    int valor_mao; // Valor da mão em pontos
    int rodada_atual; // Número da rodada atual (1, 2 ou 3)
    int mao_atual; // Número da mão atual
    int equipe_rodada; // Equipe que ganhou a rodada anterior
    int equipe_mao; // Equipe que ganhou a mão anterior
} Mesa;

// Protótipos das funções
void embaralhar(Carta baralho[], int num_cartas); // Embaralha as cartas
void distribuir(Carta baralho[], Jogador jogadores[NUM_JOGADORES]); // Distribui as cartas para os jogadores
void definir_vira_e_manilhas(Carta baralho[], Mesa *mesa, int num_numeros); // Define o vira e as manilhas
void ordenar_mao(Jogador *jogador); // Ordena a mão do jogador de acordo com o valor das cartas
void mostrar_mao(Jogador jogador); // Mostra a mão do jogador na tela
void jogar_carta(Jogador *jogador, Mesa *mesa, int indice); // Joga uma carta na mesa
int comparar_cartas(Carta c1, Carta c2); // Compara duas cartas e retorna 1 se a primeira é maior, -1 se a segunda é maior e 0 se são iguais
int verificar_vencedor_rodada(Mesa mesa); // Verifica qual equipe venceu a rodada e retorna 0 ou 1
int verificar_vencedor_mao(Mesa mesa); // Verifica qual equipe venceu a mão e retorna 0 ou 1
int verificar_vencedor_partida(Jogador jogadores[NUM_JOGADORES]); // Verifica se alguma equipe venceu a partida e retorna 0 ou 1
void atualizar_pontos(Jogador jogadores[NUM_JOGADORES], Mesa *mesa, int equipe); // Atualiza os pontos da equipe vencedora da mão
void limpar_rodada(Mesa *mesa); // Limpa as cartas jogadas na rodada
void limpar_mao(Jogador jogadores[NUM_JOGADORES], Mesa *mesa); // Limpa as cartas na mão dos jogadores
void limpar_partida(Jogador jogadores[NUM_JOGADORES], Mesa *mesa); // Limpa os pontos e as cartas dos jogadores e da mesa
void pedir_truco(Jogador *jogador, Mesa *mesa); // Pede truco e aumenta o valor da mão
void aceitar_truco(Jogador *jogador, Mesa *mesa); // Aceita o truco e continua a mão
void recusar_truco(Jogador *jogador, Mesa *mesa); // Recusa o truco e perde a mão
void mostrar_placar(Jogador jogadores[NUM_JOGADORES]); // Mostra o placar da partida na tela
void mostrar_rodada(Mesa mesa); // Mostra as cartas jogadas na rodada na tela
void mostrar_vira(Mesa mesa); // Mostra a carta que é a vira na tela
void mostrar_mensagem(char *mensagem); // Mostra uma mensagem na tela
void pausar(); // Pausa o programa até o usuário pressionar uma tecla
int ler_opcao(int min, int max); // Lê uma opção do usuário entre um valor mínimo e máximo

#endif // TRUCO_H