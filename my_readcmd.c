/*                                                                              
** my_readcmd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:56:35 2014 bourge_v                                
** Last update Sun Mar  9 18:47:02 2014 bourge_v                                
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"

char    *my_readcmd(int fd)
{
  int   ret;
  char  buf[2];
  char  *str;

  if (fd < 0)
    return (NULL);
  str = my_strnew(0);
  while ((ret = read(fd, buf, 1)))
    {
      buf[ret] = '\0';
      if (my_strichr(buf, '\n') >= 0)
        return (str);
      str = my_strfjoin(str, my_strdup(buf));
      if (str == NULL)
        {
          my_error(FTSH_NAME, "memory allocation failed.", NULL);
          return (my_strnew(0));
        }
    }
  if (ret == 0)
    free((char *)str);
  return (NULL);
}
