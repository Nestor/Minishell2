/*                                                                              
** my_cmddelone.c for minishell2 in /home/bourge_v/Downloads/test/minishell2    
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:08:29 2014 bourge_v                                
** Last update Sun Mar  9 18:41:28 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

t_cmd   *my_cmddelone(t_cmd *del)
{
  t_cmd *tmp;

  if (del == NULL)
    return (NULL);
  tmp = del;
  del = del->next;
  if (del != NULL)
    {
      del->prev = tmp->prev;
      if (del->prev != NULL)
        del->prev->next = del;
    }
  free((char *)tmp->str);
  free((char *)tmp->exe);
  my_arrdel(&(tmp->args));
  free((t_cmd *)tmp);
  return (del);
}
