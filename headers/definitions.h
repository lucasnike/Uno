#define MAX_LINE 100
#define MAX_ACTION 10
#define MAX_ID_SIZE 10

#ifndef DEF
#define DEF
// Structs
typedef struct CardTag
{
    char number[3];
    char type[4];
} Card;

typedef struct HandTag
{
    Card *cards;
    int count;
} Hand;

#endif