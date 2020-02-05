#include "cub.h"

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr((nb / 10));
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar((nb + '0'));
}