#define BLA_IMPLEMENTATION
#include "bla.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
    vec2 a = {1, 2};
    size_t _a = sizeof(a);
    size_t _b = sizeof(a[0]);
    printf("%zu", _a / _b);
    mat4 b;
    size_t __a = sizeof(b);
//    size_t __b = sizeof(b[0]);
    size_t __c = sizeof(b[0][0]);
    float x[] = swizzle(a, x, y);
    return 0;
}
