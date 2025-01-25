#include "fractol.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
void ft_putstr_fd(char *s, int fd)
{
    int i;

    if (s == NULL)
        return;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}
size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (s1 == NULL && s2 == NULL)
        return (0);
    while ((i < n) && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    if (i < n)
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    return (0);
}
