#ifndef treenode_h
#define treenode_h
#include <iostream>
#include <vector>
using namespace std;
template <class T>
struct NodeTree
{
    T data;
    NodeTree<T> *parent;
    vector< NodeTree<T> *> child;

};
#endif