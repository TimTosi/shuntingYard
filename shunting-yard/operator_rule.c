/*
** operator_rule.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Aug  4 13:32:24 2013 timothee tosi
** Last update Wed Aug  7 14:24:19 2013 timothee tosi
*/

#include		"shunting_yard.h"
#include		"my_flags.h"

static const int	_check_precedence(t_op *operation, t_shunting *shunting)
{
  if ((shunting->operator_stack->front->type == WP_OPERATOR) &&
      (shunting->infix->front->type == SP_OPERATOR))
    {
      push_front_elem(shunting->operator_stack,
		      pop_front_elem(shunting->infix));
      return (RETURN_FAILURE);
    }
  push_back_elem(operation->postfix_notation,
		 pop_front_elem(shunting->operator_stack));
  return (RETURN_SUCCESS);
}

const int		operator_rule(t_op *operation, t_shunting *shunting)
{
  while ((shunting->operator_stack->size > 0) &&
	 ((shunting->operator_stack->front->type == WP_OPERATOR) ||
	  (shunting->operator_stack->front->type == SP_OPERATOR)))
    {
      if (_check_precedence(operation, shunting) == RETURN_FAILURE)
	return (RETURN_SUCCESS);
    }
  push_front_elem(shunting->operator_stack, pop_front_elem(shunting->infix));
  return (RETURN_SUCCESS);
}
