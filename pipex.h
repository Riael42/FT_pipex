/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:08:25 by riael             #+#    #+#             */
/*   Updated: 2023/09/17 16:09:06 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>

char	*ft_strdup(char *s);
char	*ft_strdupi(char *cmd, int i);
void	ft_empty_mat(char **args);
char	**ft_fill_args(char *cmd);
char	*ft_cook_path(char *path, int i, int j);
char	*ft_process_path(char **args, int size, char *path);
void	ft_putstr(char *str);
int		ft_strlen(char *s);
char	*ft_get_path(char **args, int piper, int size);
char	*ft_check_command(char *cmd);
char	**ft_zerowords(void);
int		ft_skipword(char *str, char c, int i);
int		ft_skipspace(char *str, char c, int i);
int		ft_skipstart(char *str, char c);
int		ft_cutend(char *str, char c);
int		ft_countwords(char *str, char c);
char	**ft_split(char *s, char c);
void	ft_pipex(char **cmd_path, int *files, char **cmd1args, char **cmd2args);
void	ft_start_pipe(char **argv, int *files);
void	ft_check_whereis(void);
int		*ft_check_errors(int argc, char **argv);
int		main(int argc, char **argv);
void	ft_stop_pipe(char **cmd1_args, char **cmd2_args, \
					char **cmd_path, int *files);
char	*ft_get_path0(int *pipes, char *path, int size, char **args);
void	ft_get_path1(int *pipes, char **args);

#endif
