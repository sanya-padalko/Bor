#ifndef _BOR_DUMP_H_
#define _BOR_DUMP_H_

#include "errors.h"
#include "bor.h"
#include <sys/stat.h>

BorError_t BorImgDump(Bor_t* bor);
BorError_t NodeImgDump(Node_t* node, FILE* dot_file);

#endif