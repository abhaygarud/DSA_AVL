#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
    int height;

};

Get_Height(Node*n)
{
    if(n==NULL)
    {
    return 0;

    }
    else 
    return n->height;
}
///dynamically allocation a nemory to a node pointer
Node*Create_Node(int data)
{
    Node*n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
    
}
//getting the balacne factor of the root elemnt
Balance_Factor(Node *n)
{
    if(n==NULL)
    {
    return 0;
    }
    else
    return Get_Height(n->left)-Get_Height(n->right);
}

int max(int a,int b)
{
    // if(a>b)
    return (a>b)?a:b;
    // else 
    // return b;
}
//rotation for the left left rotation
Node*Left_rotation(Node *Y)
{
    Node*X=Y->left;
    Node*T2=X->right;

    X->right=Y;
    Y->left=T2;

    X->height=max(Get_Height(X->right),(Get_Height(X->left)+1));
    Y->height=max(Get_Height(Y->right),(Get_Height(Y->left)+1));

    return X;
}
//rotation function for the right right rotation 
Node*Right_rotation(Node*X)
{
    Node*Y=X->right;
    Node*T2=Y->left;

    Y->left=X;
    X->right=T2;

    X->height=max(Get_Height(X->right),(Get_Height(X->left)+1));
    Y->height=max(Get_Height(Y->right),(Get_Height(Y->left)+1));

    return Y;

}
// couting the  AVL tree in the postoder form (r0ot->left->rigth)
void Pre_order(Node*n)
{
    if(n!=NULL)
    {
        cout<<n->data<<"->";
        Pre_order(n->left);
        Pre_order(n->right);
    }
}
//insertion of the elemnt by consider the bst condition and balancing the tree with the i
// help of of else statement
Node*Insert_Node(Node*n,int key)
{
   if(n ==NULL)
   return Create_Node(key);

   if(n->data==key)
   {

       return NULL;
   }

   if(key<n->data)
   {
       n->left=Insert_Node(n->left,key);
   }
   else
   {
     n->right=Insert_Node(n->right,key);
   }
    //finding the inserted note hight in the tree
    n->height=1+max(Get_Height(n->right),Get_Height(n->left));
    int df=Balance_Factor(n);

/*chccking the conditon if df means balance factor is > 1 the we will poerform LL rotation of the AVL;*/
    // Left_rotation
    if(df>1&& key<n->left->data)
     return Left_rotation(n);
/*chccking the conditon if df means balance factor is <-1 the we will poerform RR rotation of the AVL;*/
    // right_right rotation
    if(df<-1 && key>n->right->data)
    {
        return Right_rotation(n);
    }
/* here we have another condition RL and LR condition in this we have to do if in LR constion 


      Y
    /    \           X beome the root in the LL  rotation 
    X     t3         same with the RR rotation we will go down to up diAGRAM  RR rotation Y become root 

   /   \
 t1    t2                X
                      /     \
                   t1           Y
                              /   \
                            t2    t3
                 


*/


    // right left pointer

    if(df>1 && key>n->left->data)
    {
        n->left=Right_rotation(n->left);
        return Left_rotation(n);
    }
    if(df<-1 && key<n->right->data)
    {
        n->right=Left_rotation(n->right);
        return Right_rotation(n);
    }
    return n;
}
int main(){
    struct Node * root = NULL;
 
 
    root = Insert_Node(root, 7);
    root = Insert_Node(root, 1);
    root = Insert_Node(root, 10);
    root = Insert_Node(root, 17);
    root = Insert_Node(root, 16);
    // root = Insert_Node(root, 22);
    // root = Insert_Node(root, 30);
    Pre_order(root);
    return 0;
    
    
}