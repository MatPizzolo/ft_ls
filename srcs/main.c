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

void free_main(t_main *main) {
	int i, j;

	if (!main)
		return;

	for (i = 0; i < main->nbr_dirs; i++) {
		if (main->dirs[i].files) {
			for (j = 0; main->dirs[i].files[j]; j++) {
				free(main->dirs[i].files[j]);
			}
			free(main->dirs[i].files);
		}
	}

	free(main->dirs);
	free(main);
}

int main (int argc, char **argv){
	t_main *main;

	main = init_check_args(argc, argv);
	
	ft_ls(main);

	print_dir_info(main);

	free_main(main);
	return 0;
}