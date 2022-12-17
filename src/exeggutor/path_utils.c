/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:56:24 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/16 22:11:58 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*absolute_path(char *cmd)
{
	DIR	*dir;

	dir = opendir(cmd);
	if (dir)
	{
		closedir(dir);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(" is a directory", 2);
		g_exit_status = 126;
		exit(g_exit_status);
	}
	if (access(cmd, X_OK) < 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Command not found", 2);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	return (cmd);
}

char	*cmd_path(char *cmd, t_list *env)
{
	if (cmd[0] == '/')
		return (absolute_path(cmd));
	else
		return (relative_path(cmd, env));
}
