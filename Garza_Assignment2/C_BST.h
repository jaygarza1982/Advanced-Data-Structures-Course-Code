struct S_NODE
{
    int data;
    S_NODE *left;
    S_NODE *right;
};

class C_BST
{
    private:
        S_NODE *root;
        
    public:
        C_BST();
        S_NODE *insertValue(int data, S_NODE *node);
        S_NODE *findNode(S_NODE *node, int data);
        ~C_BST();
};
