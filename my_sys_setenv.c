/*                                                                              
** my_sys_setenv.c for minishell2 in /home/bourge_v/Downloads/test/minishell2   
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 18:03:43 2014 bourge_v                                
** Last update Sun Mar  9 18:47:41 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_sys_setenv(t_datas *datas, char *cmd, char *key, char *val)
{
  int   res;
  char  **args;

  args = my_arrnew(3);
  args[0] = my_strdup("setenv");
  if (args[0] == NULL)
    return (my_error(cmd, "memory allocation failed.", NULL));
  args[1] = my_strdup(key);
  if (args[1] == NULL)
    {
      my_arrdel(&args);
      return (my_error(cmd, "memory allocation failed.", NULL));
    }
  args[2] = my_strdup(val);
  if (args[2] == NULL)
    {
      my_arrdel(&args);
      return (my_error(cmd, "memory allocation failed.", NULL));
    }
  res = my_setenv(datas, args);
  my_arrdel(&args);
  return (res);
}
