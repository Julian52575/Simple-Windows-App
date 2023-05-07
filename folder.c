
#include "my.hpp"

bool read_in_individual_file(char name[256])
{
    char* line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    FILE* nameoffile = NULL;
    char* path = my_str_fuses("pokecfg/", name);

    if (!path)
        return false;
    nameoffile = fopen(path, "r");
    if (nameoffile == NULL) {
        free(path);
        return false;
    }
    while ((nread = getline(&line, &len, nameoffile)) != -1) {
        if (nread >= 9)
            ;//hello
    }
    free(path);
    return true;
}

//read the pokecfg folder and update the poke_list struct
bool read_folder(void)
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