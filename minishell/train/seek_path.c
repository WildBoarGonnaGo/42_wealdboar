#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	if (argc != 1)
	{
		perror("Too much arguments.\n");
		return (1);
	}
	struct dirent *de; //Входная точка в директорию
	// opendir() возвращает указатель на тип данных DIR
	DIR *dr;

	if (!(dr = opendir("/")))
	{
		printf("Could not open current directory.\n");
		return (1);
	}
	/*readdir() - функция которая возвращает указатель на стукртуру типа dirent
	 которая представляет собой взод в следую директорию в канале директории на
	 которую указывает dirp. Она возвращает NULL если достигнут конец директории или
	 если возникла ошибка
	 
	 glibc вариант структуры dirent представлена ниже
	 struct dirent 
	 {
	 	ino_t			d_ino;		Индексный дескриптор
		off_t			d_off;  	Не оффсет (см. ниже)
		unsigned short	d_reclen;	Длина этой записи
		unsigned char	d_type;		Тип файла: не поддерживается
		                            всеми типами файловых систем (?)
		char			d_name		Нуль-терминированное название файл 
	 }*/
	 while ((de = readdir(dr)))
	 	printf("%s\n", de->d_name);
	 closedir(dr);
	 return (0);
}
