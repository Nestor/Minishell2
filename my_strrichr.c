/*                                                                              
** my_strrichr.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:16:03 2014 bourge_v                                
** Last update Sun Mar  9 20:16:30 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_strrichr(const char *s, int c)
{
  int   i;

  i = my_strlen(s);
  while (i-- >= 0)
    {
      if (s[i] == (char)c)
        return (i);
    }
  return (-1);
}
