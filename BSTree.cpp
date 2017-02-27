#include "BSTree.h"
#include<iostream>
#include<vector>
#ifndef BSTREE_H
#define BSTREE_H

using namespace std;

    BSTree::Node::Node(int val){
        this->data=val;
        this->left=0;
        this->right=0;
        this->parent=0;
    }

    BSTree::BSTree(){
        root = 0;
    }
    
    bool BSTree::empty(){
        return (this->root == 0) ;
    }
    
    bool BSTree::insert(int val){
        return insertHelper(this->root,val);
    }
    
    bool BSTree::insertHelper(Node * n, int val){
        if(n == 0){
            root = new Node(val);
            //cout<<1<<endl;
            return true;
        }
        else if(val < n->data){
            if(n->left == 0){
                n->left = new Node(val);
                n->left->parent = n;
                //cout<<12<<endl;
                return true;
            } 
            else return insertHelper(n->left, val);
        }
        else if(val > n->data){
            if(n->right == 0){
                n->right = new Node(val);
                n->right->parent = n;
                //cout<<123<<endl;
                return true;
            } 
            else return insertHelper(n->right, val);
        }
        else return false; //val==0
    }
    
    bool BSTree::find(int val){
        if(0 == findHelper(root,val)) return false;
        else return true;
    }
    
    BSTree::Node* BSTree::findHelper(Node * n, int val){
        if(n == 0) return n;
        else if(val == n->data) return n;
        else if(val < n->data){
            if(n->left == 0) return n->left;
            else return findHelper(n->left,val);
        } 
        else{
            if(n->right == 0) return n->right;
            else return findHelper(n->right,val);
        } 
    }
    
    void BSTree::preOrder(Node * n){
            if(n == 0) return;
            this->insert(n->data);
            preOrder(n->left);
            preOrder(n->right);
        }
        
    void BSTree::inOrder(Node * n,std::vector<int> &list){
            if(n == 0) return;
            inOrder(n->left,list);
            list.push_back(n->data);
            inOrder(n->right,list);
        }
        
    void BSTree::postOrder(Node * n){
            if(n == 0) return;
            postOrder(n->left);
            postOrder(n->right);
            delete n;
        }
    
    BSTree::BSTree(const BSTree&old_tree){
            preOrder((old_tree.root));
        }
        
    BSTree::~BSTree(){
            postOrder(root);
        }
        
    void BSTree::sortedArray(std::vector<int> &list){
            inOrder(root,list);
        }
        
    bool BSTree::remove(int num){
            Node * node = findHelper(root,num);
            if(node == 0) return false;
            else if(node->left == 0 && node->right == 0) leaf(node);
            else if(node->left == 0 || node->right == 0) shortCircuit(node);
            else promotion(node);
            return true;
        }
        
    void BSTree::leaf(Node * n){
        if(n == root) root = 0;
        else{
            if(n == n->parent->left){ n->parent->left = 0;}
            else{ n->parent->right = 0;}
            delete n;
        }
        
       // cout<<"leaf delete";
        
    }
        
    void BSTree::shortCircuit(Node * n){
        if(n == root){
            Node * temp = root;
            if(root->left != 0){
                root = root->left;
                root->parent = 0;
            }
            else{
                root = root->right;
                root->parent = 0;
            }
            delete temp;
        }
        else{
            if(n->parent->left == n){
                if(n->left!=0){
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                }    
                else{
                    n->parent->left = n->right;
                    n->right->parent = n->parent;
                }
                delete n;
            }    
            else{
                if(n->left!=0){
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                }    
                else{
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                }
                delete n;
            }
        }
        //cout<<"promotion delete";
    }
        
    void BSTree::promotion(Node * n){
                Node * min = findMin(n->left);
                int temp = min->data;
                leaf(min);
                n->data = temp;
    }
    
    BSTree::Node * BSTree::findMin(Node * n){
        if(n->right == 0) return n;
        else return findMin(n->right);
    }
    
    #endif