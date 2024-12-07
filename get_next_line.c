#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*ft_get_line(char *buffer)
{
	char	*endOfLine;
	char	*line;

	endOfLine = ft_strchr(buffer, '\n');
	if (!endOfLine)
		endOfLine = buffer + ft_strlen(buffer);

	line = ft_substr(buffer, 0, endOfLine - buffer + 1);
	return (line);
}

static char *ft_trim_buffer(char *buffer)
{
    char *endOfLine;
    char *trimmed;

    endOfLine = ft_strchr(buffer, '\n');
    if (!endOfLine)
    {
        free(buffer);
        return (NULL);
    }
    trimmed = ft_substr(buffer, (endOfLine - buffer) + 1, ft_strlen(buffer) - (endOfLine - buffer));
    if (!trimmed) // Check if allocation failed
    {
        free(buffer);
        return (NULL);
    }
    free(buffer); // Free old buffer
    return (trimmed);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (line);
}
