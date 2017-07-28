#include <iostream>
#include <cstdlib>

using namespace std;

#include "TreeNode.hpp"

TreeNode::TreeNode(int color) : color(color) {
  children = NULL; 
}

TreeNode::TreeNode(TreeNode firstLeft, TreeNode secondLeft, TreeNode secondRight, TreeNode firstRight)
{
  children = new TreeNode[4]();
  children[0] = firstLeft;
  children[1] = secondLeft;
  children[2] = secondRight;
  children[3] = firstRight;
  color = NODEF;
}

int TreeNode::getColor() {
  return color;
}

TreeNode * TreeNode::getChild(int index)
{
  if (children[index].color == BLACK || children[index].color == WHITE ||
      children[index].color == NODEF )
    return &children[index];
  else
    return NULL;
}

int TreeNode::childrenNumber()
{
  int i = 0;
 
  if(children != NULL) {
    while(this->getChild(i) != NULL)
      i++;
    return i;
  }
  else {
    cout << "No children for this node" << endl;
    return 0;
  }
}

bool TreeNode::isLeaf()
{
  if(color == NODEF) 
    return false;
  else 
    return true;
}

/* Encode the leaf colors.
 * Black = 0. White = 1.
 */
string TreeNode::treeLabels()
{
  string result = "";
  int j = 0;
    
  if (children != NULL)
  {     
    while(j < this->childrenNumber()) {
      result = result + children[j].treeLabels();
      j++;
    }
    return result;
  }
  else 
    return result + to_string(color);
}

/* Traverse the tree in pre-order. 
 * Leafs = 0. Inner node = 1. 
 */
string TreeNode::quadTreeEncoding()
{
  string result = "";
  int j = 0;
    
  if (!(this->isLeaf()))
  {     
    while(j < this->childrenNumber()) {
      result = result + children[j].quadTreeEncoding();
      j++;
    }
    return "1" + result;
  }
  else 
    return result + "0";
}

/*
int main(int argc, char **argv)
{
  TreeNode B(WHITE);
  TreeNode D(BLACK);
  TreeNode E(WHITE);
  TreeNode F(BLACK);
  TreeNode G(WHITE);
  TreeNode H(BLACK);
  TreeNode K(BLACK);
  TreeNode L(WHITE);
  TreeNode M(BLACK);
  TreeNode N(BLACK);
  TreeNode O(BLACK);
  TreeNode P(WHITE);
  TreeNode Q(WHITE);
  TreeNode J(K, L, M, N);
  TreeNode I(J, O, P, Q);
  TreeNode C(D, E, F, G);
  TreeNode A(B, C, H, I);
  cout << "Tree labels: " << A.treeLabels() << endl;
  cout << "DFS encoding: " << A.DFSEncoding() << endl;
}
*/
