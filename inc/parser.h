/*
** parser.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Jul 22 10:36:38 2013 timothee tosi
** Last update Fri Aug 16 14:18:05 2013 timothee tosi
*/

#ifndef			PARSER_H_
# define		PARSER_H_

# include		"operation.h"

typedef	enum
{
  L_BRACKET,
  R_BRACKET,
  SP_OPERATOR,
  WP_OPERATOR,
  P_OPERAND,
  N_OPERAND
}			token_id;

typedef struct		s_parser_rule
{
  const int		(*ptr_func)(t_op *operation, t_content **tmp);
  token_id		id;
}			t_parser_rule;

const int		lexer(t_op *operation);
const int		parser(t_op *operation);
const int		l_bracket(t_op *operation, int *i);
const int		r_bracket(t_op *operation, int *i);
const int		sp_operator(t_op *operation, int *i);
const int		wp_operator(t_op *operation, int *i);
const int		p_operand(t_op *operation, int *i);
const int		n_operand(t_op *operation, int *i);
const int		parse_l_bracket(t_op *operation, t_content **tmp);
const int		parse_r_bracket(t_op *operation, t_content **tmp);
const int		parse_sp_operator(t_op *operation, t_content **tmp);
const int		parse_wp_operator(t_op *operation, t_content **tmp);
const int		parse_operand(t_op *operation, t_content **tmp);
t_content		*set_res(char *res, t_op *operation);

#endif			/* !PARSER_H_ */
