/*                                                                              
** my_strcat.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:57:54 2014 bourge_v                                
** Last update Sun Mar  9 20:01:47 2014 bourge_v                                
*/

#include "minishell2.h"

char            *my_strcat(char *dest, const char *src)
{
  unsigned int  i;
  unsigned int  len;

  i = 0;
  len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[len + i] = src[i];
      i += 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
