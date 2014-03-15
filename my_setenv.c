/*                                                                              
** my_setenv.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:57:56 2014 bourge_v                                
** Last update Sun Mar  9 18:47:13 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

static int      my_setenv_usage(char **cmd)
{
  int           len;

  len = my_arrsize(cmd);
  if (len != 3)
    {
      if (len < 3)
        my_putendl_fd("setenv: missing argument.", 2);
      else if (len > 3)
        my_putendl_fd("setenv: too many arguments.", 2);
      my_putendl_fd("usage: setenv [KEY] [VALUE]", 2);
      return (-1);
    }
  return (0);
}

static char     *my_setenv_prepare(t_datas *datas, char **cmd)
{
  char          *str;

  str = my_strnew(my_strlen(cmd[1]) + my_strlen(cmd[2]) + 1);
  if (str == NULL)
    return (NULL);
  my_strcpy(str, cmd[1]);
  my_strcat(str, "=");
  my_strcat(str, cmd[2]);
  if (my_strcmp(cmd[1], "PATH") == 0)
    {
      my_arrdel(&(datas->path));
      datas->path = my_getpath(cmd[2]);
    }
  return (str);
}

int             my_setenv(t_datas *datas, char **cmd)
{
  size_t        i;
  char          **arr;

  if (my_setenv_usage(cmd) < 0)
    return (-1);
  if (my_getenv(datas->env, cmd[1]) != NULL)
    {
      i = 0;
      arr = datas->env;
      while (arr[i] != NULL)
        {
          if (my_strncmp(arr[i], cmd[1], my_strlen(cmd[1])) == 0)
            {
              free((char *)arr[i]);
              if ((arr[i] = my_setenv_prepare(datas, cmd)) == NULL)
                return (-1);
              return (0);
            }
          i++;
        }
    }
  return (my_arradd(&(datas->env), my_setenv_prepare(datas, cmd)));
}
