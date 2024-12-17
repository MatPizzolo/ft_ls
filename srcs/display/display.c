#include "../ls.h"

void print_dir_info(t_main *main) {
    int i, j;

	printf("Flags: %i: ", main->nbr_flags);
    for (i = 0; i < main->nbr_flags; i++) {
		printf("%i,", main->flags[i]);
	}
	printf("\n");

    for (i = 0; i < main->nbr_dirs; i++) {
        printf("Directory: %s\n", main->dirs[i].dir_path);
        for (j = 0; main->dirs[i].files[j]; j++) {
            if (main->flags[0] == FLAG_L) {
                // Implement -l flag logic here (e.g., get file stats, print details)
                printf("  -l %s\n", main->dirs[i].files[j]->d_name); 
            } else {
                printf("  %s\n", main->dirs[i].files[j]->d_name);
            }
        }
        printf("\n");
    }
}

// void print_wmany_flags(t_main *main) {

// }

void print_wone_flag(t_main *main){
    
}

void print_none_flag(t_main *main) {
    int i, j;

    if (main->nbr_dirs < 2) {
        for (j = 0; main->dirs[0].files[j]; j++)
            printf("%s\t", main->dirs[0].files[j]->d_name);
    } else {
        for (i = 0; i < main->nbr_dirs; i++) {
            printf("%s:\n", main->dirs[i].dir_path);
            for (j = 0; main->dirs[i].files[j]; j++)
                printf("%s\t", main->dirs[i].files[j]->d_name);
            printf("\n\n");
        }
    }
}

void display_info(t_main *main) {
    if (main->nbr_flags == 0)
        print_none_flag(main);
    else if (main->nbr_flags == 1)
        print_wone_flag(main);
    // else
    //     print_wmany_flags(main);
}
