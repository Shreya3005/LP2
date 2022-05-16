#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
class Node {
    int data;
    Node *right, *left;
  public:
    Node() 
    {
      data = 0;
      left = NULL;
      right = NULL;
    }
    Node(int val) 
    {
      data = val;
      left = NULL;
      right = NULL;
    }

    friend class BST;
};

class BST 
{
     Node *root;

   public:
      BST() 
      {
       root = NULL;
      }
      Node* getRoot() 
      {
        return root;
      }

      void createTree(int val) 
      {
        Node *temp = new Node(val);
        if (root==NULL)
        {
            root = temp;
        }
        else
        {
          Node *temp1 = root;
          int flag = 0;
          while(flag == 0)
          {
            if(temp->data < temp1->data)
            {
              if(temp1->left==NULL)
              {
                temp1->left=temp;
                flag = 1;
              }
              else
              {
                temp1 = temp1->left;
              }
            }
            else if(temp->data > temp1->data)
            {
              if(temp1->right==NULL)
              {
                temp1->right=temp;
                flag = 1;
              }
              else
              {
                temp1 = temp1->right;
              }
            }
            else
            {
              cout << "Duplicate value" << endl;
              return;
            }
          }
        }
      }

      void inorder(Node *node) 
      {
        if (node) 
        {
          inorder(node->left);
          cout << node->data << "\t";
          inorder(node->right);
        }
      }
      
      void preorder(Node *node)
      {
        if (node)
        {
          cout << node->data << "\t";
          preorder(node->left);
          preorder(node->right);
        }

      }

      void postorder(Node *node)
      {
        if (node)
        {  
          postorder(node->left);
          postorder(node->right);
          cout << node->data << "\t";
        }

      }

      int search(Node *node, int key) 
      {
        while(node!=NULL) 
        {
            if (node->data == key) 
            {
                return 1;
            }
            else if (key < node->data) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        return -1;
      }
      
      int height(Node *node) 
      {
        if (node == NULL)
          return -1;
        else 
        {
          int lDepth = height(node->left);
          int rDepth = height(node->right);
          if (lDepth > rDepth)
            return (lDepth + 1);
          else
            return (rDepth + 1);
        }
      }
      
      bool isBalanced(Node *node)
      {
        if(node==NULL)
          return 1;

        int lh = height(node->left);
        int rh = height(node->right);

        if(abs(lh-rh)<=1 && isBalanced(node->left) && isBalanced(node->right))
          return 1;
        
        return 0;
      }


      void BFS(Node *node)
      {
        if(root==NULL)
          return;
        queue<Node*> q;
        q.push(root);
        while(q.empty() == false)
        {
          Node *b = q.front();
          cout << b->data << " ";
          q.pop();
          if(b->left != NULL)
          {
            q.push(b->left);
          }
          if(b->right != NULL)
          {
            q.push(b->right);
          }
        }  
      }

};
/*
                                             5
                                          /     \
                                        3         8
                                      /   \      /  \
                                    2      4   7      9
*/
int main() 
{
    int choice, k, val;
    BST d;
    string ch, ch1;
    do 
    {
       cout << "1. Insert data \n";
       cout << "2. Height of the tree \n";
       cout << "3. DFS \n";
       cout << "4. Search \n";
       cout << "5. BFS \n";
       cout << "Enter your choice: ";
       cin >> choice;
       switch (choice) 
       {
        case 1:  
          do 
          {
            cout << "Enter data: ";
            cin >> k;
            d.createTree(k);
            cout << "To continue adding enter y or n to terminate\n";
            cin>>ch1;
          } while(ch1 == "y" || ch == "Y");
          break;
        case 2:
            cout << "\nHeight:" << d.height(d.getRoot());  
            if (d.isBalanced(d.getRoot()))
               cout << "\nTree is balanced";
            else
               cout << "\nTree is not balanced";   
            break;
        case 3:
            cout<<"\nInorder: ";
            d.inorder(d.getRoot()); 
            cout<<"\nPreorder: ";
            d.preorder(d.getRoot());
            cout<<"\nPostorder: ";
            d.postorder(d.getRoot());
            
            break;

        case 4:
            cout << "Enter data you want to search : ";
            cin >> val;
            if (d.search(d.getRoot(), val) == -1)
                cout << "data not found" << endl;
            else
                cout << "data Found" << endl;
            break;
      
        case 5:
            cout << "BFS is : \n";
            d.BFS(d.getRoot());
            break;
        default:
            cout << "Invalid input" << endl;
            break;
       }
        cout << "\nDo you want to continue(Y/N): ";
        cin >> ch;
    }while (ch == "Y" || ch == "y");
    return 0;
}