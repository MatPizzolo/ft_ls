#ifndef LS_H
# define LS_H

# include "./libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

#define FLAG_L 1 //-l
#define FLAG_R 2 //-R
#define FLAG_A 3 //-a
#define FLAG_R_REV 4 //-r
#define FLAG_T 5 //-t

// Directory Entry
// structure used to store information about a file or directory within a directory.
// typedef struct dirent {
// 	ino_t 			d_ino;		/* inode number */
// 	off_t 			d_off;		/* offset to the next dirent */
// 	unsigned short	d_reclen;	/* length of this record */
// 	unsigned char	d_type;		/* type of file */
// 	char			d_name[256];/* filename */
// } dirent;

typedef struct s_dir_info {
	char *dir_path;			// Directory path
	struct dirent **files;	// Array of pointers to dirent structs
} t_dir_info;

typedef struct s_main {
	t_dir_info		*dirs; // Array of directory information structs
	int				nbr_dirs;
	int 			flag;
} t_main;


/* Arg Checker */
t_main *init_check_args(int argc, char **argv);

/* Handler */
void ft_ls(t_main *main);

/* Display */
void print_dir_info(t_main *main);

#endif