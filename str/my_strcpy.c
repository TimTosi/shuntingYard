/*
** my_strcpy.c for Bistromathique in /home/tosi_t//INF_DIV/src
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Aug 19 23:59:18 2013 timothee tosi
** Last update Tue Aug 20 00:00:45 2013 timothee tosi
*/

char		*my_strcpy(char *origin, char *dest)
{
  int		i;

  i = 0;
  while (origin[i] != '\0')
    {
      dest[i] = origin[i];
      ++i;
    }
  return (dest);
}
