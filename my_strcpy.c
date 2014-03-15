/*                                                                              
** my_strcpy.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:59:02 2014 bourge_v                                
** Last update Sun Mar  9 19:59:28 2014 bourge_v                                
*/

#include "minishell2.h"

char    *my_strcpy(char *s1, const char *s2)
{
  int   i;

  i = 0;
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      i += 1;
    }
  s1[i] = '\0';
  return (s1);
}
