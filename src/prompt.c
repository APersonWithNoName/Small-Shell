#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_HOST_NAME_LEN 256
#define MAX_USER_NAME_LEN 256
#define MAX_PATH_NAME_LEN 1024
#define MAX_PORMPT_LEN 2048

char* prompt() {
    static char FORMPT[MAX_PORMPT_LEN];
    struct passwd *PWD;
    char HOST_NAME[MAX_HOST_NAME_LEN];
    char USER_NAME[MAX_USER_NAME_LEN];
    char PATH_NAME[MAX_PATH_NAME_LEN];
    PWD = getpwuid(getuid());
    getcwd(PATH_NAME, MAX_PATH_NAME_LEN);
    if(gethostname(HOST_NAME, MAX_HOST_NAME_LEN) == 0) {
        sprintf(FORMPT, "[Small-Shell] %s@%s:%s", PWD -> pw_name, HOST_NAME, PATH_NAME);
    } else {
        sprintf(FORMPT, "[Small-Shell] %s@Unknown:%s", PWD -> pw_name, PATH_NAME);
    }
    /*if(getuid() == 0) {
        sprintf(FORMPT, "#");
    } else {
        sprintf(FORMPT, "#");
    }*/
    return FORMPT;
}

int main() {
    printf(prompt());
    return 0;
}