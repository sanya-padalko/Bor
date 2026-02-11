#include "bor_dump.h"

int main() {
    Bor_t* bor = BorCtor();

    UpdateBor(bor, "abc", 12);
    UpdateBor(bor, "abd", 3);
    UpdateBor(bor, "baby", -8);
    UpdateBor(bor, "bad", 152);
    UpdateBor(bor, "ca", 152);

    BorImgDump(bor);
}