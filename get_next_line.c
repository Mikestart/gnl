
#include "get_next_line.h"

char 	*ft_divider(int fd);
char	*get_next_line(int fd)
{
	char *line;
	
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier");
		return ("-1");
	}
	line = ft_divider(fd);
	return(line);
}

char *ft_divider(int fd)
{
	char *buffer;
	static char *stash;	
	ssize_t i;
	int j;

	stash = "?";
	i = 0;
	j = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = read(fd, buffer, BUFFER_SIZE);
	while (buffer[j])
	{	
		printf("%s", buffer);
		j++;
	}

	return(stash);
}

int	main	(void)
{
	int fd;
	static char *buf;
	fd = open("text.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("%s\n", buf);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}