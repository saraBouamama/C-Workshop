#include <stdlib.h>

struct recycler
{
    size_t block_size;
    size_t capacity; // number of blocks in the chunk
    void *chunk; // memory chunk containing all blocks
    void *free; // address of the first free block of the free list
};

struct recycler *recycler_create(size_t block_size, size_t total_size)
{
    if (block_size == 0 || total_size == 0 || block_size % sizeof(size_t) != 0
        || total_size % block_size != 0)
        return NULL;
    void *chunk = malloc(total_size);
    struct recycler *rec = malloc(sizeof(struct recycler));
    if (chunk == NULL || rec == NULL)
        return NULL;
    rec->chunk = chunk;
    rec->block_size = block_size;
    rec->capacity = total_size / block_size;
    rec->free = chunk;
    void **tmp_free = rec->free;
    size_t i = 1;
    char *rc = rec->chunk;
    void *next = rc + block_size;
    for (; i < rec->capacity; i++)
    {
        *tmp_free = next;
        tmp_free = next;
        next = rc + block_size * (i + 1);
    }
    *tmp_free = NULL;
    return rec;
}

void recycler_destroy(struct recycler *r)
{
    if (r != NULL)
    {
        if (r->chunk != NULL)
            free(r->chunk);
        free(r);
    }
}

void *recycler_allocate(struct recycler *r)
{
    if (r == NULL || r->free == NULL)
        return NULL;
    void **f = r->free;
    void *adress = *f;
    void *res = r->free;
    r->free = adress;
    return res;
}

void recycler_free(struct recycler *r, void *block)
{
    if (r != NULL && block != NULL)
    {
        void **rep = block;
        *rep = r->free;
        r->free = block;
    }
}
