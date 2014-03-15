/*                                                                              
** my_strcmp.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:43:12 2014 bourge_v                                
** Last update Sun Mar  9 19:43:32 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_strcmp(const char *s1, const char *s2)
{
  while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
