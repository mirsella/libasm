#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char *ft_strdup(const char *s);

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	{
		char test[] = "Hello World";
		if (ft_strlen(test) != strlen(test))
			printf("ft_strlen problem test n1. %s\n", test);
		if (ft_strlen("") != strlen(""))
			printf("ft_strlen problem test n2. ''\n");
	}
	{
		char test[] = "Hello World";
		char *dest = malloc(sizeof(char) * strlen(test) + 1);
		char *ret = ft_strcpy(dest, test);
		if (ret != dest)
			printf("ft_strcpy problem test n1. ret == dest\n");
		if (strcmp(ret, "Hello World"))
			printf("ft_strcpy problem test n2. ret == 'Hello World'\n");
		free(dest);
	}
	{
		if (ft_strcmp("Hello", "Hello") != strcmp("Hello", "Hello"))
			printf("ft_strcmp problem test n1. 'Hello' == 'Hello'\n");
		if (ft_strcmp("Hell", "Hello") >= 0)
			printf("ft_strcmp problem test n2. 'Hell' == 'Hello'\n");
		if (ft_strcmp("", "") != strcmp("", ""))
			printf("ft_strcmp problem test n3. '' == ''\n");
		if (ft_strcmp("HelloA", "Hello") <= 0)
			printf("ft_strcmp problem test n4. 'HelloA' == 'Hello'\n");
	}
	{
		int ret = ft_write(1, "ft_write if you see this write passed test n1\n", 47);
		if (ret != 47)
			printf("ft_write problem test n2. return size\n");
		write(-1, "test", 4);
		int write_errno = errno;
		ft_write(-1, "test", 4);
		int ft_write_errno = errno;
		if (write_errno != ft_write_errno)
			printf("ft_write problem test n3. errno\n");
	}
	{
		int f1 = open(argv[0], 0);
		char b1[200];
		b1[read(f1, &b1, 200)] = 0;

		int f2 = open(argv[0], 0);
		char b2[200];
		b2[ft_read(f2, &b2, 200)] = 0;

		if (strcmp(b1, b2))
			printf("ft_read problem test n1. reading argv[0]\n");
		close(f1);
		close(f2);
	}
	{
		errno = 0;
		char test[] = "Hello World";
		char *dup = ft_strdup(test);
		if (strcmp(test, dup))
			printf("ft_strdup problem test n1. strdup(%s) -> %s \n", test, dup);
		free(dup);
	}
	return EXIT_SUCCESS;
}
