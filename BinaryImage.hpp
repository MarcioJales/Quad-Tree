#ifndef BINARYIMAGE_HPP
#define BINARYIMAGE_HPP

#ifndef NODEF
#define BLACK   0
#define WHITE   1
#define NODEF  -1
#endif

class BinaryImage
{

private:

  int *raster;
  int width, height;
  FILE *fs;
  image<rgb_pixel> *png_image;

public:

  BinaryImage(){}

  ~BinaryImage(){}

  BinaryImage(int width, int height);

  BinaryImage(string filename);

  bool isBlack(int x, int y);

  int getSize();

  int whichColor(int x, int y, int size);

};

#endif
