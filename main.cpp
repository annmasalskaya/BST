#include <iostream>
#include "binaryTree.h"
#include <fstream>
using namespace std;

int main()
{
    Tree tree1;
    ifstream fin("input");
    short value;
    fin>>value;
    while(!fin.eof())
    {
        tree1.insertNode(value) ;
        fin>>value;
    }
    cout<<"The tree 1 : "<<endl;
    tree1.outputTree(0);
    cout<<endl<<endl;
    cout<<"The tree 2 : "<<endl;
    Tree tree2;
    for( int i=3; i<7; i++)
    {
        tree2.insertNode(i);
    }
    cout<<endl;
    tree2.outputTree(0);
    cout<<endl;
    cout<<"Объединение деревьев 2 и 1:"<<endl;
    cout<<"___________________________"<<endl;
    (tree2+tree1).outputTree(0);
    cout<<endl<<endl;
    cout<<"Пересечение деревьев 1 и 2 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree1*tree2).outputTree(0);
    cout<<endl;
    cout<<"Разность 1 -2 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree1-tree2).outputTree(0);
    cout<<"Разность 2 -1 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree2-tree1).outputTree(0);

    return 0;
}
