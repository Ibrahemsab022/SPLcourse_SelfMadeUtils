#include <unistd.h>

int mv_main(int argc, char *argv[]) {
    if (argc != 3) {
        write(2, "Usage: mv <source> <destination>\n", 33);
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0) {
        write(2, "Error: move failed\n", 19);
        return 1;
    }

    return 0;
}
