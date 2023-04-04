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
    printf("%d\n", do_move("a4", &d));
    printf("%d\n", do_move("a5", &d));
    printf("%d\n", do_move("a6", &d));
    printf("%d\n", do_move("a7", &d));
    printf("%d\n", do_move("a8", &d));
    char cf[3];
    printf("'a' Pawn is now at %s", c_nsqr(d.white.pawns[0].sq, cf));

    return 0;
}
