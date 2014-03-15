/*                                                                              
** my_strchr.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:02:09 2014 bourge_v                                
** Last update Sun Mar  9 20:02:46 2014 bourge_v                                
*/

#include "minishell2.h"

char            *my_strchr(const char *s, int c)
{
  unsigned int  i;
  char          chr;

  i = 0;
  chr = c;
  if (chr == '\0')
    return ((char *)s + my_strlen(s));
  while (s[i] != chr)
    {
      if (s[i] == '\0')
        return (NULL);
      i += 1;
    }
  return ((char *)s + i);
}
