#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
} t_list;

size_t ft_strlen(const char *s);
char *ft_strcpy(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char *ft_strdup(const char *s);

int	ft_list_size(t_list *begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);

int main(int argc, char *argv[])
{
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
		int ret = ft_write(1, "if you see this ft_write passed test n1\n", 47);
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
	if (argc == 2 && strcmp(argv[1], "bonus") == 0) {
		printf("testing bonus\n");
		t_list c = {"c",NULL};
		t_list b = {"b",&c};
		t_list a = {"a",&b};
		int size = ft_list_size(&a);
		if (size != 3)
			printf("ft_list_size problem test n1. size != 2\n");
		t_list	*ptr = &a;
		ft_list_push_front(&ptr, "first");
		if (strcmp(ptr->data, "first") != 0)
			printf("ft_list_push_front problem nest n1. new front should be 'first' but is %s", (char *)ptr->data);
		t_list *ptr2 = NULL;
		ft_list_push_front(&ptr2, "test");
		if (!ptr)
			printf("ft_list_push_front problem nest n2. ptr2 is null");
		if (strcmp(ptr2->data, "test") != 0)
			printf("ft_list_push_front problem nest n3. ptr2->data shoud be 'test' but is %s", (char *)ptr->data);
	}
	return EXIT_SUCCESS;
}
