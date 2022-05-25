/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:06:15 by hbostan           #+#    #+#             */
/*   Updated: 2022/05/25 16:13:09 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_str(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free (str);
	return (new);
}

char	*ft_read_line(char *str)
{
	char	*newline;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = (char *)malloc((i + 2) * sizeof(char));
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newline[i] = str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*ft_data_reader(int fd, char *str)
{
	char	*buff;
	int		read_to_byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_to_byte = 1;
	while (!ft_strchr(str, '\n') && read_to_byte != 0)
	{
		read_to_byte = read(fd, buff, BUFFER_SIZE);
		if (read_to_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_to_byte] = '\0';
		str = ft_strjoin (str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*newstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newstr = ft_data_reader(fd, newstr);
	if (!newstr)
		return (NULL);
	line = ft_read_line(newstr);
	newstr = ft_next_str(newstr);
	return (line);
}
