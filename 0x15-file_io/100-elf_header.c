#include "helper.h"

void elf_checker(unsigned char *e_ident);
void magic_printer(unsigned char *e_ident);
void class_printer(unsigned char *e_ident);
void data_printer(unsigned char *e_ident);
void version_printer(unsigned char *e_ident);
void osabi_printer(unsigned char *e_ident);
void abi_printer(unsigned char *e_ident);
void type_printer(unsigned int e_type, unsigned char *e_ident);
void entry_printer(unsigned long int e_entry, unsigned char *e_ident);
void elf_closer(int elf);

/**
* main - Displays the information contained in the
*        ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the file is not an ELF File or
*              the function fails - exit code 98.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int _o, _r;

_o = open(argv[1], O_RDONLY);
if (_o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
elf_closer(_o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
_r = read(_o, header, sizeof(Elf64_Ehdr));
if (_r == -1)
{
free(header);
elf_closer(_o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

elf_checker(header->e_ident);
printf("ELF Header:\n");
magic_printer(header->e_ident);
class_printer(header->e_ident);
data_printer(header->e_ident);
version_printer(header->e_ident);
osabi_printer(header->e_ident);
abi_printer(header->e_ident);
type_printer(header->e_type, header->e_ident);
entry_printer(header->e_entry, header->e_ident);

free(header);
elf_closer(_o);
return (0);
}


/**
*elf_checker - validates whether a file is of elf format
*@e_ident:file desc
*/
void elf_checker(unsigned char *e_ident)
{
if (e_ident[0] == 0x7f &&
e_ident[1] == 'E' &&
e_ident[2] == 'L' &&
e_ident[3] == 'F')
{
printf("ELF Header:\n");
}
else
{
dprintf(STDERR_FILENO, "Error: File is not an ELF file\n");
exit(98);
}
}

/**
* magic_printer - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void magic_printer(unsigned char *e_ident)
{
int n;

printf("  Magic:   ");

for (n = 0; n < EI_NIDENT; n++)
{
printf("%02x", e_ident[n]);

if (n == EI_NIDENT - 1)
	printf("\n");
else
	printf(" ");
}
}


/**
*class_printer - prints an elf's class
*@e_ident:pointer to string
*/
void class_printer(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("This class is invalid\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}


/**
* data_printer - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void data_printer(unsigned char *e_ident)
{
printf("  Data:                              ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}


/**
*version_printer - prints an elf's version
*@e_ident:string pointer
*/
void version_printer(unsigned char *e_ident)
{
printf("  Version:                           ");
if (e_ident[EI_VERSION] == EV_CURRENT)
printf("%i (current)\n", EV_CURRENT);
else
printf("%i\n", e_ident[EI_VERSION]);
}


/**
*osabi_printer - prints an elfs osabi
*@e_ident:string pointer
*/
void osabi_printer(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

