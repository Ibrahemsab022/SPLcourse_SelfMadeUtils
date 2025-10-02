#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int cp_main(int argc, char *argv[]) {
    if (argc != 3) {
        write(2, "Usage: cp <source> <destination>\n", 33);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        write(2, "Error: cannot open source file\n", 31);
        return 1;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        write(2, "Error: cannot open/create destination file\n", 43);
        close(src_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, bytes);
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}
