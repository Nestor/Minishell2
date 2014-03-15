/*                                                                              
** my_strlen.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:12:48 2014 bourge_v                                
** Last update Sun Mar  9 19:22:10 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_strlen(const char *s)
{
  int   i;

  i = 0;
  if (s)
    {
      while (s[i] != '\0')
        i++;
    }
  return (i);
}
