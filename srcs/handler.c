#include "../ls.h"

int count_files(DIR *dir) {
    int count = 0;
    struct dirent *entry;

    while ((entry = readdir(dir))) {
        if (ft_strncmp(entry->d_name, ".", 1) && ft_strncmp(entry->d_name, "..", 2))
            count++;
    }
    rewinddir(dir);
    return count;
}

void ft_ls(t_main *main) {
    DIR *dir;
    struct dirent *entry;
    int count;
    char *each_dir;

    for (int i = 0; i < main->nbr_dirs; i++) {
        each_dir = ft_strdup(main->dirs[i].dir_path);
        dir = opendir(each_dir);
        free(each_dir);
        if (!dir) {
            perror("opendir");
            return;
        }

        count = count_files(dir);
        main->dirs[i].files = malloc(sizeof(struct dirent *) * (count + 1)); // Allocate space for pointers
        if (!main->dirs[i].files) {
            perror("malloc");
            closedir(dir);
            return;
        }

        int j = 0;
        while ((entry = (struct dirent *)readdir(dir))) {
            if (ft_strncmp(entry->d_name, ".", 1) && ft_strncmp(entry->d_name, "..", 2)) {
                main->dirs[i].files[j] = malloc(sizeof(struct dirent)); // Allocate space for each dirent
                if (!main->dirs[i].files[j]) {
                    perror("malloc");
                    closedir(dir);
                    return;
                }
                ft_memcpy(main->dirs[i].files[j], entry, sizeof(struct dirent));
                j++;
            }
        }
        main->dirs[i].files[j] = NULL;
        main->dirs[i].nbr_files = j - 1;
    }
    closedir(dir);
}