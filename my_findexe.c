/*                                                                              
** my_findexe.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:29:08 2014 bourge_v                                
** Last update Sun Mar  9 18:44:15 2014 bourge_v                                
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include "minishell2.h"

static int      my_findexe_start(char *exe)
{
  struct stat   infos;

  if (access(exe, F_OK) < 0)
    return (-1);
  if (access(exe, X_OK) < 0)
    return (-1);
  if (stat(exe, &infos) < 0)
    return (-1);
  if (!S_ISREG(infos.st_mode))
    return (-1);
  return (0);
}

static int      my_findexe_check(char *exe)
{
  struct stat   infos;

  if (access(exe, F_OK) < 0)
    return (my_error(exe, ": command not found.", NULL));
  if (access(exe, X_OK) < 0)
    return (my_error(exe, ": permission denied.", NULL));
  if (stat(exe, &infos) < 0)
    return (my_error(exe, ": command not found.", NULL));
  if (!S_ISREG(infos.st_mode))
    return (my_error(exe, ": permission denied.", NULL));
  return (0);
}

static char     *my_findexe_search(char **path, char *exe)
{
  size_t        i;
  DIR           *ptdir;
  struct dirent *datas;

  i = 0;
  while (path[i] != NULL)
    {
      ptdir = opendir(path[i]);
      if (!ptdir)
        return (NULL);
      while ((datas = readdir(ptdir)) != NULL)
        {
          if (my_strcmp(datas->d_name, exe) == 0)
            {
              closedir(ptdir);
              return (my_findexe_prepare(path[i], exe));
            }
        }
      closedir(ptdir);
      i++;
    }
  return (NULL);
}

char            *my_findexe(char **path, char *exe)
{
  char          *tmp;

  if (my_findexe_start(exe) == 0)
    return (my_strdup(exe));
  tmp = my_findexe_search(path, exe);
  if (tmp == NULL)
    return (NULL);
  if (my_findexe_check(tmp) < 0)
    {
      free((char *)tmp);
      return (NULL);
    }
  return (tmp);
}
