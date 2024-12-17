#include "../ls.h"

int char_type(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 0;
    if (c >= '0' && c <= '9')
        return 1;
    return 2;
}

int custom_strcmp(const char *s1, const char *s2) {
    size_t i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return 0;
}

void sort_default(struct dirent **files, int count) {
    struct dirent *temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (custom_strcmp(files[j]->d_name, files[j + 1]->d_name) > 0) {
                temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void sort_files(t_main *main) {
    for (int i = 0; i < main->nbr_dirs; i++) {
        if (main->dirs[i].files && main->dirs[i].nbr_files > 1) {
            sort_default(main->dirs[i].files, main->dirs[i].nbr_files);
        }
    }
}