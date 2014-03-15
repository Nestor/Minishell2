/*                                                                              
** my_isbuiltin.c for minishell2 in /home/bourge_v/Downloads/test/minishell2    
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:46:31 2014 bourge_v                                
** Last update Sun Mar  9 18:45:57 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_isbuiltin(char *cmd)
{
  if (my_strcmp(cmd, "exit") == 0
      || my_strcmp(cmd, "cd") == 0
      || my_strcmp(cmd, "env") == 0
      || my_strcmp(cmd, "setenv") == 0
      || my_strcmp(cmd, "unsetenv") == 0)
    return (1);
  return (0);
}
