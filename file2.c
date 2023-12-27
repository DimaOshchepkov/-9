#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h> // Добавленный заголовочный файл для umask()
#include <unistd.h> 

int main()
{
    int fd;
    size_t size;
    char string[100];
    /* Обнуляем маску создания файлов текущего процесса для
     того,
    чтобы права доступа у создаваемого файла точно 
    соответствовали параметру вызова open() */
    (void)umask(0);
    /* Попытаемся открыть файл с именем myfile в 
    текущей директории только для операций вывода.
     Если файла не существует, попробуем его создать
      с правами доступа 0666, т. е. read-write для всех
       категорий пользователей */
    if ((fd = open("myfile", O_RDONLY)) < 0)
    {
        /* Если файл открыть не удалось, печатаем об этом
         сообщение и прекращаем работу */
        printf("Can\'t open file\n");
        exit(-1);
    }
    
    while ((size = read(fd, string, 1)) != 0) {
        printf(string);
    }
    /* Закрываем файл */
    if (close(fd) < 0)
    {
        printf("Can\'t close file\n");
    }
    return 0;
}
