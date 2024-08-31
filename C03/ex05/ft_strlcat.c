/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:55:24 by hasbayou          #+#    #+#             */
/*   Updated: 2024/08/31 23:19:58 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dstlen;
	unsigned int	src_len;

	j = 0;
	i = 0;
	while (dest[j])
		j++;
	src_len = ft_strlen(src); 
	dstlen = j;
	if (size == 0 || size <= dstlen)
		return (size + src_len);
	while (src[i] && i < size - dstlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dstlen + src_len);
}
