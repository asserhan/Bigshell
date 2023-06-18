int	ft_strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
	{
		if (!str1 && !str2)
			return (0);
		else if (!str1)
			return (-1);
		else
			return (1);
	}
	while ((*str1 || *str2) && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
