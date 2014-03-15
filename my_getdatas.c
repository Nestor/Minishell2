/*                                                                              
** my_getdatas.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:37:37 2014 bourge_v                                
** Last update Sun Mar  9 20:00:59 2014 bourge_v                                
*/

#include <unistd.h>
#include "minishell2.h"

static char             **my_basic_env(char **ep)
{
  char                  **env;
  char                  pwd[256];

  if (ep == NULL || ep[0] == NULL)
    {
      env = my_arrnew(3);
      if (env == NULL)
        return (NULL);
      env[0] = my_strjoin("PWD=", getcwd(pwd, 256));
      env[1] = my_strjoin("OLDPWD", my_strchr(env[0], '=') + 1);
      env[2] = my_strdup("PATH=./:/");
    }
  else
    {
      env = my_arrdup(ep);
      if (my_getenv(env, "PWD") == NULL)
        my_arradd(&env, my_strjoin("PWD", getcwd(pwd, 256)));
      if (my_getenv(env, "OLDPWD") == NULL)
        my_arradd(&env, my_strjoin("OLDPWD", my_getenv(env, "PWD")));
      if (my_getenv(env, "PATH") == NULL)
        my_arradd(&env, my_strdup("PATH=./:/"));
    }
  return (env);
}

t_datas                 *my_getdatas(int ac, char **av, char **ep)
{
  static t_datas        datas;
  static t_datas        *ptr;

  if (!ptr)
    {
      datas.todo = NULL;
      datas.env = my_basic_env(ep);
      if (datas.env == NULL)
        return (NULL);
      datas.path = my_getpath(my_getenv(datas.env, "PATH"));
      datas.color = ((ac > 1 && my_strcmp(av[1], "-G") == 0) ? 1 : 0);
      ptr = &datas;
    }
  return (ptr);
}
