/*                                                                              
** my_strsub.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:45:09 2014 bourge_v                                
** Last update Sun Mar  9 19:45:12 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

char            *my_strsub(char const *s, unsigned int start, size_t len)
{
  size_t        i;
  char          *str;

  if (!s)
    return (NULL);
  str = (char *)malloc((len + 1) * sizeof(*str));
  if (str == NULL)
    return (NULL);
  i = 0;
  while (i < len && s[(size_t)start + i] != '\0')
    {
      str[i] = s[(size_t)start + i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
