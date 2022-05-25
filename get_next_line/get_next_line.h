/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:05:34 by hbostan           #+#    #+#             */
/*   Updated: 2022/05/23 10:32:10 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*****HEADER*****/
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*****Main File*****/
char	*get_next_line(int fd);
char	*ft_data_reader(int fd, char *str);
char	*ft_next_str(char *str);
char	*ft_read_line(char *str);

/*****Utils File*****/
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
