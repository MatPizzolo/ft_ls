#include "../ls.h"

void print_dir_info(t_main *main) {
    int i, j;
    for (i = 0; i < main->nbr_dirs; i++) {
        printf("Directory: %s\n", main->dirs[i].dir_path);
        for (j = 0; main->dirs[i].files[j]; j++) {
            if (main->flag == FLAG_L) {
                // Implement -l flag logic here (e.g., get file stats, print details)
                printf("  -l %s\n", main->dirs[i].files[j]->d_name); 
            } else {
                printf("  %s\n", main->dirs[i].files[j]->d_name);
            }
        }
        printf("\n");
    }
}