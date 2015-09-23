/*
** is_number.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Jul 18 15:41:07 2013 timothee tosi
** Last update Mon Jul 22 17:41:46 2013 timothee tosi
*/

#include	"my_flags.h"

const int	is_number(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	return (RETURN_FAILURE);
      ++i;
    }
  return (RETURN_SUCCESS);
}
