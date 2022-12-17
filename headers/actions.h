#include "../headers/definitions.h"

#ifndef ACTIONS
#define ACTIONS
void say(char *txt);
void buy_card(int, Hand*);
void discard_card(Card, Hand*, Card*);
Card decide_card_type(Hand*);
Card decide_card_to_discard(Hand*, Card);
#endif