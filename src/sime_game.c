#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/sime_game.h"

char *c_nsqr(int sqr_n, char *wr_to) {
    if (sqr_n <= 0 || sqr_n > 64)
        return "";

    char column = 'a' - 1;
    while (sqr_n > 0) {
        sqr_n -= 8;
        column += 1;
    }

    char res[] = {column, (char) ((sqr_n + 8) + '0')};
    strcpy(wr_to, res);

    return wr_to;
}

int c_sqrn(const char *square) {
    if (strlen(square) != 2 || !(square[0] >= 'a' && square[0] <= 'h') || !(square[1] >= '1' && square[1] <= '8'))
        return -1;

    char row = square[1];
    return ((int) (square[0] - 'a')) * 8 + atoi(&row);
}

/**
 * Initializes a player and sets pieces squares for each color.
 * @param color Target color, 0 for white and 1 for black.
 * */
struct c_player player_init(int color) {
    struct c_player new_player;
    memset(&new_player, 0, sizeof(struct c_player));

    struct piece king;

    memset(&king, 0, sizeof(struct piece));
    king.sq = !color ? c_sqrn("e1") : c_sqrn("e8");
    king.piece = PK;

    new_player.king = king;

    char pawn_row = !color ? '2' : '7';
    struct piece *porder[] = {new_player.rooks, new_player.knights, new_player.bishops, new_player.queens};

    struct piece piece;
    memset(&piece, 0, sizeof(struct piece));

    for (int i = 0; i < 8; i++) {
        char res[2] = {(char) ((int) 'a' + i), pawn_row};

        piece.sq = c_sqrn(res);
        piece.piece = PP;
        new_player.pawns[i] = piece;

        if (res[0] == 'e')
            continue;

        int ord_indx = i < 4 ? i % 4 : (8 - (i % 4) % 4 - 1) % 4;
        res[1] = (char) ((int) !color ? pawn_row - 1 : pawn_row + 1);
        piece.sq = c_sqrn(res);
        int p;

        switch (ord_indx) {
            case 0:
                p = PR;
                break;
            case 1:
                p = PN;
                break;
            case 2:
                p = PB;
                break;
            case 3:
                p = PQ;
                break;
            default:
                p = -1;
        }

        piece.piece = p;
        porder[ord_indx][i < 4 ? 0 : 1] = piece;
    }

    return new_player;
}

struct cg_status cg_init() {
    struct cg_status new_cg = {
            .turn = 0,
            .player_cmate = 0,
            .white = player_init(0),
            .black = player_init(1)
    };
    return new_cg;
}

int gmi_prompt() {
    struct cg_status cg = cg_init();

    char* usr = malloc(PROMPT_MAX_INPUT_SIZE);
    while (1) {
        printf("%s's Move (%s)->>> ", cg.turn ? "Black" : "White", "Init");
        scanf("%10s", usr);
        printf("\n");

        if (strcmp(usr, "exit") == 0) {
            printf("Would you like to save the game before exiting? (Y/n) ");
            scanf("%1s", usr);
            printf("\n");
            break;
        }
    }

    return 0;
}
