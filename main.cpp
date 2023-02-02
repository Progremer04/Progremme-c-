#include <iostream>
#include<string>
#include<bits/stdc++.h>
#include<windows.h>
#include<vector>
#include<algorithm>
using namespace std;
class tree
{
  public:
    int key;
    tree *left, *right;
    tree *inserttree(tree *root, int key)
    {
        if (root == NULL)
        {
            tree *new1 = new tree;
            new1->key = key;
            new1->left = new1->right = NULL;
            return new1;
        }
        else
        {
            if (key < root->key)
                root->left = inserttree(root->left, key);
            else if (key > root->key)
                root->right = inserttree(root->right, key);
        }
    }
    tree *minValueNode(tree *node)
    {
        tree *current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    /* Given a binary search tree and a key, this function
deletes the key and returns the new root */
    tree *deleteNode(tree *root, int key)
    {
        // base case
        if (root == NULL)
            return root;

        // If the key to be deleted is
        // smaller than the root's
        // key, then it lies in left subtree
        if (key < root->key)
            root->left = deleteNode(root->left, key);

        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
        else
        {
            // node has no child
            if (root->left == NULL and root->right == NULL)
                return NULL;

            // node with only one child or no child
            else if (root->left == NULL)
            {
                tree *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                tree *temp = root->left;
                free(root);
                return temp;
            }

            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
            tree *temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
    // Parcurs prefixe {racine,left,right}
    void prefixe(tree *root)
    {
        if (root != NULL)
        {
            cout << "\t" << root->key;
            prefixe(root->left);
            prefixe(root->right);
        }
        cout << endl;
    }
    // Parcours infixe {left,racine,right}
    void infixe(tree *root)
    {
        if (root != NULL)
        {
            infixe(root->left);
            cout << "\t" << root->key;
            infixe(root->right);
        }
        cout << endl;
    }
    // posfixe {left,right,racine}
    void posfixe(tree *root)
    {
        if (root != NULL)
        {
            posfixe(root->left);
            posfixe(root->right);
            cout << "\t" << root->key;
        }
        cout << endl;
    }
    // heigth
    int tree_height(tree *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            // Find the height of left, right subtrees
            int left_height = tree_height(root->left);
            int right_height = tree_height(root->right);

            // Find max(subtree_height) + 1 to get the height of the tree
            return max(left_height, right_height) + 1;
        }
    }
};

class linked
{
  public:
    int key;
    linked *next;
    linked *addatend(linked *root, int key)
    {
        if (root == NULL)
        {
            linked *newnode = new linked;
            newnode->key = key;
            newnode->next = NULL;
            return newnode;
        }


else
            root->next = addatend(root->next, key);
    }
    linked *addatbegin(linked *root, int key)
    {
        linked *newnode = new linked;
        newnode->key = key;
        newnode->next = root;
        root = newnode;
        return root;
    }
    void show(linked *root)
    {
        if (root == NULL)
        {
            cout << "End Of Linked List " << endl;
            return;
        }
        else
        {
            cout << "\t" << root->key << endl;
            show(root->next);
            return;
        }
    }
    void del(linked *&head, int val)
    {
        if (head == NULL)
        {
            cout << "Element not present in the list\n";
            return;
        }
        if (head->key == val)
        {
            linked *t = head;
            head = head->next;
            delete (t);
            return;
        }
        del(head->next, val);
    }
    linked *reverselist(linked *root)
    {
        if (root == NULL)
            return root;
        else
        {
           linked* root1=NULL;
            while(root!=NULL)
            {
                root1=root1->addatbegin(root1,root->key);
                root=root->next;
            }
            return root1;
        }
    }
    int size(linked *root)
    {
        if (root == NULL)
            return 0;
        else

            return 1 + size(root->next);
    }
};
class stacks
{
  public:
    int key;
    stacks *next;

    bool empty(stacks *p)
    {
        if (p == NULL)
            return true;
        else
            return false;
    }
    // peak ==sommet
    int top(stacks **p)
    {
        int x;
        if (p != NULL)
            x = (*p)->key;
        return x;
    }
    // pop : delete peak;
    void pop(stacks **p)
    {
        stacks *before = *p;

        *p = before->next;

        free(before);
    }

    void push(stacks **p, int key)
    {
        stacks *newstack = new stacks;
        newstack->key = key;
        newstack->next = *p;
        *p = newstack;
    }
    void show(stacks *p)
    {
        while (((p)->empty(p)) != true)
        {
            cout << p->top(&p) << endl;
            p->pop(&p);
            // p=p->next;
        }
    }
    int size(stacks *p)
    {
        if (((p)->empty(p)) == true)
            return 0;
        else

            return 1 + size(p->next);
    }
};

class Array {
    private:
        vector<int> arr;

    public:
        void addElement(int element) {
            arr.push_back(element);
        }

        void deleteElement(int element) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == element) {
                    arr.erase(arr.begin() + i);
                    break;
                }
            }
        }

        void showArray() {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void reverseArray() {
            reverse(arr.begin(), arr.end());
        }

        void sortArray() {
            sort(arr.begin(), arr.end());
        }
        int size()
        {
            return arr.size();
        }
};

class looding{
public:
    int secend=80;
    string namefile;
  void menu()
{

    system("COLOR 0e");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    printf_s("\n\n\n\t\t\t\t Looding");
    for (int j = 0; j < 10; j++)
    {
        printf_s(".");
        Sleep(10);
    }
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\t\t\t\t This Work Was Creating By ");
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\t\t\t\t    \t Alliche Amine Mohamed ");
    printf_s("\n\t\t\t\t Hello In Data structure Programme You Find 4 Type structure {\t Benaire Shearsh Tree | Single Linked List | Stack | Vector\t} \n\n\t\t\t\t This Programme Make You had a information about 4 Data structure \n\n\t\t\t\t Enjoy");
    printf_s("\n\n\n\t\t\t\t");
    Sleep(4);
    for (int i = 0; i < 80; i++)
    {

        printf("%c", (char)bar2);
        Sleep(100);
    }
    system("COLOR 0e");
    printf_s("\n\n\n\t\t\t\t\n\n\n\t\t\t\t");
    system("pause");
    system("cls");
    system("COLOR 0F");
}
  void menu1()
{

    system("COLOR 08");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    printf_s("\n\n\n\t\t\t\t Looding");
    for (int j = 0; j < 10; j++)
    {
        printf_s(".");
        Sleep(1);
    }
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\n\n\t\t\t\t");
    //Sleep(4);
    for (int i = 0; i <25; i++)
    {
        printf("%c", (char)bar2);
        Sleep(20);
    }

    system("cls");
    system("COLOR 0F");
}

void gotoxy(int x, int y)
{
    COORD coord = {0, 0}; // this is global variable
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showfile(string name)
{

    system("cls");
    system("COLOR 07");
    std:: ifstream inputFile(name);
   //std::ifstream inputFile("Stack.txt"); // open the file
    int spaceCount = 0; // initialize a counter for spaces
    char currentChar; // variable to store the current character

    while (inputFile >> std::noskipws >> currentChar) { // read the file character by character
        std::cout << currentChar;
        if (currentChar ==' ') { // check if the current character is a space
           Sleep(secend); // if it is, increment the counter
        }else
        {
            Sleep(20);
        }
    }
    inputFile.close(); // close the file

    system("cls");
    system("COLOR 0F");
}
};
int main()
{
    int x,y;string n1;
    system("cls");
    looding menus;
    menus.gotoxy(10,10);
    string n= "Hello In My Programme ";
    system("color 05");
    x=20;y=10;
    for (int i=0; n[i]!='\0';i++,x++)
    {
        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(10);
    }
     Sleep(2000);
    n= "Why My Proggremme";
    system("cls");
    system("color 0E");
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(10);
    }
    Sleep(2000);
    system("cls");
    n="Parfact";
    system("color 0B");
    x=10;y=30;
    for (int i=0; n[i]!='\0';i++,x++)
    {

        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(10);
    }
    Sleep(2000);
    system("cls");
        system("color 08");
    n="Better";
    x=50;y=40;
    for (int i=0; n[i]!='\0';i++,x++)
    {

        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(10);
    }
    Sleep(2000);
    system("cls");
    system("color 06");
    n="Why We Love Programmer Look It's Make you Creative Happy Make  You Really succed Human ";
    x=20;y=4;
    for (int i=0; n[i]!='\0';i++,x++)
    {

        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(20);
    }
    Sleep(2000);
    system("cls");
    system("color 0A");
    n="This code is like no other, an epic achievement | A masterpiece that will stand the test of time  | It's an awe-inspiring work of art that will never be forgotten  ";
    x=20;y=5;
    for (int i=0; n[i]!='\0';i++,x++)
    {
        if (n[i]=='|')
        {menus.gotoxy(x+2,y+2);cout<<endl;}
        menus.gotoxy(x,y);
        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
    system("cls");
    x=10;y=7;
    system("color 0E");
    n="A work of genius that will live on forevermore | My code is legendary";

    for (int i=0; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;}
           menus.gotoxy(x,y);
        cout<<n[i];

        Sleep(30);
    }
    Sleep(3000);
    system("cls");
 system("color 0C");
    n="This code is a masterpiece of programming,| crafted with precision and expertise. | It is highly efficient, reliable and secure, | making it an ideal choice for complex applications. | It is also extremely flexible, | allowing for easy customization and modification to meet specific needs. | This code is truly a work of art, providing a high level of performance with minimal effort. |";
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;} menus.gotoxy(x,y);

        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
    system("cls");

 system("color 03");
    n="I Love Coding";
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;} menus.gotoxy(x,y);

        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
    system("cls");
 system("color 03");
    n="It's complex and intricate, but so well designed | A beautiful amalgamation of algorithms and functions |A perfect harmony of logic and creativity |My code is an unbeatable combination.";
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;} menus.gotoxy(x,y);

        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
    system("cls");
 system("color 03");
  n="My code is legendary, a masterful creation|A work of art, so divinely inspired|No one can compete, no one can match it|It's pure genius, a marvel to behold";
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;} menus.gotoxy(x,y);

        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
system("cls");
 system("color 03");
 n="This code is like no other, an epic achievement|A masterpiece that will stand the test of time| It's an awe-inspiring work of art that will never be forgotten |My code is legendary, a timeless innovation. ";
    x=10;y=20;
    for (int i=0 ; n[i]!='\0';i++,x++)
    {

           if (n[i]=='|') {menus.gotoxy(x+2,y+2);cout<<endl;} menus.gotoxy(x,y);

        cout<<n[i];
        Sleep(30);
    }
    Sleep(3000);
    system("cls");
    system("color 0F");

    Array arr;
    linked *linkedlist = NULL,*root;
    tree *treebst = NULL;
    stacks *stackss = NULL;
    int choice, choice1, choice2, choice3,choice4, val;
    bool loop1,loop2,loop3,loop4,loop5;
    loop1=loop2=loop3=loop4=loop5=true;char reponce;
        menus.menu();
    while (loop1==true)
    {
    loop2=loop3=loop4=loop5=true;
        cout << "\n\n Before You  go to choice Your Data structure  Type There is a small intrudoction read it \n\n \n 1-\t  binary shearch tree  \n 2-\t  Single linked list \n 3-\t Stack   \n 4-\t  Vector\n 5-\t  Exit\n  Give me your choice\t";
        cin >> choice;
        menus.menu1();
        switch (choice)
        {
case 1:
        {
            cout<<"Do You Need To Show Information About Data structure You Choice {Y/N} {y/n} \t";cin>>reponce;
            if (reponce=='Y' || reponce=='y'){
            menus.gotoxy(3,4);
            menus.showfile("bts.txt");
            }

            while (loop2==true){
                    menus.menu1();
            cout << "\n\n \n 1-\t  Add value\n 2-\t  Delete  \n 3-\t show prefixe   \n 4-\t  show infixe \n 5-\t  show postfixe \n 6-\t heigth of bst  \n 7-\t  Exit to main\n  Give me your choice\t";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {

                cout << "\n Give me value for add it in bst\t";
                cin >> val;
                treebst = treebst->inserttree(treebst, val);
                break;
            }
            case 2:
            {
                cout << "\n Give me value for delete it in bst\t";
                cin >> val;
                treebst = treebst->deleteNode(treebst, val);
                break;
            }
            case 3:
            {
                cout << endl;
                treebst->prefixe(treebst);
                Sleep(2000);
                break;

            }
            case 4:
            {
                cout << endl;

                treebst->infixe(treebst);
                Sleep(2000);
                break;
            }

            case 5:
            {
                cout << endl;
                treebst->posfixe(treebst);
                Sleep(2000);
                break;
            }
            case 6:
            {
                cout << endl
                     << "Height of benaire shearch tree is \t" << treebst->tree_height(treebst) << endl;
                Sleep(2000);
                break;
            }
            case 7:
            {
                loop2=false;
                break;
            }
            }
            }
            break;
        }

case 2:
   {
            cout<<"Do You Need To Show Information About Data structure You Choice {Y/N} {y/n} \t";cin>>reponce;
            if (reponce=='Y' || reponce=='y'){
            menus.gotoxy(3,4);
                        menus.showfile("Single Linked List.txt");
            }
            menus.gotoxy(0,0);
while (loop3==true ){
        menus.menu1();
cout << "\n\n \n 1-\t  Add value at begin \n 2-\t  Add value at end  \n 3-\t Delete    \n 4-\t  Reverse  \n 5-\t  size \n 6-\t Show   \n 7-\t  Exit to main\n  Give me your choice\t";
cin >> choice2;
            switch (choice2)
          {
            case 1:
            {

                cout << "\n Give me value for add it in Single Linked Liste At Begine\t";
                cin >> val;
                linkedlist=linkedlist->addatbegin(linkedlist,val);
                break;
            }
            case 2:
            {
                cout << "\n Give me value for add it in Single Linked List At End\t";
                cin >> val;
                linkedlist=linkedlist->addatend(linkedlist,val);
                break;
            }
            case 3:
            {
                cout << "\n Give me value for delete it in Linked list \t";
                cin >> val;
                linkedlist->del(linkedlist,val);
                break;
            }
            case 4:
            {
                cout << endl;
                linkedlist=linkedlist->reverselist(linkedlist);
                break;
            }

            case 5:
            {
                cout << endl
                     << "Size  of linked list is \t" << linkedlist->size(linkedlist) << endl;
                Sleep(2000);
                break;
            }
            case 6:
            {
                cout << endl;
                   linkedlist->show(linkedlist);
                Sleep(2000);
                break;
            }
            case 7:
            {
                loop3=false;
                break;
            }
            }
            }
 break;
   }

case 3:
{

             cout<<"Do You Need To Show Information About Data structure You Choice {Y/N} {y/n} \t";cin>>reponce;
            if (reponce=='Y' || reponce=='y'){
            menus.gotoxy(3,4);
            menus.showfile("Stack.txt");
            }

            menus.gotoxy(0,0);
            menus.menu1();
while (loop4==true){

 cout << "\n\n \n 1-\t  Add value {\t Push \t} \n 2-\t  Delete first value in Stack  \n 3-\t Show First Value Of  Stack \n 4-\t  size  \n 5-\t  verifite if stack is empty \n 6-\t Show   \n 7-\t  Exit to main\n  Give me your choice\t";
cin >> choice3;
switch(choice3)
{
case 1:
{
cout << "\n Give me value for add it in Stack \t";
cin >> val;
stackss->push(&stackss,val);
break;
}
case 2:
    {
        stackss->pop(&stackss);
        break;
    }
case 3:
    {
        cout<<endl<<"\t Top in Stack is :\t"<<stackss->top(&stackss)<<endl;
        Sleep(2000);
        break;
    }
case 4:
    {
        cout<<endl<<"\t size of Stack is :\t"<<stackss->size(stackss)<<endl;
        Sleep(2000);
        break;
    }
case 5:
    {
        if (stackss->empty(stackss)==true)
        cout<<endl<<"\t Stack is :\t Not empty"<<endl;
        else
        cout<<endl<<"\t Stack is :\t  empty"<<endl;
        Sleep(2000);
        break;
    }
case 6:
    {
        stackss->show(stackss);
    Sleep(2000);
        break;
    }
case 7:
    {
        loop4=false;
        break;
    }
}
}
break;
}

case 4:
{
            menus.gotoxy(3,4);
            cout<<"Do You Need To Show Information About Data structure You Choice {Y/N} {y/n} \t";cin>>reponce;
            if (reponce=='Y' || reponce=='y'){
            menus.gotoxy(3,4);
 menus.showfile("Vector.txt");
          }             }
menus.gotoxy(0,0);
while (loop5==true){
    menus.menu1();
 cout << "\n\n \n 1-\t  Add value  \n 2-\t  Delete Value  \n 3-\t Show All Value of Vector \n 4-\t  size  \n 5-\t  Sort Vector \n 6-\t Reverse Vector   \n 7-\t  Exit to main\n  Give me your choice\t";
cin >> choice4;
switch(choice4)
{
case 1:
{
cout << "\n Give me value for add it in Vector\t";
cin >> val;
arr.addElement(val);
break;
}
case 2:
    {
            cout << "\n Give me value for delete it in Vector\t";
            cin >> val;
            arr.deleteElement(val);
        break;
    }
case 3:
    {
        arr.showArray();
        Sleep(2000);
        break;
    }
case 4:
    {
        cout<<endl<<"\t size of Vector is :\t"<<arr.size()<<endl;
        Sleep(2000);
        break;
    }
case 5:
    {
        arr.sortArray();
        cout<<"After Sort "<<endl;
        arr.showArray();
        cout<<endl;
        Sleep(2000);
        break;
    }
case 6:
    {
        arr.reverseArray();
        cout<<"After Reverse "<<endl;
        arr.showArray();
        cout<<endl;
      Sleep(2000);
        break;
    }
case 7:
    {

        loop5=false;
        break;
    }
}
}
break;
}


case 5:
    {
         cout<<"Thanks For Using Our Programmer"<<endl;
        Sleep(2000);
        loop1=false;
        break;
    }

}

}
}
