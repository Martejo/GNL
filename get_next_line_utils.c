/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:46 by gemartel          #+#    #+#             */
/*   Updated: 2023/11/20 17:28:06 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}

char	*str_init(char *s)
{
	s = (char *)malloc(1 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}
