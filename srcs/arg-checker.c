#include "../ls.h"

int check_flag(char* str) {
	if (ft_strncmp(str, "-l", 2) == 0)
		return FLAG_L; 
	else if (ft_strncmp(str, "-R", 2) == 0)
		return FLAG_R; 
	else if (ft_strncmp(str, "-a", 2) == 0)
		return FLAG_A; 
	else if (ft_strncmp(str, "-r", 2) == 0)
		return FLAG_R_REV; 
	else if (ft_strncmp(str, "-t", 2) == 0)
		return FLAG_T; 
	else
		return 0;
}

void check_dir_args(t_main *main, int argc, char **argv, int start_index) {
	int i;

	main->nbr_dirs = argc - start_index;
	main->dirs = malloc(sizeof(t_dir_info) * main->nbr_dirs);
	if (!main->dirs)
		return;

	for (i = 0; i < main->nbr_dirs; i++) {
		main->dirs[i].dir_path = argv[start_index + i];
	}
}

t_main *init_check_args(int argc, char **argv) {
	t_main *main;
	int isFlag;

	main = malloc(sizeof(t_main));
	if (!main)
		return NULL;


	if (argc == 3) {
		isFlag = check_flag(argv[1]);
		if (isFlag > 0) {
			main->flag = isFlag;
			check_dir_args(main, argc, argv, 2);
		} else {
			main->flag = 0;
			check_dir_args(main, argc, argv, 1);
		}
	} else if (argc == 1) {
		main->flag = 0;
		main->nbr_dirs = 1;
		main->dirs = malloc(sizeof(t_dir_info));
		if (!main->dirs)
			return NULL;
		main->dirs[0].dir_path = ".";
	} else {
		main->flag = 0;
		check_dir_args(main, argc, argv, 1); 
	}


	return main;
}