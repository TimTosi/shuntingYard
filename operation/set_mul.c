/*
** set_mul.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sat Aug 17 17:15:45 2013 timothee tosi
** Last update Sun Sep  8 22:39:43 2013 timothee tosi
*/

#include			"shunting_yard.h"

t_content			*set_mul(t_op *operation, t_shunting *stack)
{
  t_content			*op1;
  t_content			*op2;
  t_content			*sym;
  char				*res;

  op2 = pop_front_elem(stack->operator_stack);
  op1 = pop_front_elem(stack->operator_stack);
  sym = pop_front_elem(operation->postfix_notation);
  res = inf_mul(op1->content, op2->content, operation->operands,
		operation->operators[3]);
  free_node(op1);
  free_node(op2);
  free_node(sym);
  return (set_res(res, operation));
}
