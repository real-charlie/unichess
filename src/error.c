#include "../headers/error.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @returns -1 if error was fatal, 1 if error was not fatal
 * */
int err_msg_handle(const int *error_code) {
    switch (*error_code) {
        case PD_INFMT:
            fprintf(stderr, "Invalid format for the square\n");
            return 1;
        case PD_ERARG:
            fprintf(stderr, "Invalid argument\n");
            return -1;
        case PD_ERINP:
            fprintf(stderr, "Invalid value given for the argument\n");
            return -1;
        case PD_ERSYN:
            fprintf(stderr, "Invalid syntax given as a flag. Flags should be of [a-zA-Z]+");
            return -1;
    }
    return 0;
}

void handle_errc(const int error_code, int exit_fatal) {
    if (error_code == 0)
        return;

    const int errors[] = {PD_INFMT, PD_ERARG, PD_ERINP, PD_ERSYN};
    int error_status = 0;

    for (int i = 0; i < sizeof(errors) / 4; i++) {
        int curr_err = errors[i];
        if ((error_code & curr_err) == curr_err) {
            if (err_msg_handle(&curr_err) == -1) {
                error_status = -1;
            }
        }
    }

    if (error_status == -1 && exit_fatal) {
        fprintf(stderr, "Exiting the program because of some occurred fatal errors...\n");
        exit(WEXITSTATUS(error_code));
    }
}
