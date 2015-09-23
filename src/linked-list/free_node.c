/*
** free_node.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Aug 16 15:37:59 2013 timothee tosi
** Last update Fri Aug 16 15:40:32 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"content.h"

void		free_node(t_content *container)
{
  if (container != NULL)
    {
      if (container->content != NULL)
	free(container->content);
      free(container);
    }
}
