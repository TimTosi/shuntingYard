/*
** uniform.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 13:38:28 2013 timothee tosi
** Last update Sun Sep  8 19:46:18 2013 timothee tosi
*/

#ifndef				UNIFORM_H_
# define			UNIFORM_H_

char				*uniform_to_zero(char *base, char *origin);
char				*uniform_result(char *rest, char *base, char minus);
char				*uniform_sym(char *op1, char *op2, char *res, char minus);
const int			epure_sym(char *op1, char *op2, char **res1, char **res2, char minus);

#endif				/* !UNIFORM_H_ */
