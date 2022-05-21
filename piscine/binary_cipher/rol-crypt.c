#include <stddef.h>

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t keylen)
{
    char *tmp1 = data;
    const char *tmp2 = key;
    for (size_t i = 0; i < data_len; ++i)
        tmp1[i] += tmp2[i % keylen];
    data = tmp1;
}
