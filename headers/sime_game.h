/// Starting-Interpreting-Managing-Ending Game

#ifndef UNICHESS_SIME_GAME_H
#define UNICHESS_SIME_GAME_H

#define KS_CHECK 1
#define KS_SMATE 2
#define KS_CMATE 3

#define MAX_PS_Q 9
#define MAX_PS_BNR 10
#define MAX_PS_P 8

#define PP 1
#define PN 3
#define PB 4
#define PR 5
#define PQ 9
#define PK 100

#define PROMPT_MAX_INPUT_SIZE 10

/**
 * Chess Square Number, converts a conventional chess square such as c2 or e4 to a more easy to interpret number ranges from 0-63
 *
 * @returns Square as a number or -1 for error
 * */
int c_sqrn(const char *sqr);

/**
 * Reverse action of c_sqrn()
 *
 * @returns Square as an string or an empty string for error
 * */
char* c_nsqr(int sqr_n, char* wr_to);

/**
 * Struct for each piece
 * */
 struct piece {
     int piece;
     int is_moved;
     int sq;
     int captured;
 };

/**
 * Chess Player, indicates each player's pieces squares and each piece's square in a matched array of integers.
 * */
struct c_player {
    // Available pieces
    struct piece pawns[MAX_PS_P];
    struct piece knights[MAX_PS_BNR];
    struct piece bishops[MAX_PS_BNR];
    struct piece rooks[MAX_PS_BNR];
    struct piece queens[MAX_PS_Q];

    struct piece king;

    /**
     * Indicated the king status. 0 for the default state, 1 for check, 2 for stalemate and 3 for checkmate.
     * */
    int king_status;
};

/**
 * Chess Game Status data structure
 * */
struct cg_status {

    /**
     * Indicates a chess game turn, 0 for white and 1 for black.
     * */
    int turn;

    /**
     * Indicates which player has been checkmated, 0 for none, 1 for white and 2 for black.
     * */
    int player_cmate;

    /**
     * White pieces
     * */
    struct c_player white;

    /**
     * Black pieces
     * */
    struct c_player black;

};

/**
 * Initializes a new chess game.
 *
 * @returns An initialized cg_status or Chess Game Status
 * */
struct cg_status cg_init();

/**
 * Game Move Interpreter Prompt, getting and then interpreting user moves.
 *
 * @returns An error code or 0 for success
 * */
int gmi_prompt();

#endif //UNICHESS_SIME_GAME_H
