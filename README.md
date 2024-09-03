# bla

### Basic Linear Algebra library

`bla` is a pure C, single-header, linear algebra library, geared towards game development.

bla has been designed to be similar (as possible) to glsl. Like in glsl, matrix and vector types support operators. So `vec + vec` or `mat * mat` all work. Also included is a `swizzle` macro, that mimics glsl [vector swizzling](https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)).

bla relies on the clang+gcc language extensions to work. Please check if your compiler has support for [Matrix Types](https://clang.llvm.org/docs/LanguageExtensions.html#matrix-types) and [Vectors](https://clang.llvm.org/docs/LanguageExtensions.html#vectors-and-extended-vectors) extensions. For matrices to work you will need to pass the `-fenable-matrix` opt. If you don't want to do that define `BLA_NO_MATRICES` before including.

```c
#define BLA_IMPLEMENTATION // Enables the implementation (only decalre once)
// #define BLA_NO_MATRICES // Disables matrix support
// #define BLA_NO_PRINT // Disables printing functions
// #define BLA_NO_GENERICS // Disable _Generic support (for bla_print)
#include "bla.h"

vec4 v = Vec4(1, 2, 3, 4);
bla_print(v);
> { 1.00 2.00 3.00 4.00 }
vec4 x = Vec4(4, 3, 2, 1);
vec4 y = v + x;
bla_print(y);
> { 5.00 5.00 5.00 5.00 }

// swizzle(vector, ...) translates the args to { ... }
// so you can convert this to either another vector
// or a float array quite easily.
// So for this example, swizzle(v, y, x) -> {v.y, v.x, v.w}
vec3 yxw = swizzle(v, y, x, w);
bla_print(yxw);
> { 2.0 1.0 4.0 }

mat4 mat = mat4_identity();
bla_print(mat);
> | 1.00 0.00 0.00 0.00 |
> | 0.00 1.00 0.00 0.00 |
> | 0.00 0.00 1.00 0.00 |
> | 0.00 0.00 0.00 1.00 |
mat4 o = perspective(...);
mat4 m = mat4_identity() * mat4_translate(Vec3(...));
mat4 p = o * m;
```

## TODO

- [ ] Create some actual tests
- [ ] Basic Makefile
- [ ] Documentation

## Acknowledgements

- Most of the matrix + vector functions, as well as the easing functions were all hand ported from [raymath.h](https://github.com/raysan5/raylib/blob/master/src/raymath.h)
- Swizzle macro is based off the [map-macro](https://github.com/swansontec/map-macro) project (really cool I use this a lot)

## LICENSE
```
The MIT License (MIT)

Copyright (c) 2024 George Watson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
