#include "main.h"

/**
 * create_file - creates a file and fills it with text
 * @filename: name of the file to create
 * @text_content: text to write in the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int _o, _w, length = 0;

	if (filename == NULL)
	{
		return (0);
	}

	_o = open(filename, O_CREAT | O_RDWR | O_TRUNC);

	while (text_content[length])
	{
		length++;
	}

	_w = write(_o, text_content, length);

	if (_w != length)
	{
		return (0);
	}

	close(_o);

	return (1);
}
