/*                                                                              
** my_strtrim.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:10:42 2014 bourge_v                                
** Last update Sun Mar  9 19:12:11 2014 bourge_v                                
*/

#include "minishell2.h"

char            *my_strtrim(char *s)
{
  size_t        i;
  size_t        j;
  int           space;

  if (!s)
    return (NULL);
  i = 0;
  j = 0;
  space = 1;
  while (s[i] != '\0')
    {
      if (my_isspace(s[i]) == 0)
        {
          if (j > 0 && space == 1)
            s[j++] = ' ';
          space = 0;
          s[j] = s[i];
          j++;
        }
      else
        space = 1;
      i++;
    }
  my_bzero((s + j), i - j);
  return (s);
}
