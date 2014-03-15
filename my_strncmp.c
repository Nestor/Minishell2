/*                                                                              
** my_strncmp.c for minishell in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:29:35 2014 bourge_v                                
** Last update Sun Mar  9 19:30:17 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t  i;

  i = 0;
  while (i < (n - 1) && s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}
