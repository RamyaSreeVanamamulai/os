#include <stdio.h>
#include <stdlib.h>

void right(int a, int b, int c) {
    int sides[3] = {a, b, c};
    int max = 0, max_idx = 0;

    // Find the longest side (hypotenuse)
    for (int i = 0; i < 3; i++) {
        if (sides[i] > max) {
            max = sides[i];
            max_idx = i;
        }
    }

    // Square of hypotenuse
    long hyp_square = (long)max * max;

    // Sum of squares of other two sides
    long sum_squares = 0;
    for (int i = 0; i < 3; i++) {
        if (i != max_idx) {
            sum_squares += (long)sides[i] * sides[i];
        }
    }

    printf("%d %d %d ", a, b, c);
    if (hyp_square == sum_squares) {
        printf("is a right triangle\n");
    } else {
        printf("is not a right triangle\n");
    }
}

#ifdef STAND_ALONE
int main(int argc, char *argv[]) {
    printf("Written by your name\n");

    if (argc != 4) {
        printf("Usage: %s side1 side2 side3\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    right(a, b, c);
    return 0;
}
#endif
