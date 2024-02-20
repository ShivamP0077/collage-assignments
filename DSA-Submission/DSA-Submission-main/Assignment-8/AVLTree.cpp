#include<iostream>
#include<queue>
using namespace std;

class Node{
   public:
    int data,hight;
    Node *left,*right;

    Node(int d)
    {
        data = d;
        hight = 1;
    }

};

class avlTree{
   public:
    Node *root;

    int hight(Node* temp)
    {
        if(temp == NULL)
         return 0;

         return temp->hight;
    }

    int hightBalance(Node* temp)
    {
        if(temp == NULL)
         return 0;

         return hight(temp->left) - hight(temp->right);
    }

    Node *leftRotation(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        x->hight = max(hight(x->left) , hight(x->right))+1;
        y->hight =  max(hight(y->left) , hight(y->right))+1;

        return y;
    }

    Node *rightRotation(Node *x)
    {
        Node *y = x->left;
        Node *temp = y->right;

        y->right = x;
        x->left = temp;

        x->hight = max(hight(x->left) , hight(x->right)) +1;
        y->hight =  max(hight(y->left) , hight(y->right))+1;


        return y;



    }

    Node *insert(Node *root,int data)
{
    if(root == NULL)
     return new Node(data);


     if(root->data > data)
       root->left = insert(root->left,data);
    else if(root->data < data)
      root->right = insert(root->right,data);
      else
       return root;


       int balance = 1 + hightBalance(root->left) + hightBalance(root->right);

       if(balance > 1 && root->left->data > data)
         return rightRotation(root);

       if(balance < -1 && root->right->data < data)
         return leftRotation(root);

       if(balance > 1 && root->left->data < data)
         {
            root->left = leftRotation(root->left);
            return rightRotation(root);
         }

      if(balance < -1 && root->right->data > data)
      {
        root->right = rightRotation(root->right);
        return leftRotation(root);
      }

      return root;
}

// min value in avl

Node *minVal(Node* root)
{
   Node *temp = root;
   while(temp->left != NULL)
   {
      temp = temp->left;
   }
   return temp;
}

// delete in avl

Node* deleteInAvl(Node* root,int data)
{
   // no child
   if(root->data == data)
   {
      if(root->left == NULL && root->right == NULL)
      {
         root = NULL;
      }
    // 1 child

      // left exist
      if(root->left != NULL && root->right == NULL)
      {
         root = root->left;

      }
        // right exits
       if(root->left == NULL && root->right != NULL)
      {
         root = root->right;

      }
       // 2 child
      if(root->left != NULL && root->right != NULL)
      {
             int min = minVal(root->right)->data;
             root->data = min;
             root->right = deleteInAvl(root->right,min);

      }
   }
   // go to left part
   else if(root->data > data)
   {
      root->left = deleteInAvl(root->left,data);

   }
   // go to right part
   else
   {
      root->right = deleteInAvl(root->right,data);

   }


   if (root == NULL)
    return NULL;

    root->hight = max(hight(root->left),hight(root->right)) + 1;

    int balance = 1 + hightBalance(root->left) + hightBalance(root->right);

     if(balance > 1 && root->left->data > data)
         return rightRotation(root);

       if(balance < -1 && root->right->data < data)
         return leftRotation(root);

       if(balance > 1 && root->left->data < data)
         {
            root->left = leftRotation(root->left);
            return rightRotation(root);
         }

      if(balance < -1 && root->right->data > data)
      {
        root->right = rightRotation(root->right);
        return leftRotation(root);
      }

      return root;


}


};

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


void Input(Node* &root)
{

    avlTree a;
    int data;
    cin>> data;
    while(data != -1){
  root = a.insert(root,data);
    cin>>data;
    }

}

Node* searchInAVL(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return searchInAVL(root->left, value);
    else
        return searchInAVL(root->right, value);
}

int main(void)
{
  Node * root = NULL;
  avlTree a;


  Input(root);
 // root = a.deleteInAvl(root,6);

  LOT(root);
  return 0;
}


