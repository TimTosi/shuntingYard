/*
** set_mod.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 18:04:04 2013 timothee tosi
** Last update Sun Sep  8 22:23:03 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"shunting_yard.h"
#include		"uniform.h"
#include		"my_flags.h"

#include "my_str.h"

static void		free_buffers(char **str1, char **str2, char **str3,
				     char **str4)
{
  free(*str1);
  free(*str2);
  free(*str3);
  free(*str4);
}

static char		*modulo_operation(char *op1, char *op2,
					  t_op *operation)
{
  char			*op_cpy1;
  char			*op_cpy2;
  char			*res1;
  char			*res2;
  char			*res3;

  if (op2[0] == operation->operands[0])
    {
      my_puterror("Division by zero\n");
      return (NULL);
    }
  if (epure_sym(op1, op2, &op_cpy1, &op_cpy2,
		operation->operators[3]) == RETURN_FAILURE)
    return (NULL);
  res1 = inf_div(op_cpy1, op_cpy2, operation->operands, operation->operators[3]);
  res2 = inf_mul(op_cpy2, res1, operation->operands, operation->operators[3]);
  res3 = inf_sub(op_cpy1, res2, operation->operands, operation->operators[3]);
  free_buffers(&op_cpy1, &op_cpy2, &res1, &res2);
  return (res3);
}

t_content		*set_mod(t_op *operation, t_shunting *stack)
{
  t_content		*op1;
  t_content		*op2;
  t_content		*sym;
  char			*res;

  op2 = pop_front_elem(stack->operator_stack);
  op1 = pop_front_elem(stack->operator_stack);
  sym = pop_front_elem(operation->postfix_notation);
  if ((res = modulo_operation(op1->content, op2->content, operation)) == NULL)
    return (NULL);
  if ((res = uniform_sym(op1->content, op2->content, res,
			  operation->operators[3])) == NULL)
    return (NULL);
  free_node(op1);
  free_node(op2);
  free_node(sym);
  return (set_res(res, operation));
}
