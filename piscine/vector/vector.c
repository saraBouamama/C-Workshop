#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *vec = malloc(sizeof(struct vector));
    vec->size = 0;
    vec->capacity = n;
    vec->data = malloc(n * sizeof(int));
    for (size_t k = 0; k < n; k++)
    {
        vec->data[k] = 0;
    }
    return vec;
}

void vector_destroy(struct vector *v)
{
    if (v == NULL)
        return;
    else
    {
        free(v->data);
        free(v);
        return;
    }
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n <= v->size)
    {
        v->size = n;
        v->capacity = n;
        return v;
    }
    else if (n > v->size && n <= v->capacity)
    {
        v->capacity = n;
        return v;
    }
    else
    {
        v->data = realloc(v->data, n * sizeof(int));
        v->capacity = n;
        return v;
    }
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v == NULL)
        return NULL;
    else if (v->size + 1 <= v->capacity)
    {
        v->data[v->size] = elt;
        v->size++;
        return v;
    }
    else
    {
        v->data = realloc(v->data, v->capacity * 2 * sizeof(int));
        v->data[v->size] = elt;
        v->capacity *= 2;
        v->size++;
        return v;
    }
}

void vector_print(const struct vector *v)
{
    if (v == NULL || v->size == 0)
        putchar('\n');
    else
    {
        for (size_t k = 0; k < v->size - 1; k++)
        {
            printf("%d,", v->data[k]);
        }
        printf("%d\n", v->data[v->size - 1]);
    }
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    v->size = 0;
    v->capacity = n;
    v->data = realloc(v->data, n * sizeof(int));
    return v;
}

int *decalle_d(int *data, size_t i, size_t size)
{
    for (size_t k = size; k > i; k--)
    {
        data[k] = data[k - 1];
    }
    return data;
}

int *decalle_g(int *data, size_t i, size_t size)
{
    for (size_t k = i; k < size - 1; k++)
    {
        data[k] = data[k + 1];
    }
    return data;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v == NULL)
        return NULL;
    else if (i <= v->size && v->size + 1 <= v->capacity)
    {
        v->data = decalle_d(v->data, i, v->size);
        v->data[i] = elt;
        v->size++;
        return v;
    }
    else if (i <= v->size)
    {
        v->data = realloc(v->data, v->size * 2 * sizeof(int));
        v->capacity *= 2;
        v->size++;
        v->data = decalle_d(v->data, i, v->size);
        v->data[i] = elt;
        return v;
    }
    else if (i > v->size)
    {
        /*v->data[v->size] = elt;
        v->size++;*/
        return NULL;
    }
    else
        return NULL;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v == NULL || v->size == 0 || i > v->size - 1)
        return NULL;
    v->data = decalle_g(v->data, i, v->size);
    v->size--;
    if (v->size <= (v->capacity / 2) && v->size != 0)
    {
        v->capacity = v->capacity / 2;
    }
    return v;
}
