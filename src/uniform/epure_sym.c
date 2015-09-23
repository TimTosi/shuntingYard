/*
** epure_sym.c for Bistromathique in /home/tosi_t//BISTRO/src/uniform
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 18:30:45 2013 timothee tosi
** Last update Wed Sep  4 18:36:22 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"memory.h"
#include		"my_flags.h"

const int		epure_sym(char *op1, char *op2,
				  char **res1, char **res2, char minus)
{
  if ((op1[0] == minus) && ((*res1 = my_strdup(&op1[1])) == NULL))
    return (RETURN_FAILURE);
  else if ((*res1 = my_strdup(op1)) == NULL)
    return (RETURN_FAILURE);
  if ((op2[0] == minus) && ((*res2 = my_strdup(&op2[1])) == NULL))
    return (RETURN_FAILURE);
  else if ((*res2 = my_strdup(op2)) == NULL)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
