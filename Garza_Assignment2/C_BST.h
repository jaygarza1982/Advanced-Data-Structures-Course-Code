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
        void p_deleteNode(S_NODE *node);
        S_NODE *p_rotateLeft(S_NODE *node);
        S_NODE *p_rotateRight(S_NODE *node);
        S_NODE *p_createVine(S_NODE *node);
        S_NODE *p_initialRotations(S_NODE *node, int count);

    public:
        C_BST();
        S_NODE *insertValue(int data, S_NODE *node);
        void insertValue(int data);
        S_NODE *findNode(S_NODE *node, int data);
        int getHeight();
        void printTree();
        void sortTree();
        void deleteTree();
        ~C_BST();
};
