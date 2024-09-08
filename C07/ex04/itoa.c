#include <stdio.h>
#include <stdlib.h>

int count_digits(unsigned int nb)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count += 1;
		nb /= 10;
	}
	return count;
}

void	convert(char *arr, int i, unsigned int nbr)
{
	while (i >= 0)
	{
		arr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
}

char	*itoa(int nb)
{
	char *arr;
	int	i;
	unsigned int nbr;
	int	len;

	i = 0;
	nbr = (unsigned int)nb;
	if (nb < 0)
	{
		nbr = 1u - nbr - 1;
		len = count_digits(nbr) + 1;
	}
	else
		len = count_digits(nbr);
	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	i = len - 1;
	arr[i + 1] = '\0';
	convert(arr, i, nbr);
	if (nb < 0)
		arr[0] = '-';
	return (arr);
}

int main()
{
	printf("%s" ,itoa(-234));
}