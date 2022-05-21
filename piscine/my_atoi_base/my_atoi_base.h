#ifndef MY_ATOI_BASE_H
#define MY_ATOI_BASE_H

int base_size(const char *b);
int atoi_char(char c, const char *b);
int rev(unsigned long n);
int skip_space(const char *str);

int my_atoi_base(const char *str, const char *base);

#endif
