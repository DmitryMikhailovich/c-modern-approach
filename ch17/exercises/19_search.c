#include <stdio.h>
#include <stdlib.h>

void execute_function(char *name);
void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] = 
{{"new", new_cmd},
 {"open", open_cmd},
 {"close", close_cmd},
 {"close all", close_all_cmd},
 {"save", save_cmd},
 {"save as", save_as_cmd},
 {"save all", save_all_cmd},
 {"print", print_cmd},
 {"exit", exit_cmd}
};


int main(void) {

    return 0;
}


void execute_function(char *name) {
    for(int i = 0; i < sizeof(file_cmd)/sizeof(file_cmd[0]); i++) {
        if(name == file_cmd[i].cmd_name)
            file_cmd[i].cmd_pointer();
    }
}
void new_cmd(void){}
void open_cmd(void){}
void close_cmd(void){}
void close_all_cmd(void){}
void save_cmd(void){}
void save_as_cmd(void){}
void save_all_cmd(void){}
void print_cmd(void){}
void exit_cmd(void){}
