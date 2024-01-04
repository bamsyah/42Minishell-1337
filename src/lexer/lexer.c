/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:23:16 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/12/28 07:05:00 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->line))
	{
		lexer->i++;
		lexer->c = lexer->line[lexer->i];
	}
}

t_token	*lexer_advance_with(t_token *token, t_lexer *lexer)
{
	lexer_advance(lexer);
	return (token);
}

void	ft_freetmp(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
}

t_token	*lexer_get_char_value(t_lexer *lexer)
{
	char	*value;
	char	*tmp;

	tmp = NULL;
	value = ft_strdup("");
	while (ft_isprint(lexer->c))
	{
		if (lexer->c == '\'')
			tmp = lexer_collect_squote(lexer);
		else if (lexer->c == '\"')
			tmp = lexer_collect_dquote(lexer);
		else if (lexer->c == '$')
			tmp = lexer_collect_dollar(lexer);
		else
		{
			value = ft_strjoin_char(value, lexer->c);
			lexer_advance(lexer);
		}
		if (tmp)
		{
			value = ft_strjoin(value, ft_strdup(tmp));
			ft_freetmp(&tmp);
		}
	}
	return (init_token(value, CMD));
}

t_token	*lexer_get_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0')
	{
		if (ft_iswp(lexer->c))
			lexer_advance(lexer);
		if (lexer->c == '|')
			return (lexer_advance_with(
					init_token(ft_strdup("|"), PIPE), lexer));
		else if (lexer->c == '<')
			return (lexer_collect_larrow(lexer));
		else if (lexer->c == '>')
			return (lexer_collect_rarrow(lexer));
		else if (ft_isprint(lexer->c))
			return (lexer_get_char_value(lexer));
	}
	return (init_token(ft_strdup("EOF"), END));
}
