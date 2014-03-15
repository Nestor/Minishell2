/*                                                                              
** my_strrchr.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:13:57 2014 bourge_v                                
** Last update Sun Mar  9 20:14:27 2014 bourge_v                                
*/

#include "minishell2.h"

char            *my_strrchr(const char *s, int c)
{
  size_t        i;
  char          chr;
  char          *ptr;

  i = 0;
  chr = c;
  ptr = NULL;
  if (chr == '\0')
    return ((char *)s + my_strlen(s));
  while (s[i] != '\0')
    {
      if (s[i] == c)
        ptr = (char *)s + i;
      i += 1;
    }
  return (ptr);
}
