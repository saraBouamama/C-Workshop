#ifndef INT_VECTOR_INSERT_SORT_H
#define INT_VECTOR_INSERT_SORT_H

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

static struct int_vector swap(struct int_vector vec, size_t i, size_t j);
static int_vector int_vector_insert_sort(struct int_vector vec);

#endif
