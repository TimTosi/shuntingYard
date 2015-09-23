/*
** evaluate_postfix.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sat Aug 10 11:19:40 2013 timothee tosi
** Last update Sun Sep  8 22:34:49 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"shunting_yard.h"
#include		"my_str.h"
#include		"my_flags.h"

static t_postfix	g_tab_postfix[] = {
  {ADDITION, &set_sub_add},
  {SUBTRACTION, &set_sub_add},
  {DIVISION, &set_div},
  {MULTIPLICATION, &set_mul},
  {MODULO, &set_mod},
  {RETURN_FAILURE, NULL}
};

static const int	_calc_elem(t_shunting *stack, t_op *operation)
{
  int			i;
  t_content		*res;

  if (stack->operator_stack->size < 2)
    return (RETURN_FAILURE);
  i = 0;
  while (g_tab_postfix[i].id != RETURN_FAILURE)
    {
      if (g_tab_postfix[i].id == operation->postfix_notation->front->operator)
	{
	  if ((res = g_tab_postfix[i].ptr_func(operation, stack)) == NULL)
	    return (RETURN_FAILURE);
	  push_front_elem(operation->postfix_notation, res);
	  return (RETURN_SUCCESS);
	}
      ++i;
    }
  return (RETURN_FAILURE);
}

const int		_check_type(t_shunting *stack, t_op *operation)
{
  if (operation->postfix_notation->front->type >= P_OPERAND)
    return (push_front_elem(stack->operator_stack,
			    pop_front_elem(operation->postfix_notation)));
  else
    return (_calc_elem(stack, operation));
}

const int		evaluate_postfix(t_op *operation)
{
  t_shunting		stack;

  if ((stack.operator_stack = new_linked_list()) == NULL)
    return (RETURN_FAILURE);
  if (operation->postfix_notation->size == 1)
    {
      my_putstr(operation->postfix_notation->front->content);
      my_putstr("\n");
      free(stack.operator_stack);
      return (RETURN_SUCCESS);
    }
  while (operation->postfix_notation->size > 1)
    {
      if (_check_type(&stack, operation) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
  if (_check_type(&stack, operation) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  my_putstr(operation->postfix_notation->front->content);
  my_putstr("\n");
  free(stack.operator_stack);
  return (RETURN_SUCCESS);
}
