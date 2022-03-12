/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:05:56 by avoltorb          #+#    #+#             */
/*   Updated: 2022/03/04 10:59:01 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd, char *line);

int			ft_strlen(char *s);
char		*ft_strjoin(char *cache, char *buf);
char		*ft_strchr(char *str, char c);
void		ft_strncpy(char *dest, char *src, int len);

#endif
