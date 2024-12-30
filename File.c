#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd[2];
    char buf1[25] = "just a test\n";
    char buf2[50];

    // Open file1 and file2 for read-write access, create if they don't exist
    fd[0] = open("file1", O_RDWR | O_CREAT, 0666);
    fd[1] = open("file2", O_RDWR | O_CREAT, 0666);

    // Check if files were opened successfully
    if (fd[0] < 0 || fd[1] < 0) {
        perror("Failed to open files");
        return 1;
    }

    // Write buf1 to file1
    write(fd[0], buf1, strlen(buf1));

    printf("\nEnter the text now… ");
    fgets(buf1, sizeof(buf1), stdin);

    // Write user input (buf1) to file1
    write(fd[0], buf1, strlen(buf1));

    // Move cursor to the beginning of file1
    lseek(fd[0], 0, SEEK_SET);

    // Read from file1 into buf2
    read(fd[0], buf2, sizeof(buf2));

    // Write buf2 to file2
    write(fd[1], buf2, strlen(buf2));

    // Close file descriptors
    close(fd[0]);
    close(fd[1]);

    printf("\n");

    return 0;
}