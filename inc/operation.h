/*
** operation.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Jul 18 17:48:05 2013 timothee tosi
** Last update Wed Sep  4 19:02:13 2013 timothee tosi
*/

#ifndef			OPERATION_H_
# define		OPERATION_H_

# include		"linked_list.h"

typedef enum
{
  ADDITION,
  SUBTRACTION,
  DIVISION,
  MULTIPLICATION,
  MODULO
}			operation_id;

typedef struct		s_op
{
  char			*operators;
  char			*operands;
  char			*input;
  t_content		*infix_notation;
  t_linked_list		*lexeme_list;
  t_linked_list		*postfix_notation;
  int			size_read;
}			t_op;

typedef	struct		s_add
{
  int			carry;
  int			carry2;
  int			i;
  int			j;
  int			k;
}			t_add;

char			*op_init(t_add *add, char *first_op, char *second_op, char *base);
char			*inf_add(char *first_op, char *sec_op, char *base, char minus);
char			*inf_sub(char *first_op, char *sec_op, char *base, char minus);
char			*inf_mul(char *first_op, char *sec_op, char *base, char minus);
char			*inf_div(char *first_op, char *sec_op, char *base, char minus);
char			*set_dividend(char *divisor, char *base, char minus, int x);

#endif			/* !OPERATION_H_ */
