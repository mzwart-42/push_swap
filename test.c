#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_strtoi(const char *str, bool *succes)
{
	const int	base = 10;
	int			character;
	int			result;
	bool		neg;

	*succes = 0;
	result = 0;
	neg = (*str == '-');
	str += neg;
	while (*str)
	{
		character = *str++;
		if (character >= '0' && character <= '9')
			character -= '0';
		else
			return (result);
		if (result > (INT_MAX / 10) || \
			(result == (INT_MAX / 10) && character > INT_MAX % 10 + neg))
			return (result);
		result *= base;
		result += character;
	}
	*succes = 1;
	return (result * (-1 * neg));
}

int main()
{
	const char *s = "-2147483648";
	bool	succes;
	int	res;

	succes = 0;
	res = ft_strtoi(s, &succes);
	printf("%i %i", res, succes);
	if (!succes)
		return (-1);
}
