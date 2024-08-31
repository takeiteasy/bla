#define BLA_IMPLEMENTATION
#include "bla.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
    vec2 a = {1, 2};
    size_t _a = sizeof(a);
    size_t _b = sizeof(a[0]);
    printf("%zu\n", _a / _b);
    mat4 b;
    size_t __a = sizeof(b);
//    size_t __b = sizeof(b[0]);
    size_t __c = sizeof(b[0][0]);
    float x[] = swizzle(a, x, y, y, x);
    vec2 y = swizzle(a, x, y);
    mat4 m = mat4_identity();
    bla_print(a);
    for (int i = 0; i < 4; i++)
        printf("%.2f\n", x[i]);
    bla_print(m);
    for (int i = 0; i < 4; i++)
        bla_print(mat4_row(m, i));
    return 0;
}
