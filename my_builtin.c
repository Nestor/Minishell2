/*                                                                              
** my_builtin.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 16:58:07 2014 bourge_v                                
** Last update Sun Mar  9 18:39:52 2014 bourge_v                                
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell2.h"

int     my_builtin(t_datas *datas, char ***cmd)
{
  int   code;

  if (my_strcmp((*cmd)[0], "exit") == 0)
    {
      code = ((*cmd)[1] != NULL ? my_atoi((*cmd)[1]) : 0);
      my_arrdel(cmd);
      my_exit(datas, code);
    }
  else if (my_strcmp((*cmd)[0], "cd") == 0)
    return (my_cd(datas, *cmd));
  else if (my_strcmp((*cmd)[0], "env") == 0)
    return (my_env(datas, *cmd));
  else if (my_strcmp((*cmd)[0], "setenv") == 0)
    return (my_setenv(datas, *cmd));
  else if (my_strcmp((*cmd)[0], "unsetenv") == 0)
    return (my_unsetenv(datas, *cmd));
  return (42);
}
