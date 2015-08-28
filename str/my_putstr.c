/*
** my_putstr.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Jul 12 20:04:26 2013 timothee tosi
** Last update Mon Jul 22 17:43:04 2013 timothee tosi
*/

#include		<unistd.h>
#include		"my_flags.h"
#include		"my_str.h"

void			my_putstr(char *str)
{
  (void) write(STANDARD_OUTPUT, str, my_strlen(str));
}
