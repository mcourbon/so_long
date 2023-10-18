/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:10:18 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/12 11:13:51 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(char *file_map)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	*tmp;
	char	**map;

	fd = open(file_map, O_RDONLY);
	buffer = ft_strdup("");
	if (fd == -1 || buffer == NULL)
		return (free(buffer), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
	return (map);
}
