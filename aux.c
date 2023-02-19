
#include <wchar.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	iswspace(wint_t wc)
{
	if (wc == L' ' || wc == L'\t' || wc == L'\n'
		|| wc == L'\v' || wc == L'\f' || wc == L'\r')
		return (1);
	else
		return (0);
}

int	wtoi(const wchar_t *str)
{
	int				result;
	int				sign;
	const wchar_t	*p;

	result = 0;
	sign = 1;
	p = str;
	while (iswspace(*p))
		p++;
	if (*p == L'+')
		p++;
	else if (*p++ == L'-')
		sign = -1;
	while ((*p >= L'0' && *p <= L'9'))
	{
		result = result * 10 + (*p - L'0');
		p++;
	}
	return (result * sign);
}

/* wchar_t	*my_wcscpy(wchar_t *dest, const wchar_t *src)
{
	wchar_t			*d;
	const wchar_t	*s;

	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = L'\0';
	return (dest);
} */