#include "main.h"

char *buffer_creator(char *file);
void file_killer(int fd);


/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the argument count is incorrect - exit code 97.
*              If file_from does not exist or cannot be read - exit code 98.
*              If file_to cannot be created or written to - exit code 99.
*              If file_to or file_from cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
int filefrom, fileto, _read, _write;
char *buff;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buff = buffer_creator(argv[2]);
filefrom = open(argv[1], O_RDONLY);
_read = read(filefrom, buff, 1024);
fileto = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (filefrom == -1 || _read == -1)
{
	dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", argv[1]);
	free(buff);
	exit(98);
}

_write = write(fileto, buff, _read);
if (fileto == -1 || _write == -1)
{
	dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", argv[2]);
	free(buff);
	exit(99);
}

_read = read(filefrom, buff, 1024);
fileto = open(argv[2], O_WRONLY | O_APPEND);

} while (_read > 0);

free(buff);
file_killer(filefrom);
file_killer(fileto);

return (0);
}


/**
* buffer_creator - Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
*
* Return: A pointer to the newly-allocated buffer.
*/

char *buffer_creator(char *file)
{
char *buff;

buff = malloc(sizeof(char) * 1024);

if (buff == NULL)
{
dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", file);
exit(99);
}

return (buff);
}

/**
* file_killer - Closes file descriptors.
* @fd: The file descriptor to be closed.
*/
void file_killer(int fd)
{
int _close;

_close = close(fd);

if (_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
