/*                                                                              
** my_env.c for minishell2 in /home/bourge_v/Downloads/test/minishell2          
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:18:28 2014 bourge_v                                
** Last update Sun Mar  9 18:53:16 2014 bourge_v                                
*/

#include <stdio.h>
#include "minishell2.h"

static int      my_env_usage(char **cmd)
{
  if (my_arrsize(cmd) > 1)
    {
      my_putendl_fd("env: too many arguments.", 2);
      my_putendl_fd("usage: env", 2);
      return (-1);
    }
  return (0);
}

int             my_env(t_datas *datas, char **cmd)
{
  size_t        i;
  char          **env;

  if (my_env_usage(cmd) < 0)
    return (-1);
  i = 0;
  env = datas->env;
  while (env[i] != NULL)
    {
      my_putendl(env[i]);
      i++;
    }
  return (0);
}
