#ifndef Mytree_h
#define Mytree_h
#include <iostream>
#include "treenode.h"
using namespace std;
template <class T>
class Mytree{
private:
    NodeTree<T> *root;
public:
    Mytree(){
        root = NULL;
    }
    // ham kiem tra cay rong
    bool IsEmpty()const{
        return root == NULL;
    }
    // ham tra ve mot node trong cay
    // NodeTree<T> * Search(NodeTree<T> *p, T val){
    //     if (p == NULL){
    //         return NULL;
    //     }
    //     else if(p ->data == val) {
    //         return p;
    //     }
    //     else{
    //         for(int i = 0; i< p->child.size(); i++){
    //             NodeTree<T> *temp = p ->child[i];
    //             if(temp ->data == val){
    //                 return temp;
    //             } 
    //         }
    //     }
    //     return NULL;
    // }
    NodeTree<T> *Search(NodeTree<T> *p, T val) {
        if (p == NULL) {
            return NULL;
        }
        if (p->data == val) {
            return p;
        }
        for (int i = 0; i< p->child.size(); i++) {
            NodeTree<T> *temp = p ->child[i];
            NodeTree<T> *result = Search(temp, val);
            return result;
        }
        return NULL;
    }

    NodeTree<T> *Search(T val){
        return Search(root, val);
    }
    // ham Them mot node
    void AddNode(T parent , T val){
        if(Search(parent) == NULL){
            cout<<"Node cha khong ton tai !"<<endl;
            return;
        }
        NodeTree<T> *p = Search(parent);
        NodeTree<T> *temp = new NodeTree<T>();
        temp ->data = val;
        p ->child.push_back(temp);
    }
    void AddRoot(T value){
        NodeTree<T> *NewNode = new NodeTree<T>();
        NewNode ->data = value;
        if(root == NULL){
            root = NewNode;
        }
        else{
            root ->data = value;
        }
    }
    // ham in ra cac node trong cay khi duyet theo thu tu nao do
    void PrintAll(NodeTree<T> *p)const{
        if(p == NULL){
            return;
        }
        else{
            for(int i = 0; i < p->child.size(); i++){
                NodeTree<T> *temp = p ->child[i];
                cout << temp ->data <<" ";
                PrintAll(temp);
            }
        }
    }
    void PrintAll()const{
        cout<<root->data<<" ";
        PrintAll(root);
    }
    // ham tinh so node cua cay
    int CountNode(NodeTree<T> *p)const{
        int dem = 0;
        if (p == NULL){
            return dem;
        }
        else{
            for(int i = 0; i < p->child.size(); i++){
                dem += CountNode(p->child[i]);
            }
            dem ++;
        }
        return dem;
    }
    int CountNode()const{
        return CountNode(root);
    }
    // hàm tính số lá của cây
    int CountLeaves(NodeTree<T> *p)const{
        int dem = 0;
        if (p == NULL){
            return dem;
        }
        else{
            if(p->child.size()== 0){
                return 1;
            }
            for(int i = 0; i < p->child.size(); i++){
                dem += CountLeaves(p->child[i]);
            }
        }
        return dem;
    }
    int CountLeaves()const{
        return CountLeaves(root);
    }
    // hàm tính số node nội của cây
    int CountInNode(NodeTree<T> *p)const{
        int dem = 0;
        if (p == NULL){
            return dem;
        }
        dem = CountNode(p) - CountLeaves(p);
        return dem;
    }
    int CountInNode()const{
        return CountInNode(root);
    }
    // hàm xóa cây , trả về cây rỗng
    void Clear(NodeTree<T> *p){
        if(p==NULL) return;
        else{
            for(int i=0;i<p->child.size();i++){
                Clear(p->child[i]);
            }
            delete p;
        }
    }
    void Clear(){
        Clear(root);
    }
    // Hàm tạo sao chép, toán tử gán
    NodeTree<T> *Copy(NodeTree<T> *p){
        if (p == NULL) return NULL;
        NodeTree<T> *NewNode = new NodeTree<T>;
        NewNode ->data = p ->data;
        for(int i = 0; i < p->child.size(); i++){
            NewNode ->child.push_back(Copy(p->child[i]))
        }
        return NewNode;
    }
    Mytree<T> &operator=(const Mytree<T> &other){
        if (this != other){
            Clear(root);
        }
        root = Copy(other.root);
        return *this;
    }
    // Hàm tính chiều cao của một nút
    int Height(NodeTree<T> *node) const {
        if (node == nullptr) {
            return -1; // Trường hợp cơ sở: nút không tồn tại, trả về -1
        } else {
            int maxChildHeight = -1; // Chiều cao lớn nhất của các nút con
            for (int i = 0; i < node->child.size(); ++i) {
                int childHeight = Height(node->child[i]);
                if (childHeight > maxChildHeight) {
                    maxChildHeight = childHeight;
                }
            }
            return maxChildHeight + 1; // Chiều cao của nút là chiều cao lớn nhất của các nút con + 1
        }
    }

    // Hàm tính chiều cao của cây
    int TreeHeight() const {
        return Height(root);
    }
};
#endif