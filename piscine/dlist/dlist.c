#include "dlist.h"

#include <stdio.h>
#include <stdlib.h>
// Thereshold 1

struct dlist *dlist_init(void)
{
    struct dlist *new_dlist;
    new_dlist = malloc(sizeof(struct dlist));
    if (!new_dlist)
        return NULL;
    new_dlist->size = 0;
    new_dlist->head = NULL;
    new_dlist->tail = NULL;

    return new_dlist;
}

int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *new_item;
    new_item = malloc(sizeof(struct dlist_item));
    if (!new_item)
        return 0;
    new_item->data = element;
    new_item->next = list->head;
    new_item->prev = NULL;

    if (list->head)
        list->head->prev = new_item;

    else
    {
        list->tail = new_item;
    }
    list->head = new_item;
    list->size++;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list == NULL)
        return;
    struct dlist_item *current;
    current = list->head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    struct dlist_item *new_item;
    new_item = malloc(sizeof(struct dlist_item));
    if (!new_item)
        return 0;
    new_item->data = element;
    new_item->prev = list->tail;
    new_item->next = NULL;
    if (list->tail != NULL)
        list->tail->next = new_item;
    else
        list->head = new_item;
    list->tail = new_item;
    list->size++;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

int dlist_get(struct dlist *list, size_t index)
{
    if (index == 0)
        return list->head->data;
    if (index == list->size - 1)
        return list->tail->data;
    struct dlist_item *current = list->head;
    size_t pos = 0;
    while (current != NULL && pos != index)
    {
        current = current->next;
        pos++;
    }
    if (pos == index)
        return current->data;
    return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (!list || list->size < index || element <= 0)
        return -1;

    if (index == 0)
        return dlist_push_front(list, element);

    if (index == list->size)
        return dlist_push_back(list, element);

    struct dlist_item *new_item;
    new_item = calloc(1, sizeof(struct dlist_item));
    if (!new_item)
        return 0;
    new_item->data = element;

    size_t cpt = 0;
    struct dlist_item *current = list->head;

    while (current != NULL && cpt < index)
    {
        current = current->next;
        cpt++;
    }

    new_item->next = current;
    new_item->prev = current->prev;
    current->prev->next = new_item;
    current->prev = new_item;

    list->size++;

    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    struct dlist_item *current = list->head;
    int index = 0;
    while (current != NULL && current->data != element)
    {
        index++;
        current = current->next;
    }
    if (current == NULL)
        return -1;
    return index;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (!list || list->size <= index)
        return -1;

    struct dlist_item *item_to_remove;

    if (index == 0)
    {
        item_to_remove = list->head;
        list->head = item_to_remove->next;
        if (list->head)
            list->head->prev = NULL;
        else
            list->tail = NULL;
    }

    else if (index == list->size - 1)
    {
        item_to_remove = list->tail;
        list->tail = item_to_remove->prev;
        list->tail->next = NULL;
    }
    else
    {
        struct dlist_item *current = list->head;
        size_t pos = 0;

        while (current != NULL && pos != index)
        {
            pos++;
            current = current->next;
        }

        if (pos == index)
        {
            item_to_remove = current;
            item_to_remove->prev->next = item_to_remove->next;
            item_to_remove->next->prev = item_to_remove->prev;
        }
    }

    int res = item_to_remove->data;
    list->size--;
    free(item_to_remove);
    return res;
}
// Threshold 3
void dlist_map_square(struct dlist *list)
{
    struct dlist_item *current = list->head;
    while (current != NULL)
    {
        current->data = current->data * current->data;
        current = current->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *current = list->head;
    struct dlist_item *head = list->head;
    struct dlist_item *temp = NULL;
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    list->tail = head;
    if (temp)
        list->head = temp->prev;
    else
        list->head = head;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (list == NULL || list->size <= index)
        return NULL;

    if (list->size == 0)
        return dlist_init();

    if (index == 0)
    {
        struct dlist *splitted_list = dlist_init();
        splitted_list->size = list->size;
        splitted_list->head = list->head;
        splitted_list->tail = list->tail;

        list->size = 0;
        list->head = list->tail = NULL;

        return splitted_list;
    }

    struct dlist_item *item_to_split = NULL;
    struct dlist_item *current = list->head;
    struct dlist *splitted_list = dlist_init();
    if (index < list->size / 2)
    {
        current = list->head;
        for (size_t i = 0; i < index; i++)
            current = current->next;
    }
    else
    {
        current = list->tail;
        for (size_t i = 0; i < list->size - index - 1; i++)
            current = current->prev;
    }
    item_to_split = current;
    struct dlist_item *prev = item_to_split->prev;

    splitted_list->size = list->size - index;
    list->size = index;

    splitted_list->head = item_to_split;
    splitted_list->head->prev = NULL;
    splitted_list->tail = list->tail;
    list->tail = prev;
    list->tail->next = NULL;

    return splitted_list;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2)
        return;
    else if (!list2->head)
        return;
    if (list1->head)
    {
        list1->tail->next = list2->head;
        list2->head->prev = list1->tail;
    }
    else
        list1->head = list2->head;
    list1->tail = list2->tail;
    list1->size = list1->size + list2->size;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}

void destroy(struct dlist *l)
{
    struct dlist_item *current = l->head;
    while (current != NULL)
    {
        struct dlist_item *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(l);
}
