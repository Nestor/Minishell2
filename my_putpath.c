/*                                                                              
** my_putpath.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:51:11 2014 bourge_v                                
** Last update Sun Mar  9 18:46:50 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_putpath(char **env, char *path, int nl)
{
  int   i;
  char  *home;

  home = my_getenv(env, "HOME");
  if (home != NULL && my_strncmp(path, home, my_strlen(home)) == 0)
    {
      my_putchar('~');
      my_putstr(path + my_strlen(home));
    }
  else
    my_putstr(path);
  i = 0;
  while (i++ < nl)
    my_putchar('\n');
}
