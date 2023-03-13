/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnegre <pnegre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:45:40 by pnegre            #+#    #+#             */
/*   Updated: 2023/03/13 12:45:47 by pnegre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char	*line;
    char	*buf;
    int		ret;

    line = malloc(sizeof(char) * 1);
    if (!line)
        return (NULL);
    line[0] = '\0';
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    ret = read(fd, buf, BUFFER_SIZE);
    while (ret > 0)
    {
        buf[ret] = '\0';
        line = ft_strjoin(line, buf);
        if (ft_strchr(buf, '\n'))
            break ;
        ret = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    if (ret < 0)
    {
        free(line);
        return (NULL);
    }
    return (line);   
}
