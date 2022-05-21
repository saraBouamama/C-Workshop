#include "serialize.h"

#include <stdio.h>
#include <stdlib.h>

static void print_children_sibling(FILE *fd, struct gtree *root)
{
    if (!root)
        return;

    if (root->children)
        fprintf(fd, "%c -> %c;\n", root->data, root->children->data);

    struct gtree *tmp = root->children;

    while (tmp && tmp->siblings)
    {
        fprintf(fd, "%c -> %c;\n", root->data, tmp->siblings->data);
        tmp = tmp->siblings;
    }

    print_children_sibling(fd, root->siblings);
    print_children_sibling(fd, root->children);
}

static char *init_s(FILE *fd)
{
    char *s = malloc(20);
    s = fgets(s, 20, fd);

    return s;
}

int gtree_serialize(const char *filename, struct gtree *root)
{
    FILE *fd = fopen(filename, "w+");
    if (!fd)
        return -1;

    fprintf(fd, "digraph tree {\n");

    if (root->children)
        print_children_sibling(fd, root);
    else
        fprintf(fd, "%c;\n", root->data);

    fprintf(fd, "}\n");
    fclose(fd);

    return 0;
}

struct gtree *gtree_deserialize(const char *filename)
{
    FILE *fd = fopen(filename, "r");

    char *s = init_s(fd);
    struct gtree *tree = NULL;

    s = fgets(s, 7, fd);

    if (s[1] == ';')
        tree = gtree_create_node(s[0]);

    else if (s[0] != '}')
    {
        struct gtree *root = gtree_create_node(s[0]);
        struct gtree *cur = NULL;
        struct gtree *node = gtree_create_node(s[5]);
        gtree_add_child(root, node);

        while (1)
        {
            s = fgets(s, 7, fd);

            if (s[0] == '}')
            {
                tree = root;
                break;
            }

            else if (root->data != s[0])
            {
                cur = gtree_search_node(root, s[0]);
                node = gtree_create_node(s[5]);
                gtree_add_child(cur, node);
            }
            else
            {
                node = gtree_create_node(s[5]);
                gtree_add_child(root, node);
            }
        }
    }

    fclose(fd);
    return tree;
}
