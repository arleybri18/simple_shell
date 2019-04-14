#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	char buf[120], *wbuf = NULL;
	size_t characters = 0, resize = 1;
	ssize_t wr = 0;
	int topen = 0;

	characters = read(STDIN_FILENO, buf, 120);
	wbuf = malloc(120 * sizeof(char));
	topen = open(wbuf, O_APPEND);
	wr = write(topen, wbuf, characters);
	printf("chars:%lu\n", wr);
	printf("buf:%s\n", wbuf);
	if (wr == 120)
	{
		while (wr == 120)
		{
			resize++;
			wbuf = realloc(wbuf, resize * 120);
			characters = read(STDIN_FILENO, buf, 120);
			wr = write(STDIN_FILENO, wbuf, characters);
		}
	}
	return (0);
}
