#include "binaryTree.h"
#include <iostream>
using namespace std;

Tree::Tree():
    root(0)
{}

Tree::~Tree()
{
    clearTreeNode(root);
}

Tree::Tree (const Tree &original)
{
    if (original.root)
    {
        root=new TreeNode(original.root->data);
        copyTreeNode(root, original.root);
    }
    else root=0;
}

////////////////////////////////////////////////// перегруженные операторы

Tree &Tree::operator=(const Tree &original)
{
    if(this==&original)
        return *this;
    clearTreeNode(root);
    copyTreeNode(root,original.root);
    return *this;
}


Tree Tree::operator+(const Tree &original)
{
    if(this!= &original)
    {
        Tree temp;
        temp=original;
        uniteTrees(root,temp.root); // root это узел переданного tree2, temp.root - узел дерева,
        // полученный при объединении
        return temp;
    }
    else
        return *this;
}

Tree Tree::operator*(const Tree &original)
{
    if(this!= &original)
    {
        Tree temp;
        intersectTrees(temp,original.root);
        return temp;
    }
    else
        return *this;
}

Tree Tree::operator-(const Tree &original)
{
    Tree temp;
    if(!this && original.root)
    {
        clearTreeNode(temp.root);
        *this=temp;
    }
    else  if(this && !original.root)
        return *this;
    if(this!= &original)
    {
        differenceTrees(temp,root,original.root);
        return temp;
    }
    else
        return *this;
}


/////////////////////////////////////////////////////


void Tree::insertNode(int value)
{
    insertNode(root,value);
}

bool Tree::findElement(int value)
{
    if(findElement(root,value)) return true;
    else return false;
}

void Tree::clearTreeNode()
{
    clearTreeNode(root);
}

void Tree::outputTree(int level)
{
    outputTree(root,level);
}
//////////////////////////////////////////// вспомогательные функции (функции - утилиты)

void Tree::insertNode(TreeNode *&ptr,int value)
{
    if (ptr== 0)
        ptr= new TreeNode(value);

    else if (value > ptr->data)
        insertNode(ptr->right,value);

    else if (value < ptr->data)
        insertNode(ptr->left,value);

}

bool Tree::findElement(TreeNode *ptr,int value)
{
    if (!ptr) return false;
    else if (ptr->data==value) return true;
    else if (value<ptr->data) return findElement(ptr->left,value);
    else return findElement(ptr->right, value);
}


void Tree::clearTreeNode(TreeNode *&ptr)
{
    if(ptr)
    {
        clearTreeNode(ptr->left);
        clearTreeNode(ptr->right);
        delete ptr;
        ptr=0;
    }
}

void Tree::copyTreeNode(TreeNode *&newTreeNode, TreeNode *original)
{
    if(original==0)
        newTreeNode = 0;

    if (original) // пока не конец
    {
        newTreeNode= new TreeNode(original->data);
        if(original->left)
            copyTreeNode(newTreeNode->left,original->left);
        else
            newTreeNode->left =0;

        if(original->right)
            copyTreeNode(newTreeNode->right,original->right);
        else
            newTreeNode->right =0;
    }
}

void Tree::uniteTrees(TreeNode *other, TreeNode *result)
{
    if(other->left)
    {
        uniteTrees(other->left, result);
        insertNode(result,other->data);
    }
    else if(other->right)
    {
        uniteTrees(other->right,result);
        insertNode(result,other->data);
    }
}

Tree Tree::intersectTrees(Tree &tree,TreeNode *wer)
{
    if(wer)
    {
        intersectTrees(tree,wer->left);
        if( findElement(root,wer->data))
            insertNode(tree.root, wer->data);
        intersectTrees(tree,wer->right);
    }
    return tree;

}
Tree Tree::differenceTrees(Tree &tree, TreeNode *other,TreeNode *one)
{
    if(other)
    {
        differenceTrees(tree,other->left,one);
        if(!findElement(one,other->data))
            insertNode(tree.root, other->data);
        differenceTrees(tree,other->right,one);
    }
    return tree;
}

void Tree::outputTree(TreeNode *ptr,int level)
{
    if(ptr)
    {
        outputTree(ptr->left,level+1);
        if(level==0)   cout<<"корень ";
        else
            for(int i=0; i<level; i++)
                cout<<"*";
        cout<<ptr->data<<endl;
        outputTree(ptr->right,level+1);
    }

}
