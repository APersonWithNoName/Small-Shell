#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "./shell.h"

#define MAX_HOST_NAME_LEN 256
#define MAX_USER_NAME_LEN 256
#define MAX_DIR_NAME_LEN 1024
#define MAX_PORMPT_LEN 2048

char* prompt() {
    static char PROMPT[MAX_PORMPT_LEN];
    struct passwd *PWD = getpwuid(getuid());
    char HOST_NAME[MAX_HOST_NAME_LEN];
    char USER_NAME[MAX_USER_NAME_LEN];
    char DIR_NAME[MAX_DIR_NAME_LEN];
    char user_str;
    char prompt_end[MAX_DIR_NAME_LEN];
    getcwd(DIR_NAME, MAX_DIR_NAME_LEN);
    
    if(PWD == NULL || \
       gethostname(HOST_NAME,MAX_HOST_NAME_LEN)==-1 || \
       getcwd(DIR_NAME,256)==NULL) {
        strcpy(PROMPT, "Small-Shell>> ");
        fflush(stdout);
        return PROMPT;
    } else {
        if(getuid() == 0) {
            user_str = '#';
        } else {
            user_str = '$';
        }
        /*if(gethostname(HOST_NAME, MAX_HOST_NAME_LEN) == 0) {
            sprintf(PROMPT, "[Small-Shell] %s@%s:%s%c", PWD -> pw_name, HOST_NAME, DIR_NAME, user_str);
            return PROMPT;
        } else {
            sprintf(PROMPT, "[Small-Shell] %s@Unknown:%s%c", PWD -> pw_name, DIR_NAME, user_str);
            return PROMPT;
        }*/
        sprintf(PROMPT, "[Small-Shell] %s@%s:%s%c", PWD -> pw_name, HOST_NAME, DIR_NAME, user_str);
        return PROMPT;
        /*if(strncmp(PROMPT, PWD -> pw_dir, strlen(PWD -> pw_dir)) != 0) {
            sprintf(prompt_end, "%s%c", DIR_NAME, user_str);
            strcat(PROMPT, prompt_end);
            return PROMPT;
        } else {
            sprintf(prompt_end, "~/%s%c", DIR_NAME, user_str);
        }*/
    }
    
}

int main() {
    printf(prompt());
    return 0;
}