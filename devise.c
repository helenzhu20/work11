#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int r = open("/dev/urandom", O_RDONLY);
    char ra[100];
    if (r < 0) {
        printf("error, read in no bytes");
    } else {
        read(r, ra, sizeof(ra));
    }
    close(r);

    int i;
    for (i = 0; i < 10; i++) {
        printf("random %d: %d\n", i, ra[i]);
    }
    
    int new = open("output.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(new, ra, sizeof(ra));
    close(new);

    int r2 = open("output.txt", O_RDONLY);
    char ra2[100];
    if (r2 < 0) {
        printf("error, read in no bytes");
    } else {
        read(r2, ra2, sizeof(ra2));
    }
    close(r2);

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("random %d: %d\n", i, ra2[i]);
    }
}