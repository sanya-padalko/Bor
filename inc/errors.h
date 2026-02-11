#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <stdio.h>

#define RESET_COLOR  "\033[0m"
#define RED_COLOR    "\033[31m"
#define GREEN_COLOR  "\033[32m"
#define YELLOW_COLOR "\033[33m"

#define line_info __FILE__, __FUNCTION__, __LINE__

#define ERROR_PARSE(type)   printf("ParseBorError called from %s, %s in line %d\n", line_info); \
                            printf("Error Type %d: ", type); \
                            ParseBorError(type);

enum BorError_t {
    OK      =   0,
    NPTR    =   1,
    MXDEEP  =   2,
    WERROR  =   3,
};

void ParseBorError(BorError_t err);

#endif