/*
** right_parenthesis_rule.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Aug  4 17:27:43 2013 timothee tosi
** Last update Sun Aug  4 17:33:23 2013 timothee tosi
*/

#include		"shunting_yard.h"
#include		"my_flags.h"

const int		right_parenthesis_rule(t_op *operation,
					       t_shunting *shunting)
{
  while (shunting->operator_stack->size > 0)
    {
      if (shunting->operator_stack->front->type == L_BRACKET)
	{
	  pop_front_elem(shunting->operator_stack);
	  pop_front_elem(shunting->infix);
	  return (RETURN_SUCCESS);
	}
      push_back_elem(operation->postfix_notation,
		     pop_front_elem(shunting->operator_stack));
    }
  return (RETURN_FAILURE);
}
