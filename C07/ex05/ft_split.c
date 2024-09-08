/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:57:24 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/08 17:28:00 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	inword;

	count = 0;
	inword = 0;
	while (*str)
	{
		if (is_charset(charset, *str))
			inword = 0;
		else if (!inword)
		{
			count += 1;
			inword = 1;
		}
		str++;
	}
	return (count);
}

char	*split_words(char *str, char *charset)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && is_charset(charset, str[i]) == 0)
		i++;
	res = malloc(sizeof(char) * (size_t)(i + 1));
	if (!res)
		res = NULL;
	i = 0;
	while (str[i] && is_charset(charset, str[i]) == 0)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char	*str, char	*charset)
{
	int		i;
	char	**split;
	int		len;

	len = count_words(str, charset);
	split = malloc(sizeof(char *) * (size_t)(len + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*str && is_charset(charset, *str))
			str++;
		split[i] = split_words(str, charset);
		if (!split)
			return (NULL);
		while (*str && is_charset(charset, *str) == 0)
			str++;
		i++;
	}
	split[i] = NULL;
	return (split);
}

// #include <stdio.h>

// int main()
// {
// 	char *str = "ana ‡,zwina ‡,he    ‡,pipie";
// 	char *sep = "‡°";
// 	int i = 0;
// 	char **res = ft_split(str, sep);
// 	while (res[i])
// 	{
// 		printf("'%s' " ,res[i]);
// 		i++;
// 	}
// }