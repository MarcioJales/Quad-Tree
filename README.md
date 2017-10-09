# Quad-Tree

A program to compress a binary image (same width and height. PNG format) using Quad-Tree technique.

STILL INCOMPLETE, BUT ALREADY FUNCTIONAL.


## Compiling
```
$ g++ -c --std=c++11 QuadTreeCompression.cpp BinaryImage.cpp TreeNode.cpp `libpng-config --cflags`
$ g++ -o QuadTreeCompression QuadTreeCompression.o BinaryImage.o TreeNode.o `libpng-config --ldflags`
```

The **png++**, a C++ wrapper for libpng, is needed: http://www.nongnu.org/pngpp/
