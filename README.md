# **Ft_ls**

[Subject PDF](en.subject.pdf)  

`ft_ls` is a project that involves recreating the behavior of the Unix `ls` command in C. 


## **Implemented Features**

### **Flags**

- **`-R`**: Recursively lists all subdirectories.
- **`-a`**: Includes hidden files (files starting with `.`).
- **`-r`**: Reverses the sort order.
- **`-t`**: Sorts by the most recently modified time. If two files have the same timestamp, they are sorted lexicographically by name. The `-r` flag reverses both sort orders.
- **`-l`**: Displays files in the **long format**.  
   In long format, the following information is displayed:  
   - File mode (permissions)  
   - Number of links  
   - Owner name  
   - Group name  
   - File size (bytes)  
   - Modification timestamp (month, day, hour, minute)  
   - File/directory name  

   Only nfocusing on the standard permissions (rwx) and ignoring ACL-related symbols or extended attributes

## **Project Structure**

The project follows a structured directory layout:

```plaintext
ft_ls/
├── Makefile            # Build system
├── srcs/               # Source code directory
│   ├── main.c          # Entry point of the program
│   ├── ft_ls.c         # Core logic for handling flags and file listings
│   ├── utils.c         # Utility functions for sorting, formatting, etc.
│   ├── display.c       # Logic for printing file information
│   └── recursive.c     # Recursive logic for handling -R flag
├── libft/              # Custom C library (if needed)
│   ├── libft.a         # Static library
│   └── (additional helper functions)
├── ft_ls.h         	# Project header file
└── en.subject.pdf      # Project subject file
```


## **How to Compile**

To build the project, use the provided `Makefile`:

```bash
make
```

This will generate the executable `ft_ls` in the project root directory.

## **Usage**

### **Basic Usage**

Run `ft_ls` with or without flags:

```bash
./ft_ls [options] [directory]
```

- If no flags are specified, `ft_ls` behaves like the basic `ls` command.  
- If no directory is provided, the current working directory is listed.

### **Examples**

- List all files in the current directory (default behavior):  
   ```bash
   ./ft_ls
   ```

- List files in long format:  
   ```bash
   ./ft_ls -l
   ```

- Include hidden files:  
   ```bash
   ./ft_ls -a
   ```

- Sort by modification time and reverse the order:  
   ```bash
   ./ft_ls -tr
   ```

- Recursively list all subdirectories:  
   ```bash
   ./ft_ls -R
   ```

- Combine flags:  
   ```bash
   ./ft_ls -laR
   ```

## **Allowed Functions**

The following standard C library functions are permitted in this project:

- `write`  
- `opendir`  
- `readdir`  
- `closedir`  
- `stat`  
- `lstat`  
- `getpwuid`  
- `getgrgid`  
- `listxattr`  
- `getxattr`  
- `time`  
- `ctime`  
- `readlink`  
- `malloc`  
- `free`  
- `perror`  
- `strerror`  
- `exit`  
