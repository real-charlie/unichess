#include <malloc.h>
#include <string.h>
#include "../headers/handle_arg.h"
#include "../headers/error.h"
#include "../headers/sime_game.h"

int assign_args(int argc, char **args) {
    int is_arg = 0;
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < strlen(args[i]); j++) {
            if (is_arg) {
                if (args[i][j] == 'c') {
                    continue;
                }
            }

            if (args[i][j] == '-' && !is_arg) {
                is_arg = 1;
            } else if (args[i][j] == ' ') {
                is_arg = 0;
            } else if ((args[i][j] == '-' && is_arg) || !((args[i][j] >= 'a' && args[i][j] <= 'z') || (args[i][j] >= 'A' && args[i][j] <= 'Z'))) {
                return PD_ERSYN;
            }
        }
    }

    return 0;
}

int proc_args(int argc, char **argv) {
    if (argc <= 1) {
        gmi_prompt();
        return 0;
    }

    char **args = malloc(argc);

    for (int i = 1; i < argc; i++) {
        const char *curr = argv[i];
        args[i - 1] = malloc(sizeof(curr));
        strcpy(args[i - 1], curr);
    }

    int err_code = assign_args(argc - 1, args);

    for (int i = 1; i < argc; i++)
        free(args[i - 1]);
    free(args);

    return err_code;
}
