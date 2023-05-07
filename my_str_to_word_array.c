
#include "my.hpp"

unsigned int how_many_c_in_str(char* str, char c)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            count++;
    return count;
}

//no malloc to gain time
char** my_str_to_word_array(char* str, char delimiter)
{
    if (!str)
        return NULL;
    unsigned int nb_delim = how_many_c_in_str(str, ':');
    char** array = malloc(sizeof(char*) * (nb_delim + 2));
    if (!array)
        return NULL;
    int a = -1;
    array[++a] = str;
    for (int s = 0; str[s]; s++) {
        if (str[s] == delimiter && str[s + 1]) {
            array[++a] = str + s + 1;
        }
        if (str[s] == delimiter) {
            str[s] = '\0';
        }
    }
    array[++a] = NULL;
    return array;
}
