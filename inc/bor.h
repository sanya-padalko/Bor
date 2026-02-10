#include "errors.h"

const int ALPH_SIZE =   26;
const int MAX_DEEP  = 1000;

struct Node_t {
    Node_t* nxt[ALPH_SIZE];

    int term = 0;

    int sub_cnt = 0;
};

struct Bor_t {
    Node_t* root;

    int cnt = 0;
};

Bor_t* BorCtor();
BorError_t BorDtor(Bor_t* bor);
Node_t* NodeCtor();
BorError_t NodeDtor(Node_t* node);

BorError_t AddToBor(Bor_t* bor, char* str);
BorError_t AddWord(Node_t* node, char* str);
int CheckInBor(Bor_t* bor, char* str);
int CheckWord(Node_t* node, char* str);
BorError_t DeleteFromBor(Bor_t* bor, char* str);
BorError_t DeleteWord(Node_t* node, char* str);
