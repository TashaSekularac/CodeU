//
//  assignment2.cpp
//  codeU
//
//  Created by Tamara Sekularac on 5/28/17.
//  Copyright © 2017 Tamara Sekularac. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
public:
    Node* left=nullptr;
    Node* right=nullptr;
    int val;
    Node(int t):val(t){}
};


bool printAllAncestorsHelp(Node *root, Node* target)
{
    if (root == nullptr)
        return false;
    if (root->val == target->val)
        return true;
    if ( printAllAncestorsHelp(root->left, target) || printAllAncestorsHelp(root->right, target) )
    {
        cout << root->val << " ";
        return true;
    }
    return false;
}


void printAllAncestors(Node *root, Node* target)
{
    printAllAncestorsHelp(root, target);
    cout<<endl;
}




bool cover(Node* root, Node* target)
{
    if (root == nullptr)
        return false;
    if (root->val == target->val)
        return true;
    return cover(root->left, target) || cover(root->right, target);
}

Node* commonAncestorHelp(Node* root, Node* p, Node* q)
{
    if (root ->val== p->val && root->val == q->val) return root;
    if (root==nullptr) return nullptr;
    
    Node* x = commonAncestorHelp(root->left, p, q);
    if (x != nullptr && x->val != p->val && x ->val!= q->val)
        return x;
    Node* y = commonAncestorHelp(root->right, p, q);
    if (y != nullptr && y->val != p->val && y->val!= q->val)
        return y;
    
    if (x != nullptr && y!=nullptr)
            return root;
    if (root->val ==p->val || root->val == q->val)
        return root;
    if(x==nullptr)
        return y;
    return x;
}
Node* commonAncestor(Node* root, Node* p, Node* q)
{
    if(!cover(root, p) || !cover(root, q))
        return nullptr;
    return commonAncestorHelp(root, p, q);
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
