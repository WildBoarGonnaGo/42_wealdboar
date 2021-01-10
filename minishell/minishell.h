/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/09 20:53:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./srcs/libft/libft.h"
# include <sys/types.h>
# include <dirent.h> 
# include <sys/wait.h>
# include <errno.h>
# include <string.h>


# define BUFFER_SIZE 2048

typedef struct		s_gnl
{
	int 			st;
	char			buf[2048];
	int				byte;
	int				i;
}					t_gnl;

typedef struct		s_shell
{
	char			**argv;	//пока не применил
	char			**envp; // переменные окружения 
	char			**cmd; // команды
	char			**tmp; // временное хранилище
	char 			**bin; 
	char			*prompt;
	char			*line;
	void			*clean;
	int				fd[2];
	int				argc;
	int				len;
	char			loop;
	char			eol;
	char			exit;
	pid_t			child;
	DIR				*sh_dir;
	struct dirent	*binary;
}					t_shell;

int					sh_gnl(int fd, char **line);
int					ft_minishell_pwd(void);
void				sh_line_ansys(t_shell *obj);
void 				alloc_free_2(void **mem);
void				ft_minishell_echo(t_shell *obj, int indx);
char				*sh_envp_search(const char *str, t_shell obj);
void				ft_minishell_env(t_shell obj);
char				*addchar(char *s, char c);
int					sh_user_bin(t_shell *obj, int indx);

#endif
