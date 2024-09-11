# bla

> [!WARNING]
> Work in progress, expect bugs and api changes

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
bla -- Basic Linear Algebra library

Copyright (C) 2024  George Watson

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
