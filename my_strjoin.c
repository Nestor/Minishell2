/*                                                                              
** my_strjoin.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:51:57 2014 bourge_v                                
** Last update Sun Mar  9 19:52:31 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

char    *my_strjoin(char const *s1, char const *s2)
{
  char  *str;

  if (!s1 || !s2)
    return (NULL);
  str = (char*)malloc((my_strlen(s1) + my_strlen(s2) + 1) * sizeof(char));
  if (str == NULL)
    return (NULL);
  my_strcpy(str, s1);
  my_strcat(str, s2);
  return (str);
}
