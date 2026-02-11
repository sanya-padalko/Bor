#include "errors.h"

void ParseBorError(BorError_t err) {
    switch (err) {
        case OK:
            printf(GREEN_COLOR "Everything is ok\n");
            break;
        case NPTR:
            printf(RED_COLOR "NULL pointer or accessing a non-existent vertex\n");
            break;
        case MXDEEP:
            printf(RED_COLOR "The word with length more than MAX DEEP\n");
            break;
        case WERROR:
            printf(YELLOW_COLOR "Word isn't in Bor\n");
            break;
    }
    printf(RESET_COLOR);
}