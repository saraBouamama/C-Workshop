#include "variant.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%lf\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    default:
        printf("default");
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == NULL || right == NULL)
        return -1;
    if (left->type == right->type)
    {
        if (left->type == TYPE_STRING)
            return strcmp(left->value.str_v, right->value.str_v) == 0;
        else if (left->type == TYPE_INT)
            return left->value.int_v == right->value.int_v;
        else if (left->type == TYPE_FLOAT)
            return left->value.float_v == right->value.float_v;
        else if (left->type == TYPE_CHAR)
            return left->value.char_v == right->value.char_v;
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    size_t i = 0;
    while (i < len)
    {
        if (array[i].type == type)
        {
            if (array[i].type == TYPE_STRING
                && strcmp(array[i].value.str_v, value.str_v) == 0)
                return i;
            else if (array[i].type == TYPE_INT
                     && array[i].value.int_v == value.int_v)
                return i;
            else if (array[i].type == TYPE_FLOAT
                     && array[i].value.float_v == value.float_v)
                return i;
            else if (array[i].type == TYPE_CHAR
                     && array[i].value.char_v == value.char_v)
                return i;
        }
        i++;
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_FLOAT)
            res += array[i].value.float_v;
        if (array[i].type == TYPE_INT)
            res += array[i].value.int_v;
    }
    return res;
}
