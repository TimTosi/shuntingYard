/*
** param.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Jul 22 09:15:56 2013 timothee tosi
** Last update Mon Jul 22 17:38:42 2013 timothee tosi
*/

#ifndef			PARAM_H_
# define		PARAM_H_

# include		"operation.h"

# define		OPERATORS_NB		7

const int		check_param(const int param_nb, char **param_tab);
const int		check_op(char **param_tab);
const int		get_param(t_op *operation, char **av);

#endif			/* !PARAM_H_ */
