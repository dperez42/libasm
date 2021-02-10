
#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>

size_t		ft_strlen(char *src);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *dst, char *src);
char		*ft_strdup(char *src);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);

#endif
