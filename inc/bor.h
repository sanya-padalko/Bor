#include "errors.h"

const int ALPH_SIZE =   26;
const int MAX_DEEP  = 1000;

struct Node_t {
    Node_t* nxt[ALPH_SIZE];

    int val = -1;
};

struct Bor_t {
    Node_t* root;
};

Bor_t* BorCtor();
Node_t* NodeCtor();
BorError_t BorDtor(Bor_t* bor);
BorError_t ClearingBor(Bor_t* bor);
BorError_t ClearingNode(Node_t* node);
BorError_t NodeDtor(Node_t* node);

BorError_t UpdateBor(Bor_t* bor, char* str, int x);
BorError_t UpdateNode(Node_t* node, char* str, int x);
int GetValueBor(Bor_t* bor, char* str);
int GetValueNode(Node_t* node, char* str);

