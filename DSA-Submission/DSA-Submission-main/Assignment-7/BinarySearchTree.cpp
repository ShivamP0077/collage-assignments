#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
       int data;
       Node* left;
       Node* right;

       Node(int val)
       {
        this->data = val;
        this->left = NULL;
        this->right = NULL;

       }
};
  // create bst
Node *createBST(Node* root,int d)
{
     if(root == NULL)
     {
        root = new Node(d);
        return root;
     }

     if(root->data > d)
        root->left = createBST(root->left,d);
     else
        root->right = createBST(root->right,d);

        return root;

}

void Input(Node* &root)
{
    int data;
    cin>> data;
    while(data != -1){
  root = createBST(root,data);
    cin>>data;
    }



}
  // level order traversal
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
         cout<<temp->data<<" ";
         if(temp -> left)
           q.push(temp->left);

      if(temp->right)
         q.push(temp->right);
      }

   }
}

 // inorder

 void InOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

   InOrder(root->left);
   cout<<root->data<<" ";
   InOrder(root->right);

}

// pre order

void PreOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

cout<<root->data<<" ";
PreOrder(root->left);
PreOrder(root->right);

}

//post order

void PostOrder(Node *root)
{
   if(root == NULL)
   {
      return;
   }

PostOrder(root->left);
PostOrder(root->right);
cout<<root->data<<" ";

}

   // search in bst
bool search(Node *root,int k)
{
    if(root == NULL)
      return false;

    if(root->data == k)
      return true;

    if(root->data > k)
      return search(root->left,k);
    else
      return search(root->right,k);
}

   // min value in bst

Node *minVal(Node* root)
{
   Node *temp = root;
   while(temp->left != NULL)
   {
      temp = temp-left;
   }
   return temp;
}

   // delete in bst

Node* deleteInBST(Node* root,int val)
{
   // no child
   if(root->data == val)
   {
      if(root->left == NULL && root->right == NULL)
      {
         delete root;
         return NULL;
      }
    // 1 child

      // left exist
      if(root->left != NULL && root->right == NULL)
      {
         Node* temp = root->left;
         delete root;
         return temp;
      }
        // right exits
       if(root->left == NULL && root->right != NULL)
      {
         Node* temp = root->right;
         delete root;
         return temp;
      }
       // 2 child
      if(root->left != NULL && root->right != NULL)
      {
             int min = minVal(root->right)->data;
             root->data = min;
             root->right = deleteInBST(root->right,min);
             return root;
      }
   }
   // go to left part
   else if(root->data > val)
   {
      root->left = deleteInBST(root->left,val);
      return root;
   }
   // go to right part
   else
   {
      root->right = deleteInBST(root->right,val);
      return root;

   }
}

int main(void)
{
    Node *root = NULL;

    cout<<"input to genarate a binary search tree : ";
    Input(root);
    LOT(root);
    cout<<"Which value you want to search:  ";
    int k;
    cin>>k;
   cout<<search(root,k)<<endl;

}