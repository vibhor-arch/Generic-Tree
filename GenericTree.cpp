#include<iostream>
#include "TreeNode.h"
#include<queue>
using namespace std;

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data::" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i=0; i < numChild ;i++){
            cout << "Enter the " << i+1 << " th children of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
}


void printLevelWise(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " ";
        for(int i=0; i < front->children.size();i++){
            //cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
    }
    cout << endl;
}

TreeNode<int> *takeInput(){
    int rootData;
    cout << "Enter root data::" << endl;
    cin >> rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);
    cout << "Enter the number of children::" << endl;
    int n;
    cin >> n;
    for(int i=0;i < n;i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}



void printTree(TreeNode<int> *root){
    if(root == NULL)
        return;

    cout << root->data << ":";

    for(int i= 0; i <root->children.size();i++){
        cout << root->children[i]->data << ",";
    }

    cout << endl;

    for(int i=0; i < root->children.size();i++){
        printTree(root->children[i]);
    }
}

int sumOfNodes(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int sum = 0;
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        sum = sum + front->data;
        for(int i=0; i < front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return sum;
}

int sumOfNodesRec(TreeNode<int> *root){
    int sum = root->data;
    for(int i=0; i < root->children.size();i++){
        sum+=sumOfNodesRec(root->children[i]);
    }
    return sum;
}


int countNumberOfNodes(TreeNode<int> *root){
    int count = 0;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        count=count+1;
        for(int i=0;i < front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return count;
}

int countNodesRec(TreeNode<int> *root){
    int ans=1;
    for(int i=0;i < root->children.size();i++){
        ans+=countNodesRec(root->children[i]);
    }
    return ans;
}


int maximumElement(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int max= root->data;
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->data > max)
            max = front->data;
        for(int i=0; i < front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
}


TreeNode<int> *maximumElementRec(TreeNode<int> *root){
    TreeNode<int> *maximum = root;
    for(int i=0; i < root->children.size();i++){
    TreeNode<int> *maxi = maximumElementRec(root->children[i]);
    if(maxi->data > maximum->data)
        maximum = maxi;
    }
    return maximum;
}

int heightOfTree(TreeNode<int> *root){
    int h=0,heigh=0;
    if(root==NULL)
        return 0;
    for(int i=0;i < root->children.size();i++){
        h = heightOfTree(root->children[i]);
        if(h > heigh)
            heigh = h;
    }
    return heigh+1;
}

void printAtLevelK(TreeNode<int>* root,int depth){
    if(depth == 0)
        cout << root->data << " ";
    for(int i=0;i < root->children.size();i++){
        printAtLevelK(root->children[i],depth-1);
    }
    return;
}

void preOrder(TreeNode<int> *root){
    if(root == NULL)
        return;
    cout << root->data << " ";
    for(int i=0;i < root->children.size();i++){
        preOrder(root->children[i]);
    }
    return;
}

void postOrder(TreeNode<int> *root){
    if(root == NULL)
        return;
    for(int i=0;i < root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteNode(TreeNode<int> *root){
    for(int i=0;i < root->children.size();i++){
        deleteNode(root->children[i]);
    }
    delete root;
}
int main(){
    /*TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *node1 = new TreeNode<int>(20);
    TreeNode<int> *node2= new TreeNode<int>(30);

    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << sumOfNodes(root) << endl;
    cout << countNumberOfNodes(root) << endl;
    cout << countNodesRec(root) << endl;
    cout << sumOfNodesRec(root) << endl;
    cout << maximumElement(root) << endl;
    TreeNode<int>* maximum=maximumElementRec(root);
    cout << maximum->data << endl;
    cout << heightOfTree(root) << endl;
    printAtLevelK(root,2);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);

}
