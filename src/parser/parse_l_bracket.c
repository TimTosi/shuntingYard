/*
** parse_l_bracket.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 15:11:56 2013 timothee tosi
** Last update Thu Aug  8 20:36:11 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"my_flags.h"

const int		parse_l_bracket(t_op *operation, t_content **tmp)
{
  if (((*tmp)->next == NULL) || ((*tmp)->next->type == SP_OPERATOR) ||
      ((*tmp)->next->type == WP_OPERATOR) ||
      ((*tmp)->next->type == R_BRACKET) ||
      (((*tmp)->prev != NULL) && (((*tmp)->prev->type == R_BRACKET) ||
				  ((*tmp)->prev->type == N_OPERAND) ||
				  ((*tmp)->prev->type == P_OPERAND))))
    return (RETURN_FAILURE);
  *tmp = (*tmp)->next;
  return (RETURN_SUCCESS);
}
