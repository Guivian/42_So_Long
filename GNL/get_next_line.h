/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:40:04 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/29 18:06:18 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*feed_saved(int fd, char *saved);
char	*find_line(char *saved);
char	*after_nl(char *saved);
size_t	ft_strlen(char *str);
char	*find_nl(char *s);
char	*gnl_strjoin(char *s1, char *s2);

#endif
