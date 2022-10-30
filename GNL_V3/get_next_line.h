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

int line_len(char *stash);
char *extract_line(char *stash);

#endif