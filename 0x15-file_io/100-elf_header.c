#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error - print an error message to stderr and exit with failure status code
 * @msg: the error message to print
 */
void error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - entry point
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd, n;
	Elf64_Ehdr hdr;

	if (argc != 2)
		error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("open");

	n = read(fd, &hdr, sizeof(hdr));
	if (n == -1)
		error("read");
	if (n < (int) sizeof(hdr))
		error("incomplete ELF header");

	if (hdr.e_ident[EI_MAG0] != ELFMAG0 ||
	    hdr.e_ident[EI_MAG1] != ELFMAG1 ||
	    hdr.e_ident[EI_MAG2] != ELFMAG2 ||
	    hdr.e_ident[EI_MAG3] != ELFMAG3)
		error("not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
	       hdr.e_ident[EI_MAG0], hdr.e_ident[EI_MAG1], hdr.e_ident[EI_MAG2], hdr.e_ident[EI_MAG3],
	       hdr.e_ident[EI_CLASS], hdr.e_ident[EI_DATA], hdr.e_ident[EI_VERSION],
	       hdr.e_ident[EI_OSABI], hdr.e_ident[EI_ABIVERSION],
	       hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD], hdr.e_ident[EI_PAD]);
	printf("  Class:                             %s\n", hdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", hdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", hdr.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (hdr.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV: printf("UNIX - System V"); break;
	case ELFOSABI_HPUX: printf("UNIX - HP-UX"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD"); break;
	case ELFOSABI_LINUX: printf("UNIX - GNU"); break;
	case ELFOSABI_SOLARIS: printf("UNIX - Solaris"); break;
	case ELFOSABI_AIX: printf("UNIX - AIX"); break;
	case ELFOSABI_IRIX: printf("UNIX - IRIX"); break;
	case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD"); break;
	case ELFOSABI_TRU64: printf("UNIX - TRU64"); break;
	case ELFOSABI_MODESTO: printf("Novell Modesto"); break;
	}
	return (0);
}
