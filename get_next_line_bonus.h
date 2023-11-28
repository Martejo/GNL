/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:38 by gemartel          #+#    #+#             */
/*   Updated: 2023/11/24 09:40:05 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_fd
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}	t_fd;

char	*ft_strdup(const char *str);
size_t	gnl_ft_strlen(char *s);
char	*get_next_line(int fd);
char	*str_init(char *s);
char	*init_buffer(int fd, t_fd *buffer_memory);

#endif