all: main.c cards hand actions
	gcc main.c obj/cards.o obj/actions.o obj/hand.o -o bin/inocente3 -g -Wno-unused-result -pedantic


cards: src/cards.c
	gcc src/cards.c -c -g -W -pedantic -o obj/cards.o


hand: src/hand.c
	gcc src/hand.c -c -g -W -pedantic -o obj/hand.o


actions: src/actions.c
	gcc src/actions.c -c -g -W -pedantic -o obj/actions.o