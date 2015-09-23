/*
** set_div.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 14:07:35 2013 timothee tosi
** Last update Sun Sep  8 22:25:39 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"shunting_yard.h"
#include		"uniform.h"
#include		"my_flags.h"
#include		"my_str.h"

static const int	_division_by_zero(char *divisor, char *base)
{
  if (divisor[0] == base[0])
    return (my_puterror("Division by zero\n"));
  return (RETURN_SUCCESS);
}

t_content		*set_div(t_op *operation, t_shunting *stack)
{
  t_content		*op1;
  t_content		*op2;
  char			*op_cpy1;
  char			*op_cpy2;
  t_content		*sym;
  char			*res;

  op2 = pop_front_elem(stack->operator_stack);
  op1 = pop_front_elem(stack->operator_stack);
  sym = pop_front_elem(operation->postfix_notation);
  if ((epure_sym(op1->content, op2->content, &op_cpy1, &op_cpy2,
		 operation->operators[3]) == RETURN_FAILURE) ||
      (_division_by_zero(op2->content, operation->operands) == RETURN_FAILURE))
    return (NULL);
  res = inf_div(op_cpy1, op_cpy2, operation->operands, operation->operators[3]);
  free(op_cpy1);
  free(op_cpy2);
  if ((res = uniform_sym(op1->content, op2->content, res,
  			 operation->operators[3])) == NULL)
    return (NULL);
  free_node(op1);
  free_node(op2);
  free_node(sym);
  return (set_res(res, operation));
}
