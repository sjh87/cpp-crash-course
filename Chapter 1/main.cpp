#include <cstdio>

int sum(int x, int y) {
    return x + y;
}

int main(void) {
    int x = -9;
    int y = 9;

    if (EOF == printf("The sum of %d and %d is %d", x, y, sum(x, y))) {
        return 1;
    }

    return 0;
}
