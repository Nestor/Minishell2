/*                                                                              
** my_cmdnew.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:09:24 2014 bourge_v                                
** Last update Sun Mar  9 18:41:46 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

t_cmd   *my_cmdnew(t_datas *datas, char *cmd)
{
  t_cmd *new;

  if (!cmd)
    return (NULL);
  new = (t_cmd *)malloc(sizeof(t_cmd));
  if (new == NULL)
    return (NULL);
  new->str = my_strdup(cmd);
  new->args = my_cmdsplit(cmd);
  if (new->args == NULL || my_isbuiltin(new->args[0]) == 1)
    new->exe = NULL;
  else
    new->exe = my_findexe(datas->path, new->args[0]);
  new->prev = NULL;
  new->next = NULL;
  return (new);
}
