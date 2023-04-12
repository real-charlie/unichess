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
    printf("D: %d\n", d.white.rooks[1].sq);
    printf("%d\n", (cd | ca) & PB);
    printf("%s\n", c_nsqr(d.white.queens[0].sq, cc));
    printf("%d\n", do_move("d4", &d));
    printf("%d\n", do_move("d5", &d));
    printf("%d\n", do_move("Qd3", &d));

    return 0;
}
