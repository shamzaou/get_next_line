#include "get_next_line.h"
#include "get_next_line_utils.c"

char    *get_next_line(int fd)
{
    t_gnl   *head;
    t_gnl   *node;
    char    *stash;
    //char    *buf;
    int nbytes = 5;

    node = (t_gnl *)malloc(sizeof(t_gnl));
    head = node;
    while (1)
    {
        node->content = (char *)malloc(sizeof(char) * nbytes);
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
    return (stash);
}

int main()
{
    int fd = open("files/text", 0);

    printf("%s\n", get_next_line(fd));

}