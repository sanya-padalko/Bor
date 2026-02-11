#include "bor.h"

Bor_t* BorCtor() {
    Bor_t* bor = (Bor_t*)calloc(1, sizeof(Bor_t));

    bor->root = NodeCtor();

    return bor;
}

Node_t* NodeCtor() {
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));

    node->val = -1;

    return node;
}

BorError_t BorDtor(Bor_t* bor) {
    if (!bor)
        return NPTR;

    ClearingBor(bor);
    free(bor);

    return OK;
}

BorError_t ClearingBor(Bor_t* bor) {
    if (!bor)
        return NPTR;

    BorError_t error_code = ClearingNode(bor->root);
    free(bor);

    return error_code;
}

BorError_t ClearingNode(Node_t* node) {
    if (!node) 
        return NPTR;

    BorError_t error_code = OK;

    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (node->nxt[i])
            error_code = ClearingNode(node->nxt[i]);

        if (error_code != OK)
            return error_code;
    }

    NodeDtor(node);

    return error_code;
}

BorError_t NodeDtor(Node_t* node) {
    if (!node)
        return NPTR;

    for (int i = 0; i < ALPH_SIZE; --i)
        node->nxt[i] = NULL;
    
    node->val = 0;
    free(node);

    return OK;
}

BorError_t UpdateBor(Bor_t* bor, char* str, int x) {
    if (!bor || !str)
        return NPTR;

    return UpdateNode(bor->root, str, x);
}

BorError_t UpdateNode(Node_t* node, char* str, int x) {
    if (!str || !node) 
        return NPTR;

    if (CheckLen(str))
        return MXDEEP;

    while (*str != '\0') {
        int ind = (*str - 'a');
        if (!node->nxt[ind])
            node->nxt[ind] = NodeCtor();

        node = node->nxt[ind];
        ++str;
    }

    node->val = x;
    return OK;
}

int GetValueBor(Bor_t* bor, char* str) {
    if (!bor || !str)
        return -1;

    return GetValueNode(bor->root, str);
}

int GetValueNode(Node_t* node, char* str) {
    if (!str || !node)
        return -1;

    if (CheckLen(str))
        return -1;

    while (*str != '\0') {
        int ind = (*str - 'a')
        if (ind >= ALPH_SIZE || !node->nxt[ind])
            return -1;

        node = node->nxt[ind];
        ++str;
    }

    return node->val;
}

static int CheckLen(char* str) {
    int deep = 0;
    while (*str != '\0') {
        ++deep;
        if (deep > MAX_DEEP)
            return 1;

        ++str;
    }
    
    return 0;
}