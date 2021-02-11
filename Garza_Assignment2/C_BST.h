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
        int p_getHeight(S_NODE *root);
        void p_formattedPrint(S_NODE *node, int indent);

    public:
        C_BST();
        S_NODE *insertValue(int data, S_NODE *node);
        void insertValue(int data);
        S_NODE *findNode(S_NODE *node, int data);
        int getHeight();
        void printTree();
        ~C_BST();
};
