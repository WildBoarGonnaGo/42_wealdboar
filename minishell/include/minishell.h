/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/03/16 20:43:07 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include "../srcs/libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <signal.h>

# define BUFFER_SIZE 2048
# define SQUOTE 0b10
# define DQUOTE 0b1
# define ISQUOTE 0b11
# define ESCCHAR 0b100
# define PARAMEXP 0b1000
# define COMCHAR 0b10000
# define TOKTWIDDLE 0b100000
# define HANPIPE 0b1000000
# define HANSEMI 0b10000000
# define ENVSPACE 0b100000000

# define SH_INT_MAX 2147483647

typedef struct		s_gnl
{
	int				st;
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
	char			**argv;
	char			**envp;
	char			**cmd;
	char			**tmp;
	char			**bin;
	char			**clean2;
	char			**pipe_block;
	char			**bin_args;
	char			*backup;
	char			*bin_search;
	char			*line;
	char			*recycle;
	char			*argstr;
	char			*clunit;
	char			*oldpwd;
	char			*cd_tmp;
	void			*clean;
	int				fd_trick;
	int				readenv;
	int				err_status;
	int				fd_pipe[2];
	int				fd_err[2];
	int				fd_redir[2];
	int				argc;
	int				len;
	int				status[3];
	int				fd_recover[3];
	int				if_child;
	int				roll;
	int				lst_flag[2];
	int				pipe_pos[2];
	int				cmd_flag;
	int				env_is_home;
	int				err_fst;
	int				err_pos;
	int				is_export;
	int				err_fd[2];
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
	t_list			*lst_newoper;
}					t_shell;

int					sh_gnl(int fd, char **line);
int					ft_minishell_pwd(t_shell *obj);
void				sh_line_ansys(t_shell *obj);
void				alloc_free_2(void ***mem);
void				ft_minishell_echo(t_shell *obj);
char				*sh_envp_search(const char *str, t_shell *obj);
void				ft_minishell_env(t_shell *obj);
char				*addchar(char *s, char c);
int					sh_user_bin(t_shell *obj);
char				**execve_args(t_shell *obj);
int					change_dir(t_shell *obj);
char				**ft_minishell_export_add(char *str, char ***envp);
char				**ft_minishell_export_sort(char **envp);
int					ft_minishell_export_envplen(char **envp);
void				ft_minishell_export(t_shell *obj);
int					check_export_input(char *str, int count,
					char *cmd, int bit_eq);
void				*memrealloc(void *mem, int oldsize, int addbyte);
int					unset_envp(t_shell *obj);
void				sh_exit(t_shell *obj);
void				sh_read_escape(int sig);
int					check_line(char *line);
int					sh_parcer(t_shell *obj);
void				sh_func_quit(int sig);
void				err_arrow_case(char *str, int count, char c);
int					err_analisys(t_shell *obj);
char				**change_pwd(t_shell *obj, char *envpwd, char *dir);
int					sh_redirects(t_shell *obj, int *index);
int					sh_env_linefix(t_shell *obj, int *st);
void				sh_free_str(char **str);
void				sh_parcer_envp_fix(char **str, int st);
char				**sh_pipe_block_fix(t_shell *obj);
char				*sh_ignore_colon(char *str);
int					err_set_var(t_shell *obj, char *src,
					char *templ, int err_case);
int					sh_err_analisys(char *str, t_shell *obj);
void				err_output(t_shell obj);
int					sh_line_err_parse(t_shell *obj);
int					sh_err_noarg_com(t_list *subj, t_shell *obj);
void				null_lst_unit(void *content);
void				sh_fork_mem_free(t_shell *obj);
char				**sh_envp_dupl(t_shell obj);
void				signal_handle(int sig);
void				sh_signal_proc(t_shell *obj, int sig);
int					sh_token_status(char *str);
int					sh_ambiguous_token(t_list *grabber);
char				**lst_to_arr2(t_list *list, int start, int size);
char				**set_arr2_strbound(char **arr, int *pos,
					char *str, t_shell *obj);
void				sh_list_semicol_fix(t_shell *obj);
void				sh_create_new_lst(t_list **src_lst, t_shell *obj,
					int *info, void (*func)(t_shell *, int *));
void				sh_index_decr(t_shell *obj, int *info);
void				sh_index_paramexp(t_shell *obj, int *info);
void				sh_index_empty(t_shell *obj, int *info);
void				sh_bitwise_or_stat(int *info, t_shell *obj,
					int ctrl_bit);
void				sh_bitwise_and_stat(int *info, t_shell *obj, int ctrl_bit);
void				sh_bitwise_or_stat_spec(int *info, t_shell *obj,
					int ctrl_bit);
void				sh_spec_char_handle(t_shell *obj, int ctrl_bit,
					int *info, void (*func)(int *, t_shell *, int ctrl_bit));
int					sh_delims_override(t_shell *obj);
void				sh_escchar_case_handle(int *st, t_shell *obj);
void				sh_read_env_var(int *st, t_shell *obj);
int					sh_meet_spec_char(t_shell *obj);
int					sh_meet_space_char(t_shell *obj);
void				sh_paramexp_handle(int *st, t_shell *obj);
void				sh_spec_char_init(t_shell *obj, int *st);
int					sh_return_if_env(int st, t_shell *obj);
int					sh_return_spec_init(int st, t_shell *obj);
int					sh_spec_char_return(int st, t_shell *obj);
int					sh_return_meet_space(int st, t_shell *obj);
void				find_elem(t_shell *obj, int st);
void				sh_close_pipes_general(t_shell *obj);
void				sh_kill_proc(t_shell *obj);
int					sh_no_bin_found(t_shell *obj, char **line);
void				sh_search_bin(t_shell *obj, int i, char **line,
					int pos);
void				sh_cmd_err_output(t_shell *obj);
void				sh_bin_line_check(t_shell *obj, char **line, int st);
char				*cd_two_args(t_shell *obj, char **cd_args);
int					cd_two_variables(t_shell *obj);
void				sh_cd_err_output(t_shell *obj, int i);
void				sh_extra_pwd_err(t_shell *obj, char ***cd_clean_2);
void				sh_change_dir_push(t_shell *obj, char ***cd_clean_2,
					char *buf);
void				sh_change_dir_data_init(t_shell *obj, int *i, int *st);
void				sh_close_pipes_common(t_shell *obj);
void				cat_ft_m_export_check(int *pos, char *eq_char,
					t_shell *obj);
char				**change_pwd(t_shell *obj, char *envpwd, char *dir);
char				*cd_two_args(t_shell *obj, char **cd_args);
int					cd_two_args_body(t_shell *obj);
void				change_dir_err_output(t_shell *obj, int i);
void				sh_cd_nonvalid_dir(t_shell *obj, char ***cd_clean_2);
void				sh_change_pwd_box(t_shell *obj, char *envpwd,
					int *info, char ***envp_cd);
void				sh_change_dir_init(t_shell *obj, int *i, int *st);
void				sh_change_dir_proc(t_shell *obj, char ***cd_clean_2,
					char *buf);
char				**change_pwd(t_shell *obj, char *envpwd, char *dir);

#endif
