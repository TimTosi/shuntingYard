/*
** parse_sp_operator.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 15:12:48 2013 timothee tosi
** Last update Thu Aug  8 20:34:57 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"my_flags.h"

const int		parse_sp_operator(t_op *operation, t_content **tmp)
{
  if (((*tmp)->next == NULL) || ((*tmp)->prev == NULL) ||
      ((*tmp)->next->type == SP_OPERATOR) ||
      ((*tmp)->next->type == WP_OPERATOR) ||
      ((*tmp)->next->type == R_BRACKET) ||
      ((*tmp)->prev->type == L_BRACKET) ||
      ((*tmp)->prev->type == SP_OPERATOR) ||
      ((*tmp)->prev->type == WP_OPERATOR))
    return (RETURN_FAILURE);
  *tmp = (*tmp)->next;
  return (RETURN_SUCCESS);
}
