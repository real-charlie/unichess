#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/move_actions.h"


int move_is_blocked(int step, int from, int to, struct cg_status *cg) {
    for (int i = from + step; to > from ? i < to : i > to; i += step) {
        for (int j = 0; j < 9; j++) {
            if (j <= 8 && (cg->white.pawns[j].sq == i || cg->black.pawns[j].sq == i))
                return 1;

            if (cg->white.knights[j].sq == i || cg->black.knights[j].sq == i)
                return 1;

            if (cg->white.bishops[j].sq == i || cg->black.bishops[j].sq == i)
                return 1;

            if (cg->white.rooks[j].sq == i || cg->black.rooks[j].sq == i)
                return 1;

            if (cg->white.queens[j].sq == i || cg->black.queens[j].sq == i)
                return 1;
        }
    }
    return 0;
}

int capt_is_valid(int tg_sqr, struct cg_status *cg) {
    int color = cg->turn;

    for (int i = 0; i < 9; i++) {
        if (i <= 8 && (color ? cg->white.pawns[i].sq == tg_sqr : cg->black.pawns[i].sq == tg_sqr))
            return 1;

        if (color ? cg->white.knights[i].sq == tg_sqr : cg->black.knights[i].sq == tg_sqr)
            return 1;

        if (color ? cg->white.bishops[i].sq == tg_sqr : cg->black.bishops[i].sq == tg_sqr)
            return 1;

        if (color ? cg->white.rooks[i].sq == tg_sqr : cg->black.rooks[i].sq == tg_sqr)
            return 1;

        if (color ? cg->white.queens[i].sq == tg_sqr : cg->black.queens[i].sq == tg_sqr)
            return 1;
    }
    return 0;
}

int pr_validate(struct c_action *cga, struct cg_status *cg) {
    int from = cga->tg_piece.sq, to = cga->tg_sqrn, dist = abs(from - to);
    if (((cga->cga | CGA_MOVE) == CGA_MOVE) || ((cga->cga | CGA_CAPT) == CGA_CAPT)) {

        int step = 0;
        if (dist % 8 == 0) {
            step = from > to ? -8 : 8;
        } else if (dist < 8) {
            step = from > to ? -1 : 1;
        }
        int vld_capt = capt_is_valid(to, cg);
        if (move_is_blocked(step, from, to, cg) || ((cga->cga == CGA_CAPT) && !vld_capt) || vld_capt) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int pb_validate(struct c_action *cga, struct cg_status *cg) {
    int from = cga->tg_piece.sq, to = cga->tg_sqrn, dist = abs(from - to);
    if (((cga->cga | CGA_MOVE) == CGA_MOVE) || ((cga->cga | CGA_CAPT) == CGA_CAPT)) {

        int step = 0;
        if (dist % 7 == 0) {
            step = from > to ? -7 : 7;
        } else if (dist % 9 == 0) {
            step = from > to ? -9 : 9;
        }
        int vld_capt = capt_is_valid(to, cg);
        if (move_is_blocked(step, from, to, cg) || ((cga->cga == CGA_CAPT) && !vld_capt) || vld_capt) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int pq_validate(struct c_action *cga, struct cg_status *cg) {
    return (pr_validate(cga, cg) || pb_validate(cga, cg));
}

int pp_validate(struct c_action *cga, struct cg_status *cg) {
    int from = cga->tg_piece.sq, to = cga->tg_sqrn, dist = abs(from - to);
    if ((((cga->cga | CGA_MOVE) == CGA_MOVE) || ((cga->cga | CGA_PROM) == CGA_PROM)) &&
            ((dist == 1) ||
        (dist == 2 && !cga->tg_piece.is_moved)) &&
        !move_is_blocked(cg->turn ? -1 : 1, from, to, cg) && !capt_is_valid(to, cg)) {
        return 1;
    } else if ((cga->cga | CGA_CAPT) == CGA_CAPT && (dist == 7 || dist == -9) && capt_is_valid(to, cg)) {
        return 1;
    }

    return 0;
}

int check_move_validity(struct c_action *cga, struct cg_status *cg) {
    int piece = cga->tg_piece.piece;

    switch (piece) {
        case PP:
            return pp_validate(cga, cg);
        case PN:
            break;
        case PB:
            return pb_validate(cga, cg);
        case PR:
            return pr_validate(cga, cg);
        case PQ:
            return pq_validate(cga, cg);
        case PK:
            break;
        default:
            return -1;
    }

    return -1;
}

int loc_piece(struct c_action* cga, struct cg_status *cg) {
    struct c_player *player = cg->turn ? &cg->black : &cg->white;
    int locd_ps_count = 0;

    for (int i = 0; i < 9; i ++) {
        struct piece tg_sqr_tmp = cga->tg_piece;
        switch (cga->tg_piece.piece) {
            case PP:
                if (i <= 8)
                    cga->tg_piece = player->pawns[i];
                break;
            case PB:
                cga->tg_piece = player->bishops[i];
                break;
            case PR:
                cga->tg_piece = player->rooks[i];
                break;
            case PQ:
                cga->tg_piece = player->queens[i];
        }
        if (check_move_validity(cga, cg) == 1)
            locd_ps_count++;
        else
            cga->tg_piece = tg_sqr_tmp;
    }
    return locd_ps_count;
}

int fd_piece(char piece) {
    switch (piece) {
        case 'Q':
            return PP;
        case 'R':
            return PR;
        case 'B':
            return PB;
        case 'N':
            return PN;
        default:
            return -1;
    }
}

struct c_action id_cga(const char *move, struct cg_status *cg) {
    unsigned int move_size = strlen(move);
    struct piece usr_piece;
    struct c_action cga;

    memset(&usr_piece, 0, sizeof(struct piece));
    memset(&cga, 0, sizeof(struct c_action));

    cga.cga = CGA_MOVE;

    if (move_size < 2) {
        cga.cga = CGA_UNDF;
        return cga;
    }

    if ((move[1] == '*' && move_size >= 4) || (move[2] == '*' && move_size >= 5))
        cga.cga = CGA_CAPT;
    else if (move[1] == '*' && move_size < 4 || (move[2] == '*' && move_size < 5)) {
        cga.cga = CGA_UNDF;
        return cga;
    }


    int is_capture = cga.cga == CGA_CAPT ? 1 : 0;
    int has_col = 0;

    if ((((move[1] >= 'a' && move[1] <= 'h') || (move[1] >= '1' && move[1] <= '8')) &&
         ((move[2] >= 'a' && move[2] <= 'h') || cga.cga == CGA_CAPT) ||
         ((move[0] >= 'a' && move[0] <= 'h') && (move[1] >= '1' && move[1] <= '8') && (cga.cga == CGA_CAPT)))) {
        has_col = 1;
    }

    if (move[0] >= 'a' && move[0] <= 'h') {
        usr_piece.piece = PP;
        char square[] = {move[0 + (is_capture + 1) * is_capture + has_col],
                         move[1 + (is_capture + 1) * is_capture + has_col]};

        if (cga.cga == CGA_CAPT && move_size == 6 && move[4] == '=')
            cga.cga |= (CGA_PROM | fd_piece(move[5]));
        else if (cga.cga != CGA_CAPT && move_size == 4 && move[2] == '=')
            cga.cga = CGA_PROM | move[3];

        cga.tg_sqrn = c_sqrn(square);
    } else {
        if (move_size < 3) {
            cga.cga = CGA_UNDF;
            return cga;
        }
        char square[] = {move[1 + is_capture + has_col], move[2 + is_capture + has_col]};
        cga.tg_sqrn = c_sqrn(square);

        switch (move[0]) {
            case CP_CHAR_KNT:
                usr_piece.piece = PN;
                break;
            case CP_CHAR_BSP:
                usr_piece.piece = PB;
                break;
            case CP_CHAR_ROK:
                usr_piece.piece = PR;
                break;
            case CP_CHAR_QUE:
                usr_piece.piece = PQ;
                break;
            case CP_CHAR_KNG:
                usr_piece.piece = PK;
                break;
            default:
                usr_piece.piece = INVALID_PIECE_NUMBER;
                break;
        }
    }

    cga.tg_piece = usr_piece;
    int loc_ps_res = loc_piece(&cga, cg);
    if (loc_ps_res == 0) {
        perror("Nothing found.\n");
        cga.cga = -1;
    } else if (loc_ps_res > 1) {
        perror("Duplicate\n");
        cga.cga = -1;
    }

    printf("Piece %d from %d is going to %d to action %d\n", cga.tg_piece.piece, cga.tg_piece.sq, cga.tg_sqrn, cga.cga);
    return cga;
}

void add_piece(struct piece ***src_pieces, struct piece *des_piece) {
    for (int i = 0; i < 9; i++) {
        if ((*src_pieces[i])->sq == 0) {
            *src_pieces[i] = des_piece;
            return;
        }
    }
}

int do_move(const char *move, struct cg_status *cg) {
    struct c_action cga = id_cga(move, cg);
    if (check_move_validity(&cga, cg)) {
        int curr_sq = cga.tg_piece.sq, tg_sq = cga.tg_sqrn;
        struct c_player *player = cg->turn ? &cg->black : &cg->white;

        if (player->king.sq == curr_sq) {
            player->king.sq = tg_sq;
            player->king.is_moved = 1;
            return 1;
        }

        struct piece * tmp_piece = NULL;
        for (int i = 0; i < 9; i++) {
            printf("i i %d\n", i);
            if (i <= 8 && (player->pawns[i].sq == curr_sq)) {
                tmp_piece = &player->pawns[i];
                printf("Pawn %d\n", tmp_piece->sq);
                if ((cga.cga & CGA_PROM) == CGA_PROM) {
                    struct piece **tg_piece = (struct piece **) &player->queens;
                    if ((cga.cga & PR) == PR) {
                        tg_piece = (struct piece **) &player->rooks;
                    } else if ((cga.cga & PN) == PN) {
                        tg_piece = (struct piece **) &player->knights;
                    } else if ((cga.cga & PB) == PB) {
                        tg_piece = (struct piece **) &player->bishops;
                    }

                    add_piece(&tg_piece, tmp_piece);
                }
            }

            if (player->knights[i].sq == curr_sq) {
                tmp_piece = &player->knights[i];
            }

            if (player->bishops[i].sq == curr_sq) {
                tmp_piece = &player->bishops[i];
            }

            if (player->rooks[i].sq == curr_sq) {
                tmp_piece = &player->rooks[i];
            }

            if (player->queens[i].sq == curr_sq) {
                tmp_piece = &player->queens[i];
            }

            if (tmp_piece != NULL) {
                tmp_piece->sq = tg_sq;
                tmp_piece->is_moved = 1;
                tmp_piece = NULL;
//                cg->turn = !cg->turn;

                return 1;
            }
        }
    }

    return 0;
}
