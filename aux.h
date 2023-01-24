
#ifndef AUX_H
# define AUX_H

# include <wchar.h>

size_t	ft_strlen(char const *str);
int		iswspace(wint_t wc);
int		wtoi(const wchar_t *str);
wchar_t	*my_wcscpy(wchar_t *dest, const wchar_t *src);

#endif