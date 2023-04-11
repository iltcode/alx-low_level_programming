#include "main.h"

/**
  * read_textfile - ...
  * @filename: The source file
  * @letters: Number of letters to reads and prints
  *
  * Return: The number of letters printed, or 0 if it failed
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int _o, _r, _w;
	char *buf;

	if (filename == NULL)
	{
		return (0);
	}

	buf = malloc(sizeof(char *) * letters);

	if (buf == NULL)
	{
		return (0);
	}


	_o = open(filename, O_RDONLY);
	if (_o == -1)
	{
		return (0);
	}

	_r = read(_o, buf, letters);
	if (_r == -1)
	{
		return (0);
	}

	_w = write(STDOUT_FILENO, buf, _r);
	if (_w == -1)
	{
		return (0);
	}

	free(buf);
	close(_o);
	return (_w);
}
