#include "bor_dump.h"

BorError_t BorImgDump(Bor_t* bor) {

    static int img_counter = 0;

    FILE* dot_file = fopen("bor.dot", "w");
    fprintf(dot_file, "digraph G {\n");

    BorError_t error_code = NodeImgDump(bor->root, dot_file);

    fprintf(dot_file, "}\n");
    fclose(dot_file);

    char* sys_call = (char*)calloc(100, sizeof(char));
    printf("i'm here\n");
    sprintf(sys_call, "\"C:\\Program Files\\Graphviz\\bin\\dot.exe\" bor.dot -T svg -o bor%d.svg", img_counter++);
    system(sys_call);

    return error_code;
}

#define ull unsigned long long

BorError_t NodeImgDump(Node_t* node, FILE* dot_file) { // todo: node_string in every node
    fprintf(dot_file, "\tNode%llx[", (ull)node);
    fprintf(dot_file, "style = \"filled\", ");
    if (node->val != -1) {
        fprintf(dot_file, "fillcolor = \"#06c78a\", ");
        fprintf(dot_file, "label = %d", node->val);
    } else { 
        fprintf(dot_file, "shape = circle, "); 
        fprintf(dot_file, "fillcolor = \"#e3e029\", ");
        fprintf(dot_file, "label = \"\"");
    }
    fprintf(dot_file, "];\n");

    BorError_t error_code = OK;

    for (int i = 0; i < ALPH_SIZE; ++i) {
        if (node->nxt[i]) {
            error_code = NodeImgDump(node->nxt[i], dot_file);
            if (error_code != OK)
                return error_code;

            fprintf(dot_file, "\tNode%llx->Node%llx", (ull)node, (ull)node->nxt[i]);
            fprintf(dot_file, "[color = \"#662491\", label = \" %c\"]", (char)('a' + i));
        }
    }

    return OK;
}

#undef ull