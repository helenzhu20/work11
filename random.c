#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int r = open(/dev/urandom, O_RDONLY);
    char ra[10];
    if (r < 0) {
        printf("error, read in no bytes");
    } else {
        read(r, ra, sizeof(ra));
    }
    close(r);

    print("random 0: %d", ra[0]);
    print("random 1: %d", ra[1]);
    print("random 2: %d", ra[2]);
    print("random 3: %d", ra[3]);
    print("random 4: %d", ra[4]);
    print("random 5: %d", ra[5]);
    print("random 6: %d", ra[6]);
    print("random 7: %d", ra[7]);
    print("random 8: %d", ra[8]);
    print("random 9: %d", ra[9]);
}
}