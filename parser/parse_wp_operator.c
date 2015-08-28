/*
** parse_wp_operator.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 15:12:33 2013 timothee tosi
** Last update Thu Aug  8 20:41:42 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"my_flags.h"

const int		parse_wp_operator(t_op *operation, t_content **tmp)
{
  if (((*tmp)->next == NULL) || ((*tmp)->next->type == R_BRACKET) ||
      ((*tmp)->next->type == SP_OPERATOR))
    return (RETURN_FAILURE);
  *tmp = (*tmp)->next;
  return (RETURN_SUCCESS);
}
