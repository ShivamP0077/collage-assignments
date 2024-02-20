#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// creating tree using recurtion

Node* BuildTree(Node *root)
{
   cout<<"Enter a data: "<<endl;
   int data;
   cin>>data;
   root = new Node(data);

   if (data == -1)
      return NULL;

   cout<<"Enter data for inserting in left: "<<endl;
   root->left = BuildTree(root->left);
   cout<<"Enter data for inserting in right: "<<endl;
   root->right = BuildTree(root->right);
   return root;

}

//Leavel Order travers

void LOT(Node *root)
{
   queue<Node*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty())
   {
      Node *temp = q.front();
      q.pop();

      if(temp == NULL)
      {
         cout<<endl;
          if(!q.empty())
            q.push(NULL);
      }
      else
      {
         cout<<temp->val<<" ";
         if(temp -> left)
           q.push(temp->left);

      if(temp->right)
         q.push(temp->right);
      }



   }
}

// inorder traversal

void InOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

   InOrder(root->left);
   cout<<root->val<<" ";
   InOrder(root->right);

}

// post order

void PostOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

PostOrder(root->left);
PostOrder(root->right);
cout<<root->val<<" ";

}

// pre order

void PreOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

cout<<root->val<<" ";
PreOrder(root->left);
PreOrder(root->right);


}


// build tree using lavel order

Node * Build(Node *root)
{
  queue<Node*> q;

  cout<<"Enter a Root Element: ";
  int data;
  cin>>data;
  root = new Node(data);
   q.push(root);

  while(!q.empty())
  {
     Node * temp = q.front();
     q.pop();

     cout<<"Enter a left Element of "<<temp->val;
     int l;
     cin>>l;
     if(l != -1){
        temp->left = new Node(l);
        q.push(temp->left);
     }



      cout<<"Enter a right Element of "<<temp->val;
     int r;
     cin>>r;
     if(r != -1){
        temp->right = new Node(r);
        q.push(temp->right);
     }

  }
  return root;
}


int main(void)
{
   // 3 2 -1 -1 4 -1 -1
   Node *root = NULL;
   root = Build(root);
   LOT(root);
  // PostOrder(root);
}