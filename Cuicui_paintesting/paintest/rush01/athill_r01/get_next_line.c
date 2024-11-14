
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str1 == 0 || str2 == 0)
		return (0);
	str = (char *)malloc(sizeof(char)
			* (strlen(str1) + strlen(str2) + 1));
	if (str == 0)
		return (0);
	while (str1[i])
		str[j++] = str1[i++];
	i = 0;
	while (str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_bufferjoin(char *static_buffer, const char *temp_buffer)
{
	char	*new;

	new = ft_strjoin(static_buffer, temp_buffer);
	free(static_buffer);
	return (new);
}

char	*ft_read(int fd, char *static_buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	if (static_buffer == NULL)
		static_buffer = calloc(1, 1);
	temp_buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (temp_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buffer);
			free(static_buffer);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		static_buffer = ft_bufferjoin(static_buffer, temp_buffer);
		if (strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (static_buffer);
}

char	*ft_line(const char *static_buffer)
{
	char	*line;
	int		line_len;
	int		i;

	line_len = 0;
	i = 0;
	if (*static_buffer == '\0')
		return (NULL);
	while (static_buffer[line_len] != '\n' && static_buffer[line_len])
		line_len++;
	line = calloc(line_len + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i <= line_len)
	{
		line[i] = static_buffer[i];
		i++;
	}
	return (line);
}

char	*ft_next(char *static_buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\0')
	{
		free(static_buffer);
		return (NULL);
	}
	line = calloc((strlen(static_buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (static_buffer[i] != '\0')
		line[j++] = static_buffer[i++];
	free(static_buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}