#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd, ret;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);	
		return (98);
	}
	ret = read(fd, &header, sizeof(header));
	if (ret != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		close(fd);
		return (98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file - it has the wrong magic bytes\n");
		close(fd);
		return (98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2],
			header.e_ident[EI_MAG3], header.e_ident[EI_CLASS], header.e_ident[EI_DATA],
			header.e_ident[EI_VERSION], header.e_ident[EI_OSABI], header.e_ident[EI_ABIVERSION],
			header.e_ident[EI_PAD], header.e_type, header.e_machine, header.e_version);
	printf("Class:%s\n",
			header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
			(header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "none"));
	printf("Data:%s\n",
		header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		(header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "none"));
   	printf("Version:%d (current)\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI:");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
		printf("OS/ABI:				UNIX - System V\n");
		break;
		case ELFOSABI_HPUX:
		printf("OS/ABI:				HP-UX\n");
		break;
		case ELFOSABI_NETBSD:
		printf("OS/ABI:				NetBSD\n");
		break;
		case ELFOSABI_LINUX:
		printf("OS/ABI:				Linux\n");
		break;
		case ELFOSABI_SOLARIS:
		printf("OS/ABI:				Solaris\n");
		break;
		case ELFOSABI_AIX:
		printf("OS/ABI:				AIX\n");
		break;
		case ELFOSABI_IRIX:
		printf("OS/ABI:				IRIX\n");
		break;
		case ELFOSABI_FREEBSD:
		printf("OS/ABI:				FreeBSD\n");
		break;
		case ELFOSABI_TRU64:
		printf("OS/ABI:				TRU64 UNIX\n");
		break;
		case ELFOSABI_MODESTO:
		printf("OS/ABI:				Novell Modesto\n");
		break;
		case ELFOSABI_OPENBSD:
		printf("OS/ABI:				OpenBSD\n");
		break;
		case ELFOSABI_ARM:
		printf("OS/ABI:				 ARM\n");
		break;
		case ELFOSABI_STANDALONE:
		printf("OS/ABI:				 Standalone (embedded) application\n");
		break;
		default:
		printf("OS/ABI:				 Unknown\n");
		break;
	}
	return (1);
}
