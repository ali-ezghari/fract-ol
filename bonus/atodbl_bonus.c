#include "fractol_bonus.h"

void	f_format_err(void)
{
	ft_putstr_fd("Please enter a valid number!\n", 1);
	ft_putstr_fd("e.g: a numbers between -2 and 2\n", 1);
	exit(EXIT_FAILURE);
}

static char	*skip_spaces(char *str)
{
	if (!str)
		f_format_err();
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '\0')
		f_format_err();
	return (str);
}

static void	check_format(char *str)
{
	int	dot;
	int	i;

	dot = 0;
	i = 0;
	if (str[i] == '.')
		f_format_err();
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.')
		{
			dot++;
			i++;
		}
		else
			f_format_err();
	}
	if (str[i] == '\0' && str[i - 1] == '.')
		f_format_err();
	if (dot != 0 && dot != 1)
		f_format_err();
}

double	atodbl(char *str)
{
	double	res;
	double	decimal;
	int		sign;

	decimal = 0.1;
	res = 0;
	sign = 1;
	str = skip_spaces(str);
	check_format(str);
	if (*str == '-' && ++str)
		sign = -1;
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
	{
		++str;
		while (*str >= '0' && *str <= '9')
		{
			res += (*str++ - '0') * decimal;
			decimal /= 10;
		}
	}
	return (res * sign);
}
