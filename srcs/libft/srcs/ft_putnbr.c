#include <libft.h>

void	ft_putnbr(int n)
{
	char nr;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 10)
	{
		ft_putnbr(n % 10);
		ft_putnbr(n / 10);
	}
	else
	{
		nr = n + '0';
		write(1, &nr, 1);		
	}
}
