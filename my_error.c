/*                                                                              
** my_error.c for minishell2 in /home/bourge_v/Downloads/test/minishell2        
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:19:54 2014 bourge_v                                
** Last update Sun Mar  9 18:50:46 2014 bourge_v                                
*/

#include <stdio.h>
#include "minishell2.h"

int     my_error(char *cmd, char *msg, char *arg)
{
  if (cmd != NULL)
    my_putstr_fd(cmd, 2);
  else
    my_putstr_fd(FTSH_NAME, 2);
  if (msg != NULL)
    {
      my_putstr_fd(": ", 2);
      my_putstr_fd(msg, 2);
    }
  if (arg != NULL)
    {
      my_putstr_fd(": ", 2);
      my_putendl_fd(arg, 2);
    }
  else
    my_putchar_fd('\n', 2);
  return (-1);
}
