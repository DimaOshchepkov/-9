#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("My pid = %d\n", (int)getpid());
    printf("My ppid = %d\n", (int)getppid());
    
    uid_t user_id = getuid(); // Получаем UID пользователя
    gid_t group_id = getgid(); // Получаем GID группы
    
    printf("User ID: %d\n", user_id);
    printf("Group ID: %d\n", group_id);
}