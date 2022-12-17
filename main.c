#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/definitions.h"
#include "./headers/cards.h"
#include "./headers/hand.h"
#include "./headers/actions.h"



int main()
{
    char temp[MAX_LINE];
    char my_id[MAX_ID_SIZE];
    Card table_card;

    // Aloca dinamicamente a mão com 7 posições
    Hand *hand = create_hand();

    // Esvazia todos os buffers
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    // -----------------------

    // === INÍCIO DA PARTIDA ===

    // Faz a leituras dos jogadores da partida, qual jogador eu sou e a minha mão
    scanf("PLAYERS %[^\n]\n", temp);
    scanf("YOU %s\n", my_id);
    scanf("HAND %[^\n]\n", temp);
    // ---------------------------

    // Salva a mão passada pelo gerenciador do uno
    read_hand(temp, hand);

    // Faz a leitura da carta na mesa
    scanf("TABLE %s\n", temp);
    table_card = read_card(temp);

    // === PARTIDA ===

    char id[MAX_ID_SIZE];
    char action[MAX_ACTION];
    char complement[MAX_LINE];
    char complement2[4];
    int last_player_discarded_V_or_C = 0;

    while (1)
    {
        do
        {
            // Escuta ações do gerenciador e dos outros jogadores
            scanf("%s %s", action, complement);

            // Se a ação for DISCARD
            if (strcmp(action, "DISCARD") == 0)
            {

                // Salva a carta descartada
                table_card = read_card(complement);

                if (is_v(table_card) || is_c(table_card))
                {
                    last_player_discarded_V_or_C = 1;
                }

                // Se a carta descartada for Ás ou Coringa
                if (is_a(table_card) || is_c(table_card))
                {

                    // Lê o naipe escolhidos pelo jogador anterior
                    scanf(" %s", complement2);

                    // Troca o naipe da carta na mesa para o naipe escolhido pelo bot
                    strcpy(table_card.type, complement2);
                }
            }
            // Se a ação for BUY
            else if (strcmp(action, "BUY") == 0)
            {
                last_player_discarded_V_or_C = 0;
            }

					if(strcmp(action, "TURN") == 0){
						
					}

        } while (strcmp(action, "TURN") || strcmp(complement, my_id));
        // Reação BUY obrigatória
        if (last_player_discarded_V_or_C)
        {
            if (is_c(table_card))
            {
                say("Te pego na saída!");
                buy_card(4, hand);
            }
            else if (is_v(table_card))
            {
                say("Mas que droga!");
                buy_card(2, hand);
            }
            last_player_discarded_V_or_C = 0;
            continue;
        }
        // ------------------------------------------------

        Card play_card = decide_card_to_discard(hand, table_card);
        // Se eu tiver cartas do mesmo naipe o do mesmo número
        if (!is_empty(play_card))
        {
            discard_card(play_card, hand, &table_card);
        }
        else
        {
            buy_card(1, hand);
        }
    }

    return 0;
}