#include "../../ls.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat st;
    struct passwd *pw;
    struct group *gr;

    if (lstat(filename, &st) == -1) {
        perror(filename);
        return;
    }

    // File type
    switch (st.st_mode & S_IFMT) {
        case S_IFREG:  printf("-"); break;
        case S_IFDIR:  printf("d"); break;
        case S_IFCHR:  printf("c"); break;
        case S_IFBLK:  printf("b"); break;
        case S_IFIFO:  printf("p"); break;
        case S_IFLNK:  printf("l"); break;
        case S_IFSOCK: printf("s"); break;
        default:      printf("?"); break;
    }

    // Permissions
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf((st.st_mode & S_IRGRP) ? "r" : "-");
    printf((st.st_mode & S_IWGRP) ? "w" : "-");
    printf((st.st_mode & S_IXGRP) ? "x" : "-");
    printf((st.st_mode & S_IROTH) ? "r" : "-");
    printf((st.st_mode & S_IWOTH) ? "w" : "-");
    printf((st.st_mode & S_IXOTH) ? "x" : "-");

    // Number of links
    printf(" %hu ", st.st_nlink);

    // Owner
    pw = getpwuid(st.st_uid);
    if (pw) {
        printf("%s ", pw->pw_name);
    } else {
        printf("%d ", st.st_uid);
    }

    // Group
    gr = getgrgid(st.st_gid);
    if (gr) {
        printf("%s ", gr->gr_name);
    } else {
        printf("%d ", st.st_gid);
    }

    // Size
    printf("%lld ", st.st_size);

    printf("%s ", ctime(&st.st_mtime));

    // File name
    printf("%s\n", filename);
}