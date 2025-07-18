#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(){
    char *args[101];
    args[0] = "./input";
    for (int i = 1; i < 100; i++){
        args[i] = "";
    }
    args['B'] = "\x20\x0a\x0d";
    args['C'] = "11111";
    args[100] = NULL;
    dup2(0, 2);
    setenv("\xde\xad\xbe\xef", "\xca\xfe\xba\xbe", 0);
    FILE *file = fopen("\x0a", "w");
    fwrite("\x00\x00\x00\x00", 4, 1, file);
    fclose(file);
    execv("/home/input2/input", args);
    return 0;
}
