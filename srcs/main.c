#include "../ls.h"

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
	free(main->flags);
	free(main);
}

int main (int argc, char **argv){
	t_main *main;

	main = init_check_args(argc, argv);
	
	ft_ls(main);

	sort_files(main);

	display_info(main);

	free_main(main);
	return 0;
}