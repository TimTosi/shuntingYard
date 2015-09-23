/*
** my_strlen.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Jul 12 19:35:30 2013 timothee tosi
** Last update Thu Jul 18 15:46:21 2013 timothee tosi
*/

int		my_strlen(const char * str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
