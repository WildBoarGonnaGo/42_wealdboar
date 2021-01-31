/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/31 20:00:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include "./srcs/libft/libft.h"
# include <sys/types.h>
# include <dirent.h> 
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <signal.h>

# define BUFFER_SIZE 2048

static int			sig_state;

typedef struct		s_gnl
{
	int 			st;
	char			buf[2048];
	int				byte;
	int				i;
	int				fd_pipe[2];
	pid_t			gnl_fork;
	int				wstatus;
	int				orig_stdout;
	int				len;
}					t_gnl;

typedef struct		s_shell
{
	char			**argv;	// пока не применил
	char			**envp; // переменные окружения 
	char			**cmd; // команды
	char			**tmp; // временное хранилище
	char 			**bin; 
	char			**clean2;
	char			**pipe_block;
	char			**bin_args;
	char			**envp_secure;
	char			*backup;
	char			*bin_search;
	char			*line;
	char			*recycle;
	char			*argstr;
	void			*clean;
	int				fd_pipe[2];
	int				fd_err[2];
	int				argc;
	int				len;
	int				status[2];
	int				fd_recover[3];
	char			loop;
	char			eol;
	char			exit;
	char			spec_char;
	pid_t			sh_pid[2];
	pid_t			child;
	DIR				*sh_dir;
	struct dirent	*binary;
	t_list			*lst_start;
	t_list			*lst_head;
}					t_shell;

int					sh_gnl(int fd, char **line);
int					ft_minishell_pwd(t_shell *obj, int indx);
void				sh_line_ansys(t_shell *obj);
void 				alloc_free_2(void **mem);
void				ft_minishell_echo(t_shell *obj, int indx);
char				*sh_envp_search(const char *str, t_shell obj);
void				ft_minishell_env(t_shell *obj, int indx);
char				*addchar(char *s, char c);
int					sh_user_bin(t_shell *obj, int indx);
char 				**execve_args(t_shell *obj, int indx);
int 				change_dir(t_shell *obj, int indx);
char				**ft_minishell_export_add(char *str, char ***envp);
char				**ft_minishell_export_sort(char **envp);
int					ft_minishell_export_envplen(char **envp);
void				ft_minishell_export(t_shell *obj, int indx);
int					check_export_input(char *str, int count, char *cmd, int bit_eq);
void				*memrealloc(void *mem, int oldsize, int addbyte);
int 				unset_envp(t_shell *obj, int indx);
int 				sh_exit(t_shell *obj, int indx);
void				sh_read_escape(int sig);
int					check_line(char *line);
t_list				*sh_parcer(t_shell *obj, char *line);

#endif
