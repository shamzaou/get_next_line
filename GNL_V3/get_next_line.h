#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct  gnl_list
{
    char            *content;
    struct  gnl_list  *next;
}               t_gnl;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char    *get_next_line(int fd);
int     line_len(char *stash);
int     nl_found(char *str);
char    *extract_line(char *stash);
void    ft_broomstick(char **stash);
char    *make_stash(t_gnl *head);
char	*ft_strdup(const char *src);
char    *my_strcat(char *str1, char *str2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlen(const char *str);



#endif