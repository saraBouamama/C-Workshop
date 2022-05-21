#include <stdio.h>
#include <stdlib.h>

#include "list.h"
void list_print(struct list *l)
{
    if (!l)
    {
        printf("\n");
        return;
    }
    struct list *tmp = l;
    while (tmp->next)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d", tmp->data);
    printf("\n");
}
