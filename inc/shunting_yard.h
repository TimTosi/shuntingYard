/*
** shunting_yard.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 09:25:35 2013 timothee tosi
** Last update Wed Sep  4 18:52:14 2013 timothee tosi
*/

#ifndef			SHUNTING_YARD_H_
# define		SHUNTING_YARD_H_

# include		"parser.h"
# include		"operation.h"

typedef	struct		s_shunting
{
  t_linked_list		*infix;
  t_linked_list		*operator_stack;
}			t_shunting;

typedef	struct		s_infix
{
  token_id		id;
  const int		(*ptr_func)(t_op *operation, t_shunting *shunting);
}			t_infix;

typedef	struct		s_postfix
{
  operation_id		id;
  t_content		*(*ptr_func)(t_op *operation, t_shunting *stack);
}			t_postfix;

const int		operator_rule(t_op *operation, t_shunting *shunting);
const int		operand_rule(t_op *operation, t_shunting *shunting);
const int		left_parenthesis_rule(t_op *operation, t_shunting *shunting);
const int		right_parenthesis_rule(t_op *operation, t_shunting *shunting);
const int		output_rule(t_op *operation, t_shunting *shunting);
const int		infix_to_postfix(t_op *operation);
const int		evaluate_postfix(t_op *operation);
t_content		*set_sub_add(t_op *operation, t_shunting *stack);
t_content		*set_mul(t_op *operation, t_shunting *stack);
t_content		*set_div(t_op *operation, t_shunting *stack);
t_content		*set_mod(t_op *operation, t_shunting *stack);

#endif			/* !SHUNTING_YARD_H_ */
