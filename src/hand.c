#include "../headers/definitions.h"
#include "../headers/cards.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Aloca a estrutura da mão sem as cartas 
Hand *create_hand()
{
    Hand *myHand = calloc(1, sizeof(Hand));
    myHand->cards = calloc(7, sizeof(Card));
    myHand->count = 7;

    return myHand;
}

// Lê a mão passada com string e salva na variável tipo Hand
void read_hand(char *s, Hand *hand)
{
    // Declaração de variáveis
    int cont = 0;
    char *token = strtok(s, " ");

    // Percorre cada parte do texto da mão separado pelos espaços em branco
    while (token != NULL)
    {
        if (token[0] != '[' && token[0] != ']')
        {
            hand->cards[cont] = read_card(token);
            cont++;
        }
        token = strtok(NULL, " ");
    }
}