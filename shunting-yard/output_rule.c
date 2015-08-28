/*
** output_rule.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Aug  4 14:36:31 2013 timothee tosi
** Last update Sun Aug  4 17:11:32 2013 timothee tosi
*/

#include		"shunting_yard.h"
#include		"my_flags.h"

const int		output_rule(t_op *operation, t_shunting *shunting)
{
  while (shunting->operator_stack->size > 0)
    {
      if ((shunting->operator_stack->front->type == WP_OPERATOR) ||
	  (shunting->operator_stack->front->type == SP_OPERATOR))
	push_back_elem(operation->postfix_notation,
		       pop_front_elem(shunting->operator_stack));
      else
	return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
