#include "definitions.h"

#ifndef CARDS
#define CARDS
int compare_cards(Card, Card);
int compare_cards_numbers(Card, Card);
int compare_cards_types(Card, Card);
void add_card(Hand*, Card);
void remove_card(Hand*, Card);

Card read_card(char*);

int is_v(Card);
int is_c(Card);
int is_a(Card);
int is_d(Card);
int is_r(Card);
int is_empty(Card);
#endif