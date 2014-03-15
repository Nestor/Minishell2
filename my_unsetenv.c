/*                                                                              
** my_unsetenv.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 18:05:10 2014 bourge_v                                
** Last update Sun Mar  9 18:47:54 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

static int      my_unsetenv_usage(char **cmd)
{
  int           len;

  len = my_arrsize(cmd);
  if (len != 2)
    {
      if (len < 2)
        my_putendl_fd("unsetenv: missing argument.", 2);
      else if (len > 2)
        my_putendl_fd("unsetenv: too many arguments.", 2);
      my_putendl_fd("usage: unsetenv [KEY]", 2);
      return (-1);
    }
  return (0);
}

static int      my_unsetenv_del(char ***env, char *key)
{
  size_t        i;
  size_t        j;
  char          **tmp;
  char          **new;

  i = 0;
  j = 0;
  tmp = *env;
  if ((new = my_arrnew((size_t)my_arrsize(tmp) - 1)) == NULL)
    return (my_error("unsetenv", "can not delete this key", key));
  while (tmp[i] != NULL)
    {
      if (my_strncmp(tmp[i], key, my_strlen(key)) != 0)
        {
          new[j] = tmp[i];
          j++;
        }
      else
        free((char *)tmp[i]);
      tmp[i] = NULL;
      i++;
    }
  free((char **)tmp);
  *env = new;
  return (0);
}

int             my_unsetenv(t_datas *datas, char **cmd)
{
  if (my_unsetenv_usage(cmd) < 0)
    return (-1);
  if (my_getenv(datas->env, cmd[1]) == NULL)
    return (0);
  return (my_unsetenv_del(&(datas->env), cmd[1]));
}
