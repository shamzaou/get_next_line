#include "get_next_line.h"
#include "leak_detector_c.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
    if (str)
    {
        while (str[i])
            i++;
        return (i);
    }
    return (0);
}

int     line_len(char *stash)
{
    int i;
    
    i = 0;
    if (stash == NULL)
        return (0);
    while (stash[i] != '\n')
    {
        i++;
    }
    return (i);
}

char    *my_strcat(char *str1, char *str2)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    j = 0;

    new = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
    if (str1)
    {
        while (str1[i])
        {
            new[i] = str1[i];
            i++;
        }
    }
    while (str2[j])
    {
        new[i + j] = str2[j];
        j++;
    }
    //new[i + j] = '\n';
    /*if (str1 != NULL)
        free(str1);*/
    return (new);
}

char    *extract_line(char *stash)
{
    int i;
    char *line;

    i = 0;
    line = (char *)malloc(sizeof(char) * (line_len(stash) + 1));
    if (!line)
        return (NULL);
    while (stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    return (line);
}

char    *make_stash(t_gnl *head)
{
    char *stash;
    int i;

    i = 0;
    stash = NULL;
    while (head != NULL)
    {
        stash = my_strcat(stash, head->content);
        head = head->next;
    }
    return (stash);
}

int main()
{
    //char str[] = "hELhLO\nall.";
    //char *test = extract_line(str);
    char *test2;

    atexit(report_mem_leak);

    t_gnl *node1 = (t_gnl *)malloc(sizeof(t_gnl));
    t_gnl *node2 = (t_gnl *)malloc(sizeof(t_gnl));
    t_gnl *node3 = (t_gnl *)malloc(sizeof(t_gnl));
    node1->content = "Hello";
    node2->content = "mon";
    node3->content = "ami.";
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    test2 = make_stash(node1);

    printf("%s\n", test2);
}