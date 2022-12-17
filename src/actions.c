#include "../headers/definitions.h"
#include "../headers/cards.h"
#include <stdio.h>
#include <string.h>

// Retorna uma carta com o número vazio e o naipe com a maior quantidade na mão
Card decide_card_type(Hand *hand)
{
    typedef struct
    {
        Card card;
        int qtd;
    } Card_Qtd;

    Card_Qtd copas = {.qtd = 0};
    strcpy(copas.card.type, "♥");

    Card_Qtd espada = {.qtd = 0};
    strcpy(espada.card.type, "♠");

    Card_Qtd paus = {.qtd = 0};
    strcpy(paus.card.type, "♣");

    Card_Qtd ouro = {.qtd = 0};
    strcpy(ouro.card.type, "♦");

    Card_Qtd cards[] = {copas, espada, paus, ouro};

    for (int i = 0; i < hand->count; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (compare_cards_types(hand->cards[i], cards[j].card) && strchr("CA", hand->cards[i].number[0]) == NULL)
            {
                cards[j].qtd += 1;
            }
        }
    }

    int maior = -1;
    Card type = {0};

    for (int i = 0; i < 4; i++)
    {
        if (cards[i].qtd > maior)
        {
            maior = cards[i].qtd;
            type = cards[i].card;
        }
    }

    return type;
}

// Retorna a melhor carta a ser jogada
Card decide_card_to_discard(Hand *hand, Card table)
{
    Card most_type = decide_card_type(hand);

    // A melhor carta tem o mesmo número da mesa e o naipe mais comum do baralho
    Card best_card = {0};

    Card play_card = {0};
    Card type_changer = {0};

    Card valete = {0};
    Card rei = {0};

    for (int i = 0; i < hand->count; i++)
    {
        Card now = hand->cards[i];

        if (is_v(now) && compare_cards_types(now, table))
        {
            valete = now;
        }

        if (is_r(now) && compare_cards_types(now, table))
        {
            rei = now;
        }

        if (is_c(now) || is_a(now))
        {
            type_changer = now;
        }

        if ((compare_cards_numbers(now, table) || compare_cards_types(now, table)) && !is_c(now) && !is_a(now))
        {
            play_card = now;
        }

        if (compare_cards_numbers(now, table) && compare_cards_types(now, most_type))
        {
            best_card = now;
        }
        else if (compare_cards_types(now, most_type) && (compare_cards_numbers(now, table) || compare_cards_types(now, table)) && !is_c(now) && !is_a(now))
        {
            best_card = now;
        }
    }
	
    if (!is_empty(best_card))
    {
        return best_card;
    }
    // Se tiver uma carta pra jogar
    else if (!is_empty(play_card))
    {
        return play_card;
    }
    else if (!is_empty(type_changer))
    {
        return type_changer;
    }

    return play_card;
}

// Executa a açao SAY do gerenciador
void say(char *txt)
{
    printf("SAY %s\n", txt);
}

// Discarta uma carta
void discard_card(Card play_card, Hand *hand, Card *table_card)
{

    if (hand->count == 1)
        say("Estão deixando a gente sonhar!");
    if (is_a(play_card) || is_c(play_card))
        say("Esse naipe não tá preferível...");
    if (is_c(play_card) || is_v(play_card))
        say("Receba!");
    if (is_r(play_card))
        say("Deixa pra próxima!");
    if (is_d(play_card))
        say("Vamo mudar o sentido!");

    printf("DISCARD ");
    printf("%s%s", play_card.number, play_card.type);
    *table_card = play_card;

    // Se a carta jogada for um coringa ou um às
    if (is_a(play_card) || is_c(play_card))
    {
        Card card_type = decide_card_type(hand);
        strcpy(table_card->type, card_type.type);
        printf(" %s", card_type.type);
    }

    printf("\n");

    remove_card(hand, play_card);
}

// Compra cartas
void buy_card(int qtd, Hand *hand)
{
    char temp[MAX_LINE];
    printf("BUY %d\n", qtd);

    // Lê e adiciona todas as cartas à minha mão
    for (int i = 0; i < qtd; i++)
    {
        scanf("%s\n", temp);
        Card card = read_card(temp);
        add_card(hand, card);
    }
}
