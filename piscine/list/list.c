#include "list.h"

#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return NULL;
    new->data = e;
    if (!l)
    {
        new->next = NULL;
        return new;
    }
    new->next = l;
    l = new;
    return l;
}

struct list *list_find(struct list *l, int e)
{
    if (!l)
        return NULL;
    if (l->data == e)
        return l;
    struct list *new = l->next;
    while (new)
    {
        if (new->data == e)
        {
            return new;
        }
        new = new->next;
    }
    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    if (!l)
        return NULL;
    if (l->data == e)
    {
        struct list *tmp = l;
        l = l->next;
        free(tmp);
        return l;
    }
    struct list *tmp = l->next;
    struct list *prev = l;
    while (tmp)
    {
        if (tmp->data == e)
        {
            prev->next = tmp->next;
            free(tmp);
            return l;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (!l)
    {
        l = list_add(l, e);
        return l;
    }
    if (l->data < e)
    {
        struct list *new = malloc(sizeof(struct list));
        new->data = e;
        new->next = l;
        l = new;
        return l;
    }
    struct list *tmp = l;
    while (tmp->next)
    {
        if (tmp->next->data < e)
        {
            struct list *new = malloc(sizeof(struct list));
            new->data = e;
            new->next = tmp->next;
            tmp->next = new;
            return l;
        }
        tmp = tmp->next;
    }
    struct list *new = malloc(sizeof(struct list));
    new->data = e;
    new->next = tmp->next;
    tmp->next = new;
    return l;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (!l)
        return NULL;

    struct list *tmp = l;
    while (tmp)
    {
        if (predicate(tmp->data))
        {
            l = list_remove(l, tmp->data);
            tmp = l;
        }
        else
            tmp = tmp->next;
    }
    return l;
}
