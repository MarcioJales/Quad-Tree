#ifndef TREENODE_HPP
#define TREENODE_HPP

#define BLACK 0
#define WHITE 1
#define NODEF -1

class TreeNode
{

private:

  int color;
  TreeNode * children;
  
public:
  
  TreeNode(){}

  ~TreeNode(){}

  TreeNode(int color);

  TreeNode(TreeNode firstLeft, TreeNode secondLeft, TreeNode secondRight, TreeNode firstRight);

  int getColor();
  
  TreeNode * getChild(int index);

  int childrenNumber();

  bool isLeaf();

  string treeLabels();

  string quadTreeEncoding();
  
};

#endif
