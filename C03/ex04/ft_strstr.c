char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!to_find)
        return str;
    while (to_find[j] && str[i])
    {
        if (str[i] != str[j])
            return 0;
        i++;
        j++;
    }
    return (str);
}
