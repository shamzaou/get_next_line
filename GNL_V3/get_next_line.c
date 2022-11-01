#include "get_next_line.h"

char    *get_next_line(int fd)
{
    t_gnl   *head;
    t_gnl   *node;
    static char    *stash;
    //char    *buf;
    int nbytes = 5;
    char *line = NULL;

 
    node = (t_gnl *)malloc(sizeof(t_gnl));
    head = node;
    stash = NULL;
    while (1)
    {
        
        node->content = (char *)malloc(sizeof(char) * (nbytes));
        node->next = (t_gnl *)malloc(sizeof(t_gnl));
        read(fd, node->content, nbytes);
        if (nl_found(node->content))
        {
            node->next = NULL;
            break;
        }
        node = node->next;
    }
    
    stash = make_stash(head);
    line = extract_line(stash);
    return (line);
}

int main()
{
    int fd = open("files/text", 0);

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    

}