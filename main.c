# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <inttypes.h>
# include "libasm.h"
# include <errno.h>

void show_error()
{
	printf("\x1b[91mValue of errno: %d. \x1b[0m", errno);
	printf("\x1b[91mError: %s\x1b[0m\n", strerror( errno ));
	errno = 0;
	return ;
}

int main(void)
{
  	int			fd;
	char		buffer[100];
	char		show[100];
	char		dst[400];
	ssize_t		ret;

//FT_STRLEN
	system("clear");
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
	printf("\x1b[34m[4]\x1b[0m \x1b[36m'asdfasdf''///##!!@'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("asdfasdf''///##!!@"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("asdfasdf''///##!!@"));
	printf("\x1b[34m[5]\x1b[0m \x1b[36m'the 0hidden'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("the\0hidden"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("the\0hidden"));
	printf("\x1b[34m[6]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	//printf("\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(NULL));
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(NULL));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	getchar();
	system("clear");

//FT_STRCMP
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("\x1b[34m[2]\x1b[0m \x1b[36m'toto' 'toto'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", "toto"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", "toto"));
	printf("\x1b[34m[3]\x1b[0m \x1b[36m'toto' ''\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", ""));
	printf("\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", ""));
	printf("\x1b[34m[4]\x1b[0m \x1b[36m'' 'toto'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "toto"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", "toto"));
	printf("\x1b[34m[5]\x1b[0m \x1b[36m'tototest' 'toto'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("tototest", "toto"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("tototest", "toto"));
	printf("\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
	printf("\x1b[34m[7]\x1b[0m \x1b[36m'abcdefghijasdf1324''klji//' 'abcdefghijasdf1324''klji//'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("abcdefghijasdf1324''klji//", "abcdefghijasdf1324''klji//"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("abcdefghijasdf1324''klji//", "abcdefghijasdf1324''klji//"));
	printf("\x1b[34m[8]\x1b[0m \x1b[36m'the\\0hidden' 'the\\0hidden'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("the\0hidden", "the\0hidden"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("the\0hidden", "the\0hidden"));

	printf("\x1b[34m[9]\x1b[0m \x1b[36m'\\xff' '\\xff'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("\xff", "\xff"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("\xff", "\xff"));

	printf("\x1b[34m[10]\x1b[0m \x1b[36m'\\x01\\x01' '\\x01'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("\x01\x01", "\x01"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("\x01\x01", "\x01"));

	printf("\x1b[34m[11]\x1b[0m \x1b[36m'111+}Te'st!wi/th*[<<As:c2ii3' '111+}Te'st!wi/th*[<<As:c2ii3'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii3"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii3"));

	printf("\x1b[34m[12]\x1b[0m \x1b[36m'\\x12\\xff' '\\x12\\0'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("\x12\xff", "\x12\0"));
	printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("\x12\xff", "\x12\0"));

	printf("\x1b[34m[13]\x1b[0m \x1b[36m'NULL' 'bbonjour'\x1b[0m\n");
	//printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp(NULL, "bbonjour"));
	printf("\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp(NULL, "bbonjour"));
	printf("\x1b[33m<libasm.h>\x1b[0m %s\n", "SEGMENTATION FAULT");

	printf("\x1b[34m[14]\x1b[0m \x1b[36m'NULL' 'NULL'\x1b[0m\n");
	//printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp(NULL, NULL));
	printf("\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp(NULL, NULL));
	printf("\x1b[33m<libasm.h>\x1b[0m %s\n", "SEGMENTATION FAULT");

	printf("\x1b[34m[15]\x1b[0m \x1b[36m'' 'NULL'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", NULL));
	printf("\x1b[33m<libasm.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", NULL));
	getchar();
	system("clear");
//FT_STRCPY
	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "toto"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "toto"));
	printf("\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
	printf("\x1b[34m[4]\x1b[0m \x1b[36m'yope 0la'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "yope\0la"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "yope\0la"));
	printf("\x1b[34m[5]\x1b[0m \x1b[36m'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis.'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis."));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis."));
	printf("\x1b[34m[6]\x1b[0m \x1b[36m'\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0b\\x0c\\x0d\\x0e\\x0f'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f"));


	printf("\x1b[34m[7]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	//printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", strcpy(dst, NULL));
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, NULL));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	getchar();
	system("clear");
//FT_STRDUP
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strdup("toto"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("toto"));
	printf("\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strdup("0123456789"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("0123456789"));
	printf("\x1b[34m[4]\x1b[0m \x1b[36m'\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0b\\x0c\\x0d\\x0e\\x0f'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", strdup("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f"));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f"));
	printf("\x1b[34m[5]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<string.h>\x1b[0m  %s\n", strdup(NULL));
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	//printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(NULL));
  	getchar();
	system("clear");

// TEST FT_READ
	system("clear");
	printf("\x1b[32mft_read:\x1b[0m\n");
//1
	printf("\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
//2
	printf("\x1b[34m[2]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '5'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
//3
	printf("\x1b[34m[3]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '-5'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, -5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, -5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");
//4
	printf("\x1b[34m[4]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '200'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);

	getchar();
	system("clear");
//5
	printf("\x1b[34m[5]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '0'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	printf(" fd: %i \n",fd);
	ret = read(fd, NULL, 0);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, 0);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//6
	printf("\x1b[34m[6]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//7
	printf("\x1b[34m[7]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '-10'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, -10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, -10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	getchar();
	system("clear");
//8
	printf("\x1b[34m[8]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '200'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");

//TEST MAKEFILE
//9
	printf("\x1b[34m[9]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, buffer, 0);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 0);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
//10

	printf("\x1b[34m[10]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' '' '5'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, buffer, 5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
//11
	printf("\x1b[34m[11]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' '' '-5'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, buffer, -5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, buffer, -5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	getchar();
	system("clear");
//12
	printf("\x1b[34m[12]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' '' '200'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, buffer, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");
//13
	printf("\x1b[34m[13]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' 'NULL' '0'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	printf(" fd: %i \n",fd);
	ret = read(fd, NULL, 0);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 0);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//14
	printf("\x1b[34m[14]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//15
	printf("\x1b[34m[15]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' 'NULL' '-10'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, NULL, -10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, NULL, -10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	getchar();
	system("clear");
//16
	printf("\x1b[34m[16]\x1b[0m \x1b[36m'open(\"makefile\", O_RDONLY)' 'NULL' '200'\x1b[0m\n");
	fd = open("makefile", O_RDONLY);
	ret = read(fd, NULL, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");

//TEST dont exist file
//17
	printf("\x1b[34m[17]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 0);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 0);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	show_error();
	close(fd);
//18

	printf("\x1b[34m[18]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '5'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
//19
	printf("\x1b[34m[11]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '-5'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, -5);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, -5);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 5));
	show_error();
	close(fd);
	getchar();
	system("clear");
//20
	printf("\x1b[34m[20]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '200'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");
//21
	printf("\x1b[34m[21]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' 'NULL' '0'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, NULL, 0);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, NULL, 0);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//22
	printf("\x1b[34m[22]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	printf(" fd: %i \n",fd);
	ret = read(fd, NULL, 10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
//23
	printf("\x1b[34m[23]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' 'NULL' '-10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	printf(" fd: %i \n",fd);
	ret = read(fd, NULL, -10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, NULL, -10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	show_error();
	close(fd);
	getchar();
	system("clear");
//24
	printf("\x1b[34m[24]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' 'NULL' '200'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	printf(" FD = %i \n",fd);
	ret = read(fd, NULL, 200);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("dontexist", O_RDONLY);
	printf(" FD = %i \n",fd);
	ret = ft_read(fd, NULL, 200);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();

	system("clear");


	printf("\x1b[32mft_read: 2 of 2 \x1b[0m\n");
// TEST VARIOS
//25
	printf("\x1b[34m[25]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	ret = ft_read(42, buffer, 10);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	getchar();
	system("clear");
//26
	errno = 0;
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("\x1b[34m[26]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '1' '10'\x1b[0m\n");
	ret = read(fd, buffer, 1);
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	ret = ft_read(fd, buffer, 1);
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, buffer);
	show_error();
	close(fd);
	remove("empty_file");

	getchar();
	system("clear");

//FT_WRITE
//1
	printf("\x1b[32mft_write in standard output:\x1b[0m\n");
	printf("\x1b[34m[1]\x1b[0m \x1b[36m ft_write('1' '' '0')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	show_error();
//2
	printf("\x1b[34m[2]\x1b[0m \x1b[36mft_write('1' 'Writing in standard' '19')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "Writing in standard", 19));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "Writing in standard", 19));
	show_error();
//3
	printf("\x1b[34m[3]\x1b[0m \x1b[36mft_write('1' 'Writing in standard' '2')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "Writing in standard", 2));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "Writing in standard", 2));
	show_error();
//4
	printf("\x1b[34m[4]\x1b[0m \x1b[36mft_write('1' 'Writing in standard' '40')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "Writing in standard", 40));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "Writing in standard", 40));
	show_error();
	getchar();
	system("clear");
//5
	printf("\x1b[34m[5]\x1b[0m \x1b[36mft_write('1' 'NULL' '6')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	show_error();
//6
	printf("\x1b[34m[6]\x1b[0m \x1b[36mft_write('0' 'toto' '4')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	show_error();
//7
	printf("\x1b[34m[7]\x1b[0m \x1b[36mft_write('42' 'toto' '4'\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	show_error();
//8
	printf("\x1b[34m[8]\x1b[0m \x1b[36mft_write('-1' 'toto' '4')\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
	show_error();
	printf("\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
	show_error();

	getchar();
	system("clear");

// checking write in file
	printf("\x1b[32mft_write en archivo :\x1b[0m\n");
	fd = open("test_write", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("\x1b[34m[9]\x1b[0m \x1b[36m'open(\"test_write\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	printf("\x1b[34m[9]\x1b[0m \x1b[36m'writing \"string write by write\" in \"test_write\" with funtion: \"write\"\x1b[0m\n");
	write(fd, "string write by write", 21);
	show_error();
	ft_write(fd, "string write by ftwrite", 23);
	printf("\x1b[34m[9]\x1b[0m \x1b[36m'writing \"string write by ftwrite\" in \"test_write\" with funtion: \"ft_write\"\x1b[0m\n");
	show_error();
	close(fd);

	printf("\n\x1b[34m[9]\x1b[0m \x1b[36m'check writing in \"test_write\"\x1b[0m\n");
	fd = open("test_write", O_RDONLY);
	read(fd, buffer, 21);
	printf("\x1b[34m[9]\x1b[0m \x1b[36m' Checking write in \"test_write\" with funtion: \"read\"\x1b[0m\n");
	printf("\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
	show_error();
	ft_read(fd, buffer, 23);
	printf("\x1b[34m[9]\x1b[0m \x1b[36m' Checking write in \"test_write\" with funtion: \"ft_read\"\x1b[0m\n");
	printf("\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
	show_error();
	close(fd);
	remove("test_write");

	getchar();
	system("clear");

	printf("\n\x1b[34m[10]\x1b[0m \x1b[36m' Not open file descriptor. \x1b[0m\n");
	printf("\x1b[34m[10]\x1b[0m \x1b[36m' Trying to writing \"string write by write\" in \"test_write\" with funtion: \"write\"\x1b[0m\n");
	write(fd, "string write by write", 21);
	show_error();
	ft_write(fd, "string write by ftwrite", 23);
	printf("\x1b[34m[10]\x1b[0m \x1b[36m' Trying to writing \"string write by ftwrite\" in \"test_write\" with funtion: \"ft_write\"\x1b[0m\n");
	show_error();
	close(fd);

return (0);
}
