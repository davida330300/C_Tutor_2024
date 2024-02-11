#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "unistd.h"

int main() {
    int fd = open("./text.txt", O_RDONLY);  // Open file in read-only mode

    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    // Assuming a reasonable buffer size for reading
    char buffer[4096];
    ssize_t bytesRead;

    // Read and print the file content
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Print the read data
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        perror("Error reading the file");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}
