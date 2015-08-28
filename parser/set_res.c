/*
** set_res.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Aug 16 13:59:11 2013 timothee tosi
** Last update Sun Sep  8 20:46:06 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"

t_content		*set_res(char *res, t_op *operation)
{
  t_content		*container;

  if ((container = malloc(sizeof(*container))) == NULL)
    return (NULL);
  container->content = res;
  if (((char *)(container->content))[0] == operation->operators[3])
    container->type = N_OPERAND;
  else
    container->type = P_OPERAND;
  return (container);
}
