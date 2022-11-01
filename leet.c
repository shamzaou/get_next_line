#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    *ft_broomstick(char *stash)
{
    int i;
    int stash_len;
    int count;
    char *new_stash;

    i =0;
    count = 0;
    stash_len = ft_strlen(stash);
    //printf("broom stash len : :%d\n", stash_len);
    while (stash[--stash_len] != '\n' && stash_len)
        count++;
    new_stash = (char *)malloc(sizeof(char) * (count + 1));
    while (stash[++stash_len] )
        new_stash[i++] = stash[stash_len];
    
    new_stash[++i] = '\0';
    return (new_stash);
}


int main() {
   char *s = "kdjsfhkjsdhfkdsjf";
    ft_foo(&s);
   printf("%s", s);
}