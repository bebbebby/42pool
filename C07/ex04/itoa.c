#include <stdio.h>
#include <stdlib.h>

int count_digits(unsigned int nb)
{
	int count;
	
	count = 0;
	if (nb == 0)
		return (1);
	if (nb > 0)
	{
		count += 1;
		nb /= 10;
	}
	return count;
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
	if (nb < 0)
		arr[0] = '-';
	i = len + 1;
	arr[i] = '\0';
	while (i >= 0)
	{
		if (nbr > 9)
			nbr = nbr / 10;
		arr[i] = nbr % 10 + '0';
		i--;
	}
	return (arr);
}

int main()
{
	printf("%s" ,itoa(234));
}