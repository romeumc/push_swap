/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:48:55 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/08 18:05:31 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup_join(char *str, char c)
{
	size_t	i;
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		temp[i] = str[i];
		i++;
	}
	temp[i++] = c;
	temp[i] = '\0';
	free(str);
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char	buffer[1];
	int		result;

	result = 1;
	line[0] = malloc(sizeof(char));
	if (line[0] == NULL)
		return (-1);
	*line[0] = '\0';
	while (result != 0)
	{
		result = read(fd, buffer, 1);
		if (result < 0)
			return (-1);
		if (buffer[0] == '\0')
			return (0);
		else if (buffer[0] == '\n')
			return (1);
		else
			line[0] = ft_strdup_join(line[0], buffer[0]);
	}
	return (0);
}
