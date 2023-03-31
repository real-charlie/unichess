#ifndef UNICHESS_ERROR_H
#define UNICHESS_ERROR_H

#define PD_ERARG 10
#define PD_ERINP 12
#define PD_ERSYN 17

#define PD_INFMT 23

/**
 * Prints a matched error message to stderr by an error code
 *
 * @param error_code Error code usually returned by a project defined integer-returning function
 * @param fatal Exit the program if the error was fatal
 * */
extern void handle_errc(const int error_code, int exit_fatal);

#endif //UNICHESS_ERROR_H
