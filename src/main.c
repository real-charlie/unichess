#include <stdio.h>
#include <malloc.h>
#include "../headers/error.h"
#include "../headers/handle_arg.h"
#include "../headers/sime_game.h"
#include "../headers/move_actions.h"

int main(int argc, char **argv) {
    struct cg_status d = cg_init();
    char cc[3];
    int cd = CGA_PROM;
    int ca = PN;
    printf("%d\n", (cd | ca) & PB);
    printf("%s\n", c_nsqr(d.white.queens[0].sq, cc));
    printf("%d\n", do_move("e4", &d));
    printf("%d\n", do_move("e5", &d));
//    printf("%d\n", do_move("e6", &d));
    printf("%d\n", do_move("Bb5", &d));
    char cf[3];
    printf("'e' Pawn is now at %s\n", c_nsqr(d.white.pawns[4].sq, cf));
    printf("'f' Bishop is now at %s", c_nsqr(d.white.bishops[1].sq, cf));

    return 0;
}
