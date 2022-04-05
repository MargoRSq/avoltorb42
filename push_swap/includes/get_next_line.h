/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:05:56 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 15:05:35 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *cache, char *buf);
char	*ft_strchr(char *str, char c);
void	ft_strcpy(char *dest, char *src, int len);

#endif
