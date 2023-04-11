#include "main.h"

/**
 * append_text_to_file - creates a file and fills it with text
 * @filename: name of the file to create
 * @text_content: text to write in the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int _o, _w, length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	_o = open(filename, O_WRONLY | O_APPEND);

	if (_o == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
	while (text_content[length])
	{
		length++;
	}
	}


	_w = write(_o, text_content, length);

	if (_w == -1)
	{
		return (-1);
	}

	if (_w != length)
	{
		return (-1);
	}

	close(_o);

	return (1);
}
