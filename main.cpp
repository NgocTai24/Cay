#include <iostream>
#include "Mytree.h"
using namespace std;
int main(){
    Mytree<int> ds;
    ds.AddRoot(2);
    ds.AddNode(2,4);
    ds.AddNode(4,5);
    ds.AddNode(2,8);
    ds.AddNode(4,7);
    //ds.PrintAll();
    //cout<<ds.CountNode();
    //cout<<ds.CountLeaves();
    //cout<<ds.CountInNode();
    //ds.Clear();
    ds.PrintAll();
    return 0;
}