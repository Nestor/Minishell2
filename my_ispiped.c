/*                                                                              
** my_ispiped.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:47:45 2014 bourge_v                                
** Last update Sun Mar  9 18:46:13 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_ispiped(char *cmd)
{
  int   i;
  int   isquote;

  i = 0;
  isquote = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '"' && isquote == 0)
        isquote = 1;
      else if (cmd[i] == '"' && isquote == 1)
        isquote = 0;
      if (cmd[i] == '|' && isquote == 0)
        return (1);
      i++;
    }
  return (0);
}
