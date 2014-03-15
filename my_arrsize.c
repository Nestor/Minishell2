/*                                                                              
** my_arrsize.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:54:55 2014 bourge_v                                
** Last update Sun Mar  9 19:55:22 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_arrsize(char **arr)
{
  int   i;

  i = 0;
  if (arr)
    {
      while (arr[i] != '\0')
        i++;
    }
  return (i);
}
