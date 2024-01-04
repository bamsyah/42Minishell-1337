/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:03:04 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/01/04 20:21:29 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_pwd(t_command *cmd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("getcwd()");
		return ;
	}
	ft_putendl_fd(pwd, cmd->out_fd);
	free(pwd);
	g_gob.ex_status = 0;
}
