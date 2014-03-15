/*                                                                              
** my_do.c for minishell2 in /home/bourge_v/Downloads/test/minishell2           
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:16:20 2014 bourge_v                                
** Last update Sun Mar  9 18:42:31 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

static int      my_do_cmd(t_datas *datas, t_cmd *cmd)
{
  int           res;

  if (cmd->args == NULL)
    {
      my_error(FTSH_NAME, "command failed", cmd->str);
      my_cmddelone(cmd);
      return (-1);
    }
  res = my_exec(datas, &(cmd->args));
  return (res);
}

int             my_do(t_datas *datas)
{
  size_t        i;
  int           res;

  if (datas->todo == NULL)
    return (-1);
  i = 0;
  while (datas->todo[i] != NULL)
    {
      if ((datas->todo[i])->next != NULL)
        res = my_exec_piped(datas, &(datas->todo[i]));
      else
        res = my_do_cmd(datas, datas->todo[i]);
      i++;
    }
  return (res);
}
