/*                                                                              
** my_strdup.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:41:19 2014 bourge_v                                
** Last update Sun Mar  9 19:41:58 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

char            *my_strdup(const char *s)
{
  unsigned int  i;
  char          *cpy;

  if (!s)
    return (NULL);
  i = 0;
  cpy = (char *) malloc((my_strlen(s) + 1) * sizeof(*cpy));
  if (cpy != NULL)
    {
      while (s[i] != '\0')
        {
          cpy[i] = s[i];
          i += 1;
        }
      cpy[i] = '\0';
    }
  return (cpy);
}
