#ifndef UNICHESS_MOVE_ACTIONS_H
#define UNICHESS_MOVE_ACTIONS_H

#include "sime_game.h"

#define CGA_MOVE 0
#define CGA_CAPT 1
#define CGA_CHCK 2
#define CGA_PROM 3
#define CGA_MATE 4
#define CGA_UNDF (-1)

#define CP_CHAR_KNT 'N'
#define CP_CHAR_BSP 'B'
#define CP_CHAR_ROK 'R'
#define CP_CHAR_QUE 'Q'
#define CP_CHAR_KNG 'K'


#define INVALID_PIECE_NUMBER (-1)

/**
 * User move action data structure
 * */
struct c_action {
    struct piece tg_piece;
    int tg_sqrn;
    int cga;
    int color;
};

/**
 * Identifies user's action by user's given move.
 *
 * @returns An initialized c_action, c_action.cga would be -1 if action was undefined
 * @param move User's move
 * */
struct c_action id_cga(const char *move, struct cg_status *cg);

/**
 * Checks if the user's move valid or not
 *
 * @returns 0 on valid, 1 on invalid, 2 on check, 3 on stalemate, 4 on checkmate
 * @param move User's move
 * @param cg Ongoing chess game
 * */
int check_move_validity(struct c_action *cga, struct cg_status *cg);


/**
 * Checks if the target square or its way (step) is blocked by any piece or not
 *
 * @param step piece square step
 * @param from current piece square
 * @param to target piece square
 * @param cg initialized game status
 * */
int move_is_blocked(int step, int from, int to, struct cg_status *cg);


/**
 * Moves pieces as the parameter `move` interprets
 *
 * @param move Target user move
 * @param cg Active game status
 * */
int do_move(const char *move, struct cg_status *cg);

#endif //UNICHESS_MOVE_ACTIONS_H
