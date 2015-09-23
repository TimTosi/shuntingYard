/*
** set_sub_add.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Aug 16 14:29:59 2013 timothee tosi
** Last update Sun Sep  8 20:49:07 2013 timothee tosi
*/

#include			<stdlib.h>
#include			"shunting_yard.h"
#include			"uniform.h"

static const operation_id	_select_sub_add(token_id op1, token_id op2,
						operation_id sym)
{
  if (((op1 == op2) && (sym == ADDITION)) ||
      ((op1 != op2) && (sym == SUBTRACTION)))
    return (ADDITION);
  return (SUBTRACTION);
}

t_content			*set_sub_add(t_op *operation, t_shunting *stack)
{
  t_content			*op1;
  t_content			*op2;
  t_content			*sym;
  char				*res;

  op2 = pop_front_elem(stack->operator_stack);
  op1 = pop_front_elem(stack->operator_stack);
  sym = pop_front_elem(operation->postfix_notation);
  if (_select_sub_add(op1->type, op2->type, sym->operator) == ADDITION)
    res = inf_add(op1->content, op2->content, operation->operands,
		  operation->operators[3]);
  else
    res = inf_sub(op1->content, op2->content, operation->operands,
		  operation->operators[3]);
  free_node(op1);
  free_node(op2);
  free_node(sym);
  if ((res = uniform_result(res, operation->operands,
			    operation->operators[3])) == NULL)
    return (NULL);
  return (set_res(res, operation));
}
