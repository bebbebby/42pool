/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:33 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/04 18:30:51 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_allocate_join(int size, char **strs, char *sep)
{
	int	i;
	char *tab;
	int	len;

	i = 0;
	len = 0;
	if (size == 0)
	{
		tab = malloc(1);
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	tab = malloc(sizeof(char) * (unsigned int)(len + 1));
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;
	int 	j;
	int		k;

	tab = ft_allocate_join(size, strs, sep);
	if (!tab)
		return (NULL);
	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			tab[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && sep[j])
			tab[k++] = sep[j++];
		i++;
	}
	tab[k] = '\0';
	return (tab);
}

// int main()
// {
// 	int	size = 3;
// 	char	*strs[] = {"apple" ,"banana" ,"potato"};
// 	char *sep = ",";
// 	char *res = ft_strjoin(size, strs, sep);

// 	printf("%s" ,res);
// }