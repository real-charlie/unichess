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
    printf("%d\n", do_move("e4", &d));
    printf("%d\n", do_move("e5", &d));
    printf("%d\n", do_move("Qh3", &d));
    printf("%d\n", do_move("Ke7", &d));
    printf("%d\n", do_move("a3", &d));
    printf("%d\n", do_move("Ke6", &d));




    return 0;
}
