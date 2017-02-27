#include<vector>

class BSTree{
    private:
        class Node{
            public:
                int data;
                Node * left;
                Node * right;
                Node * parent;
                Node(int val);
        };
                
        bool insertHelper(Node * n, int val);
                
        Node * findHelper(Node * n, int val);
        
        void preOrder(Node * n);
       
        void inOrder(Node * n,std::vector<int> &list);
      
        void postOrder(Node * n);
        
        void leaf(Node * n);
        
        void shortCircuit(Node * n);
        
        void promotion(Node * n);
        
        Node * findMin(Node * n);

    public:
        Node * root;
        
        BSTree();
        
        bool empty();
        
        bool insert(int val);

        
        bool find(int val);
        
        BSTree(const BSTree&old_tree);
        
        ~BSTree();
        
        void sortedArray(std::vector<int> &list);
        
        bool remove(int num);
};