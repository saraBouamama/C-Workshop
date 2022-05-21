#ifndef MY_STRTOK_R_H
#define MY_STRTOK_R_H

size_t my_strspn(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);
char *my_strtok_r(char *str, const char *delim, char **saveptr);

#endif
