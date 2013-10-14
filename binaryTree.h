#ifndef BINARYTREE_H
#define BINARYTREE_H

class Tree
{
    struct TreeNode
    {
        int data;
        TreeNode *left; // указатель на левое поддерево
        TreeNode *right;
        TreeNode(int dt)
        {
            data = dt;
            left= right= 0;
        }

    }*root;

public:
    Tree();
    ~Tree();
    Tree (const Tree &); // конструктор копирования
    Tree &operator=(const Tree&);
    Tree operator+(const Tree&);
    void operator+=(const Tree&);
    Tree operator*(const Tree &);
    Tree operator-(const Tree &);

    void insertNode(int); // вставка элемента
    bool findElement(int); // поиск на наличие элемента
    void clearTreeNode();
    void outputTree(int); // вывод на экран дерево поиска

private:

     // вспомогательные функции
    void insertNode(TreeNode*& ,int); // добавить узел в дерево
    bool findElement(TreeNode* ,int);
    void clearTreeNode(TreeNode*&);
    void copyTreeNode(TreeNode*& , TreeNode*);
    void outputTree(TreeNode* ,int);

    void uniteTrees(TreeNode* , TreeNode*);
    Tree intersectTrees(Tree &,TreeNode *);
    Tree differenceTrees(Tree &,TreeNode *, TreeNode *);
};




#endif

