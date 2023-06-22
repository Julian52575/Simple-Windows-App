#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

bool read_in_individual_file(char name[256])
{
    char* line = NULL;
    size_t len = 0;
    long nread = 0;
    FILE* nameoffile = NULL;
    char* path = name;////////

    if (!path)
        return false;
    nameoffile = fopen_s(1, path, "r");
    if (nameoffile == NULL) {
        free(path);
        return false;
    }
    free(path);
    return true;
}

//open a folder
bool read_folder(char *file)
{
    DIR* my_dir = opendir("pokecfg/");
    struct dirent* info;

    if (!my_dir) {
        return false;
    }
    do {
        info = readdir(my_dir);
        if (!info) {
            return true;
        }
        if (read_in_individual_file("lol\n") == false) {
            return false;
        }
    } while (info != NULL);
}
