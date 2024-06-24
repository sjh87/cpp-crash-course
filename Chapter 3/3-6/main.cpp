#include <cstdio>

size_t writeTo(char* dest, size_t destN, const char source[], size_t sourceN) {
    size_t i = 0;
    for (; i < destN && i < sourceN; i++) {
        dest[i] = source[i];
    }

    return i;
}

size_t readFrom(char* dest, size_t destN, const char source[]) {
    size_t i = 0;
    for (; i < destN; i++) {
        dest[i] = source[i];
    }

    return i;
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper;

    lower[3] = 'd';
    upper_ptr[3] = 'D';

    char letter_d = lower[3];
    char letter_D = upper_ptr[3];

    printf("lower: %s\nupper: %s", lower, upper);

    lower[7] = 'g';
}
