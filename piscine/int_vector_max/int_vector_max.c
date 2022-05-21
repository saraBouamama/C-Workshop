
struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

int int_vector_max(const struct int_vector vect)
{
    int c = 0;
    for (int i = 0; i < vect.size; i++)
    {
        if (vect.data[i] > c)
        {
            c = vect.data[i];
        }
    }
    return c;
}
