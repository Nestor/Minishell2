/*                                                                              
** my_cd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2           
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 16:59:35 2014 bourge_v                                
** Last update Sun Mar  9 18:40:08 2014 bourge_v                                
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "minishell2.h"

static int      my_cd_usage(char **cmd)
{
  int           len;

  len = my_arrsize(cmd);
  if (len != 2)
    {
      if (len < 2)
        my_putendl_fd("cd: missing argument.", 2);
      else if (len > 2)
        my_putendl_fd("cd: too many arguments.", 2);
      my_putendl_fd("usage: cd [PATH]", 2);
      return (-1);
    }
  return (0);
}

static int      my_cd_check(char *path)
{
  struct stat   infos;

  if (access(path, F_OK) < 0)
    return (my_error("cd", "no such file or directory", path));
  if (stat(path, &infos) < 0)
    return (my_error("cd", path, "not found."));
  if (!S_ISDIR(infos.st_mode))
    return (my_error("cd", path, "is not a directory."));
  if (chdir(path) < 0)
    return (my_error("cd", path, "can not open directory."));
  return (0);
}

static char     *my_cd_back(char *path, char **env)
{
  char          *tmp;
  char          *home;
  char          *pwd;
  char          *oldpwd;

  tmp = NULL;
  oldpwd = my_getenv(env, "OLDPWD");
  if (my_strcmp(path, "-") == 0)
    {
      tmp = my_strdup(oldpwd);
      my_putpath(env, my_realpath(tmp), 1);
    }
  else if (my_strcmp(path, "--") == 0)
    {
      pwd = my_getenv(env, "PWD");
      home = my_getenv(env, "HOME");
      if (my_strncmp(pwd, home, my_strlen(home)) == 0)
        tmp = my_strdup(home);
      else
        tmp = my_strdup("/");
    }
  return (tmp);
}

static char     *my_cd_realpath(char *path, char **env)
{
  char          *tmp;

  tmp = NULL;
  if (my_strcmp(path, "-") == 0 || my_strcmp(path, "--") == 0)
    tmp = my_cd_back(path, env);
  else if (my_strcmp(path, "~") == 0)
    tmp = my_strdup(my_getenv(env, "HOME"));
  else if (my_strichr(path, '~') == 0 && my_strichr(path, '/') == 1)
    tmp = my_strjoin(my_getenv(env, "HOME"), my_strchr(path, '/'));
  else if (my_strichr(path, '/') == 0)
    tmp = my_strdup(path);
  else
    {
      tmp = my_strjoin(my_getenv(env, "PWD"), "/");
      tmp = my_strfjoin(tmp, my_strdup(path));
    }
  if (tmp != NULL)
    tmp = my_realpath(tmp);
  return (tmp);
}

int             my_cd(t_datas *datas, char **cmd)
{
  int           res;
  char          *path;
  char          *pwd;

  res = 0;
  if (my_cd_usage(cmd) < 0)
    return (-1);
  path = my_cd_realpath(cmd[1], datas->env);
  if (path == NULL && my_strncmp(cmd[1], "~", 1) == 0)
    return (my_error(cmd[0], "no such file or directory", cmd[1]));
  if (path == NULL)
    return (my_error(cmd[0], "memory allocation failed.", NULL));
  res = my_cd_check(path);
  if (res == 0)
    {
      pwd = my_getenv(datas->env, "PWD");
      res = my_sys_setenv(datas, "cd", "OLDPWD", pwd);
    }
  if (res == 0)
    res = my_sys_setenv(datas, "cd", "PWD", path);
  free((char *)path);
  return (res);
}
