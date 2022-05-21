#include "gtree.h"

#include <stddef.h>
#include <stdlib.h>

struct gtree *gtree_create_node(char data)
{
    struct gtree *new_node = malloc(sizeof(struct gtree));
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->children = NULL;
    new_node->siblings = NULL;

    return new_node;
}

int gtree_add_child(struct gtree *parent, struct gtree *child)
{
    if (!parent || !child)
        return 0;

    if (!parent->children)
        parent->children = child;

    else
    {
        struct gtree *tmp = parent->children;
        while (tmp->siblings)
        {
            tmp = tmp->siblings;
        }

        tmp->siblings = child;
    }

    return 1;
}

struct gtree *gtree_search_node(struct gtree *root, char data)
{
    if (!root)
        return root;

    struct gtree *new = NULL;

    if (root->data == data)
        return root;

    if (root->children)
    {
        new = gtree_search_node(root->children, data);

        if (new)
            return new;
    }

    if (root->siblings)
    {
        new = gtree_search_node(root->siblings, data);

        if (new)
            return new;
    }

    return NULL;
}

void gtree_free(struct gtree *root)
{
    if (!root)
        return;

    if (root->siblings)
        gtree_free(root->siblings);

    if (root->children)
        gtree_free(root->children);

    free(root);
}

int gtree_del_node(struct gtree *root, char data)
{
    struct gtree *new = gtree_search_node(root, data);

    if (new)
    {
        if (new == root)
            return -1;

        gtree_free(root);
        return 1;
    }

    return 0;
}
