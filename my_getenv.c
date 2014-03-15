/*                                                                              
** my_getenv.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:40:18 2014 bourge_v                                
** Last update Sun Mar  9 18:52:00 2014 bourge_v                                
*/

#include <stdio.h>
#include "minishell2.h"

char            *my_getenv(char **env, char *key)
{
  size_t        i;

  if (!env || !key)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], key, my_strlen(key)) == 0)
        return (my_strchr(env[i], '=') + 1);
      i++;
    }
  return (NULL);
}
