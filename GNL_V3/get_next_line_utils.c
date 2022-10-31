#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
    if (str)
    {
        while (str[i])
            i++;
        return (i);
    }
    return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (!size)
		return (ft_strlen(src));
	index = 0;
	while (src[index] && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
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

char	*ft_strdup(const char *src)
{
	char	*string;
	size_t	src_size;

	src_size = ft_strlen(src);
	string = malloc(sizeof(char) * (src_size + 1));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, src, src_size + 1);
	return (string);
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
    char *tmp;
    //int i;

    //i = 0;
    stash = NULL;
    tmp = NULL;
    while (head != NULL)
    {
        tmp = my_strcat(stash, head->content);
        if (stash != NULL)
            free(stash);
        stash = ft_strdup(tmp);
        free(tmp);
        head = head->next;
    }
    return (stash);
}

char    *ft_broomstick(char *stash)
{
    int i;
    int stash_len;
    int count;
    char *new_stash;

    i =0;
    count++;
    stash_len = ft_strlen(stash);
    while (stash[--stash_len] != '\n')
        count++;
    new_stash = (char *)malloc(sizeof(char) * count);
    while (stash[++stash_len])
        new_stash[i++] = stash[stash_len];
    return (new_stash);
}

int main()
{
    char str[] = "hELhLO\nall.";
    //char *test = extract_line(str);
    char *test2;

    test2 = ft_broomstick(str);
    printf("%s\n", test2);

    /*t_gnl *node1 = (t_gnl *)malloc(sizeof(t_gnl));
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
    free(test2);
    free(node1);
    free(node2);
    free(node3);*/

}