#include "fifo.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *new_queue = calloc(1, sizeof(struct fifo));
    if (new_queue == NULL)
        return NULL;
    new_queue->size = 0;
    return new_queue;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new_elt = malloc(sizeof(struct list));
    if (new_elt == NULL)
        return;
    new_elt->data = elt;
    new_elt->next = NULL;
    if (fifo->tail == NULL)
    {
        fifo->head = new_elt;
        fifo->tail = new_elt;
        fifo->size++;
        return;
    }
    fifo->tail->next = new_elt;
    fifo->tail = new_elt;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo == NULL)
        return;
    if (fifo->head == NULL)
        return;
    struct list *new_head = fifo->head->next;
    free(fifo->head);
    fifo->head = new_head;
    fifo->size--;
    if (fifo->size == 0)
        fifo->tail = NULL;
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size > 0)
        fifo_pop(fifo);
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *current = fifo->head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
