#include "get_next_line.h"

/* Calucaltes the Length of a string */
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

/* Copies a string */
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

/* Calculate the length of the line that should be returned (aka. len until '\n') */
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

/* Concatenate two string by calculating their lengths and allocating the needed amount to put them together */
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

/* Duplicate a string (libft func) */
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

/* Extract the line to be returned from the stash */
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

/* Makes stash by collecting nodes contents and putting then together in  a single (char *) */
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

/* Clears the stash from the outputed line and the translates the next line to the beginning of the stash */
char    *ft_broomstick(char *stash)
{
    int i;
    int stash_len;
    int count;
    char *new_stash;

    i =0;
    count = 0;
    stash_len = ft_strlen(stash);
    while (stash[--stash_len] != '\n')
        count++;
    new_stash = (char *)malloc(sizeof(char) * count);
    while (stash[++stash_len])
        new_stash[i++] = stash[stash_len];
    return (new_stash);
}

/* Scans for New Line character */
int     nl_found(char *str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            if (str[i] == '\n')
                return (1);
            i++;
        }
    }
    return (0);
}



