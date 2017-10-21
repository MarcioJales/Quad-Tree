#include <iostream>
#include <string>
#include <png++/png.hpp>

using namespace std;
using namespace png;

#include "BinaryImage.hpp"
#include "TreeNode.hpp"

static TreeNode getTreeFromImage(int x, int y, int size, BinaryImage im)
{
  int color = im.whichColor(x, y, size);
  if(color != NODEF) {
    TreeNode leaf(color);
    return leaf;
  }
  else {
    /* LIC = Left Inferior Corner; RIC = Right // //; LSC = Left Superior Corner; RSC = Right // // */
    TreeNode LIC = getTreeFromImage(x, y, size/2, im);
    TreeNode RIC = getTreeFromImage(x+(size/2), y, size/2, im);
    TreeNode LSC = getTreeFromImage(x, y+(size/2), size/2, im);
    TreeNode RSC = getTreeFromImage(x+(size/2), y+(size/2), size/2, im);
    TreeNode inner(LIC, RIC, LSC, RSC);
    return inner;
  }
};

static void printResult(TreeNode qt, BinaryImage im)
{
  cout << "Original size: " << im.getSize()*im.getSize() << " bits" << endl;
  cout << "Compressed size: " << qt.treeLabels().size() + qt.quadTreeEncoding().size() << " bits" << endl;
}

int main(int argc, char **argv)
{
  string picture_name[] = {"Mondrian01.png", "Mondrian02.png", "Example256.png", "Pollock01.png", "Pollock02.png"};

  for(string &pic : picture_name)
  {
    BinaryImage png_picture(pic);
    TreeNode quad_tree;
    int x_init = 0, y_init = 0;

    quad_tree = getTreeFromImage(x_init, y_init, png_picture.getSize(), png_picture);
    printResult(quad_tree, png_picture);
    cout << endl;
  }

  return 0;
}
