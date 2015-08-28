/*
** in_array.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 14:23:11 2013 timothee tosi
** Last update Tue Jul 23 14:25:11 2013 timothee tosi
*/

#include		"my_flags.h"

const int		in_array(char needle, char *heap)
{
  int			i;

  i = 0;
  while (heap[i] != '\0')
    {
      if (heap[i] == needle)
	return (i);
      ++i;
    }
  return (RETURN_FAILURE);
}
