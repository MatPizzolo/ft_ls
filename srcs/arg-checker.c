#include "../ls.h"

int check_flag(char* str) {
	if (ft_strncmp(str, "l", 1) == 0)
		return FLAG_L; 
	else if (ft_strncmp(str, "R", 1) == 0)
		return FLAG_R; 
	else if (ft_strncmp(str, "a", 1) == 0)
		return FLAG_A; 
	else if (ft_strncmp(str, "r", 1) == 0)
		return FLAG_R_REV; 
	else if (ft_strncmp(str, "t", 1) == 0)
		return FLAG_T; 
	else
		return 0;
}

// Que pasa si me pasan de arg un archivo q empieza con -archivo
void check_flags(char* str, t_main *main) {
	char *flags_str;
	int i;

    if (str[0] == '-') { 
        flags_str = str + 1;
        for (i = 0; flags_str[i] != '\0'; i++) {
            int flag = check_flag(flags_str + i);
            if (flag == 0) {
				printf("ls: invalid option -- ?\n");
				exit(1);
			}
        }
		main->flags = malloc(sizeof(int) * i);
		main->nbr_flags = i;
		for (i = 0; flags_str[i] != '\0'; i++) {
            int flag = check_flag(flags_str + i);
            main->flags[i] = flag;
        }
    }
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

	main = malloc(sizeof(t_main));
	if (!main)
		return NULL;

	if (argc == 3) {
		check_flags(argv[1], main);
		if (main->nbr_flags > 0)
			check_dir_args(main, argc, argv, 2);
		else
			check_dir_args(main, argc, argv, 1);
	} else if (argc == 1) {
		main->flags = malloc(sizeof(int) * 1);
		main->flags[0] = 0;
		main->nbr_flags = 0;
		main->nbr_dirs = 1;
		main->dirs = malloc(sizeof(t_dir_info));
		if (!main->dirs)
			return NULL;
		main->dirs[0].dir_path = ".";
	} else {
		main->flags = malloc(sizeof(int) * 1);
		main->flags[0] = 0;
		main->nbr_flags = 0;
		check_dir_args(main, argc, argv, 1); 
	}


	return main;
}