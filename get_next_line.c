/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:44:16 by gemartel          #+#    #+#             */
/*   Updated: 2023/11/23 10:39:36 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *s, char *buffer)
{
	char	*dest;
	int		i;
	int		j;
	int		buff_len;

	i = 0;
	j = 0;
	buff_len = gnl_ft_strlen(buffer);
	dest = (char *)malloc((gnl_ft_strlen(s) + buff_len + 1) * sizeof(char));
	if (!dest)
		return (free(s), NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	free(s);
	while (j < buff_len && buffer[j - 1] != '\n')
	{
		dest[i] = buffer[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (0);
}

int	update_gnl(char *dest, char *src, char **str)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*str = extract_line(*str, dest);
	if (*str == NULL)
		return (-1);
	return (1);
}

char	*read_line(int fd, char *str, char *buffer)
{
	ssize_t	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			break ;
		buffer[byte_read] = '\0';
		str = extract_line(str, buffer);
		if (str == NULL)
			return (NULL);
		if ((check_new_line(str) > 0 || byte_read == 0) && str[0] != 0)
			return (str);
	}
	buffer[0] = '\0';
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	str = str_init(str);
	if (!str)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1
		|| (update_gnl(buffer, &buffer[check_new_line(buffer)], &str)) < 0)
		return (free(str), NULL);
	if (check_new_line(str) > 0)
		return (str);
	return (read_line(fd, str, buffer));
}
/*#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  char  *line;
  int fd;
 
  if (argc != 2)
    return 1;
  //printf("%s\n", argv[1]);
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    return 1;
  while ((line = get_next_line(fd)) != NULL)
  {
    printf("line = %s", line);
    free(line);
  }
  return 0;
}*/
