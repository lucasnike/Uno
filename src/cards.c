#include "../headers/definitions.h"
#include <string.h>
#include <stdlib.h>

// Verifica se duas cartas são iguais
int compare_cards(Card card1, Card card2)
{
    if (strcmp(card1.number, card2.number) == 0 &&
        strcmp(card1.type, card2.type) == 0)
    {
        return 1;
    }
    return 0;
}

// Verifica se os naipes de duas cartas são iguais
int compare_cards_types(Card card1, Card card2)
{
    return strcmp(card1.type, card2.type) == 0 ? 1 : 0;
}

// Verifica se os números de duas cartas são iguais
int compare_cards_numbers(Card card1, Card card2)
{
    if (strcmp(card1.number, card2.number) == 0)
    {
        return 1;
    }
    return 0;
}

// Recebe o texto da carta e retorna uma Carta
Card read_card(char *text_card)
{
    Card card = {0};
    int cont_naipe = 0;

    for (int i = 0; i < strlen(text_card); i++)
    {
        if ((text_card[i] >= 48 && text_card[i] <= 57) || strchr("VADCR", text_card[i]) != NULL)
        {
            card.number[i] = text_card[i];
            card.number[i + 1] = 0;
        }
        else
        {
            card.type[cont_naipe] = text_card[i];
            cont_naipe++;
        }
    }

    card.type[cont_naipe + 1] = 0;

    return card;
}

// Adiciona uma carta à mão e realoca as cartas
void add_card(Hand *hand, Card card)
{
    hand->count += 1;

    hand->cards = realloc(hand->cards, (hand->count) * sizeof(Card));
    hand->cards[hand->count - 1] = card;
}

// Remove uma carta da mão e realoca as cartas
void remove_card(Hand *hand, Card card)
{
    for (int i = 0; i < hand->count; i++)
    {
        if (compare_cards(hand->cards[i], card) == 1)
        {
            for (int j = i; j < hand->count; j++)
            {
                hand->cards[j] = hand->cards[j + 1];
            }

            hand->count -= 1;
            hand->cards = realloc(hand->cards, sizeof(Card) * hand->count);
            break;
        }
    }
}

// Verifica se uma carta é um valete
int is_v(Card card)
{
    Card v_card = {.number = "V"};
    return compare_cards_numbers(v_card, card) ? 1 : 0;
}

// Verifica se uma carta é um coringa
int is_c(Card card)
{
    Card c_card = {.number = "C"};
    return compare_cards_numbers(c_card, card) ? 1 : 0;
}
// Verifica se uma carta é um Ás
int is_a(Card card)
{
    Card a_card = {.number = "A"};
    return compare_cards_numbers(a_card, card) ? 1 : 0;
}

// Verifica se uma carta é uma Dama
int is_d(Card card)
{
    Card d_card = {.number = "D"};
    return compare_cards_numbers(d_card, card) ? 1 : 0;
}

// Verifica se uma carta é um Rei
int is_r(Card card)
{
    Card r_card = {.number = "R"};
    return compare_cards_numbers(r_card, card) ? 1 : 0;
}

// Verifica se uma carta está vazia
int is_empty(Card card)
{
    Card empty = {0};
    return compare_cards(card, empty) ? 1 : 0;
}