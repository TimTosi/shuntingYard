/*
** my_puterror.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Jul 18 11:18:51 2013 timothee tosi
** Last update Sun Sep  8 21:02:06 2013 timothee tosi
*/

#include	<unistd.h>
#include	"my_flags.h"
#include	"my_str.h"

const int	my_puterror(char *str)
{
  (void) write(ERROR_OUTPUT, str, my_strlen(str));
  return (RETURN_FAILURE);
}
