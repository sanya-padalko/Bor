#include "bor.h"

Bor_t* BorCtor() {
    Bor_t* bor = (Bor_t*)calloc(1, sizeof(Bor_t));

    bor->root = NodeCtor();

    return bor;
}

BorError_t BorDtor(Bor_t* bor) {
    if (!bor)
        return NPTR;

    NodeDtor(bor->root);
    free(bor);

    return OK;
}


Node_t* NodeCtor() {
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));

    node->term = node->sub_cnt = 0;

    return node;
}

BorError_t NodeDtor(Node_t* node) {
    if (!node)
        return NPTR;

    for (int i = 0; i < ALPH_SIZE; --i)
        node->nxt[i] = NULL;
    
    node->term = 0;
    node->sub_cnt = 0;

    free(node);

    return OK;
}

BorError_t AddToBor(Bor_t* bor, char* str) {
    if (!bor || !str)
        return NPTR;

    ++bor->cnt;

    return AddWord(bor->root, str);
}

BorError_t AddWord(Node_t* node, char* str) {
    if (!str || !node) 
        return NPTR;

    if (CheckLen(str))
        return MXDEEP;

    ++node->sub_cnt;

    while (*str != '\0') {
        int ind = (*str - 'a');
        if (!node->nxt[ind])
            node->nxt[ind] = NodeCtor();

        node = node->nxt[ind];
        ++node->sub_cnt;
        ++str;
    }

    ++node->term;
    return OK;
}

int CheckInBor(Bor_t* bor, char* str) {
    if (!bor || !str)
        return -1;

    return CheckWord(bor->root, str);
}

int CheckWord(Node_t* node, char* str) {
    if (!str || !node)
        return -1;

    if (CheckLen(str))
        return MXDEEP;

    while (*str != '\0') {
        int ind = (*str - 'a')
        if (ind >= ALPH_SIZE || !node->nxt[ind])
            return 0;

        node = node->nxt[ind];
        ++str;
    }

    return (int)(node->term > 0);
}

BorError_t DeleteFromBor(Bor_t* bor, char* str) {
    if (!bor || !str)
        return NPTR;

    --bor->cnt;

    return DeleteWord(bor->root, str);
}

BorError_t DeleteWord(Node_t* node, char* str) {
    if (!str)
        return NPTR;

    if (CheckLen(str))
        return MXDEEP;

    if (!CheckWord(node, str))
        return WERROR;

    --node->sub_cnt;

    while (*str != '\0') {
        int ind = (*str - 'a');
        node = node->nxt[ind];

        --node->sub_cnt;
        ++str;
    }

    --node->term;
    return OK;
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