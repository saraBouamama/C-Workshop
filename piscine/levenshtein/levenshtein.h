#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <stddef.h>
size_t small_min(size_t big, size_t little);
size_t min(size_t a, size_t b, size_t c);

int my_strlen(const char *p);
int my_strcmp(const char *p1, const char *p2);

size_t levenshtein(const char *s1, const char *s2);

#endif /* !LEVENSHTEIN_H */
