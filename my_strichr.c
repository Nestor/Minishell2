/*                                                                              
** my_strichr.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:07:10 2014 bourge_v                                
** Last update Sun Mar  9 20:07:43 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_strichr(const char *s, int c)
{
  int   i;

  i = 0;
  if (s)
    {
      while (s[i] != '\0')
        {
          if (s[i] == (char)c)
            return (i);
          i++;
        }
    }
  return (-1);
}
