int ft_recursive_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb > 0 && i < nb)
	{
		ft_recursive_factorial(nb * i);
		i++;
	}
	return (nb);
}