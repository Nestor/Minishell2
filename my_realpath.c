/*                                                                              
** my_realpath.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:03:36 2014 bourge_v                                
** Last update Sun Mar  9 20:04:50 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

char            *my_realpath(char *path)
{
  size_t        i;
  char          *tmp;
  char          **arr;

  i = 0;
  if (!path || (arr = my_strsplit(path, '/')) == NULL)
    return (NULL);
  my_bzero(path, (size_t)my_strlen(path));
  if (my_arrsize(arr) <= 0)
    my_strcat(path, "/");
  while (arr[i] != NULL)
    {
      tmp = my_strrchr(path, '/');
      if (my_strcmp(arr[i], "..") == 0 && my_strrichr(path, '/') > 0)
        *tmp = '\0';
      else if (my_strcmp(arr[i], ".") != 0)
        {
          my_strcat(path, "/");
          if (my_strcmp(arr[i], "..") != 0)
            my_strcat (path, arr[i]);
        }
      i++;
    }
  my_arrdel(&arr);
  return (path);
}
