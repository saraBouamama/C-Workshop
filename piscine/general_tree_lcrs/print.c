#include "print.h"

#include <stdio.h>

static void rec_print(struct gtree *root)
{
    if (!root)
        return;

    if (root->children)
    {
        fprintf(stdout, " %c", root->children->data);
        rec_print(root->children);
    }

    if (root->siblings)
    {
        fprintf(stdout, " %c", root->siblings->data);
        rec_print(root->siblings);
    }
}

void gtree_print_preorder(struct gtree *root)
{
    if (!root)
        return;

    fprintf(stdout, "%c", root->data);

    if (root->children)
    {
        fprintf(stdout, " %c", root->children->data);
        rec_print(root->children);
    }

    fprintf(stdout, "\n");
}
