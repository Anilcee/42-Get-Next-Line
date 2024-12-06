
#ifndef GETNEXTLINE
#define GETNEXTLINE

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char const *s);
char	*ft_strchr(const char *s, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif