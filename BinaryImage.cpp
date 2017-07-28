#include <iostream>
#include <string>
#include <png++/png.hpp>

using namespace std;
using namespace png;

#include "BinaryImage.hpp"

/* Constructor to build an custom image.
 * This funcionality is not fully implemented yet 
 */
BinaryImage::BinaryImage(int width, int height)
  : width(width), height(height)
{
  raster = new int[width*height];

  for(int i = 0; i < width*height; i++) {
    raster[i] = 0;
  }
}

BinaryImage::BinaryImage(string filename)
{
  cout << "Opening image from file " << filename << "...\n";
  png_image = new image<rgb_pixel>(filename);
  cout << "Done.\n";
    
  width = png_image->get_width();
  height = png_image->get_height();
  cout << "Image width: " << width << endl << "Image height: " << height << endl;
}

bool BinaryImage::isBlack(int x, int y)
{
  if(png_image->get_pixel(x,y).red == 0
     && png_image->get_pixel(x,y).green == 0
     && png_image->get_pixel(x,y).blue == 0)
    return true;

  if(png_image->get_pixel(x,y).red == 255
     && png_image->get_pixel(x,y).green == 255
     && png_image->get_pixel(x,y).blue == 255)
    return false;
}

int BinaryImage::getSize() {
  return png_image->get_width();
}

int BinaryImage::isSameColor(int x, int y, int size)
{
  bool is_black = isBlack(x,y);
    
  for(int i = x; i < x+size; i++) {
    for(int j = y; j < y+size; j++) {
      if(is_black != isBlack(i,j))
	  return NODEF;  
    }
  }
    
  if(is_black)
    return BLACK;
  else
    return WHITE;
}

/*
int main(int argc, char **argv)
{
  string str1 = "Mondrian01.png";
  BinaryImage im(str1); 
  
  return 0;
}
*/
