/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:05:56 by avoltorb          #+#    #+#             */
/*   Updated: 2021/11/26 13:06:40 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 10243

int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *cache, char *buf);
char	*ft_strchr(char *str, char c);
void	ft_strcpy(char *dest, char *src, int len);

#endif
