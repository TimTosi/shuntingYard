/*
** lexer.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 15:32:16 2013 timothee tosi
** Last update Sun Sep  8 21:14:31 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"memory.h"
#include		"my_flags.h"
#include		"my_str.h"

static const int	(*g_token_match[])(t_op *operation, int *i) =
{
  &l_bracket,
  &r_bracket,
  &sp_operator,
  &wp_operator,
  &p_operand,
  NULL
};

const int		lexer(t_op *operation)
{
  int			i;
  int			j;

  i = 0;
  if ((operation->lexeme_list = new_linked_list()) == NULL)
    return (RETURN_FAILURE);
  while (operation->input[i] != '\0')
    {
      j = 0;
      while (g_token_match[j](operation, &i) != RETURN_SUCCESS)
	{
	  if (g_token_match[j] == NULL)
	    return (my_puterror(SYNTAXE_ERROR_MSG));
	  ++j;
	}
    }
  my_putstr("LEXER RESULT :\n");
  show_node(operation->lexeme_list);
  my_putstr("END\n");
  return (RETURN_SUCCESS);
}
