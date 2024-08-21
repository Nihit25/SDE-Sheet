#include<iostream>
using namespace std;


// 26. Remove Duplicates from Sorted Array
#include<vector>
 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }






    // 485. Max Consecutive Ones
     int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_max=0;
        int max=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr_max++;
            }
            else{
                if(max<curr_max)max=curr_max;
                curr_max=0;
            }
        }
        if(max<curr_max)max=curr_max;
        return max;
    }





    // 700. Search in a Binary Search Tree
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
     TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val)return root;
            else if(root->val>val)root=root->left;
            else root=root->right;
        }
        return NULL;
    }






    // 215. Kth Largest Element in an Array
    #include<algorithm>
     int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<k;i++){
            nums.pop_back();
        }
        int n=nums.size();
        return nums[n-1];
    }





    // 104. Maximum Depth of Binary Tree
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        int ans=max(l,r);
        return ans+1;
    }





    // 543. Diameter of Binary Tre
    int diameter(TreeNode *root,int &ans){
        if(root==NULL)return 0;
        int left=diameter(root->left,ans);
        int right=diameter(root->right,ans);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diameter(root,ans);
        return ans;
    }







    // 102. Binary Tree Level Order Traversal
    #include<queue>
     vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        queue<TreeNode*>q;
        if(root==NULL)return v;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            vector<int>v1;
            while(x--){
                TreeNode *f=q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                v1.push_back(f->val);
            }
            v.push_back(v1);
        }
        return v;
    }





    // 110. Balanced Binary Tree
     int height(TreeNode *root){
        if(root==NULL)return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1 || !isBalanced(root->left) || !isBalanced(root->right))return false;
        return true;
    }






    // 100. Same Tree
      bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p!=NULL && q==NULL)return false;
        if(p==NULL && q!=NULL)return false;
        bool b=p->val==q->val;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&b;
    }





    // 236. Lowest Common Ancestor of a Binary Tree
     TreeNode* ancestor(TreeNode *root, int p, int q){
        if(root==NULL)return NULL;
        if(root->val==p || root->val==q)return root;
        TreeNode *leftAns=ancestor(root->left,p,q);
        TreeNode *rightAns=ancestor(root->right,p,q);
        if(leftAns!=NULL && rightAns!=NULL)return root;
        if(leftAns==NULL && rightAns!=NULL)return rightAns;
        if(leftAns!=NULL && rightAns==NULL)return leftAns;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans=ancestor(root,p->val,q->val);
        return ans;
    }






    // 101. Symmetric Tree
     bool symmetric(TreeNode *l,TreeNode *r){
        if(l==NULL && r==NULL)return true;
        if(l!=NULL && r==NULL)return false;
        if(l==NULL && r!=NULL)return false;
        bool a=symmetric(l->left,r->right);
        bool b=symmetric(l->right,r->left);
        bool c=l->val==r->val;
        if(a && b && c){
            return true;
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        if(symmetric(root->left,root->right)){
            return true;
        }else{
            return false;
        }
    }





    // 98. Validate Binary Search Tree
    #include<limits.h>
    bool BST(TreeNode *root,long minimum, long maximum){
        if(root==NULL)return true;
        if(!(root->val>minimum && root->val<maximum))return false;
        return BST(root->left,minimum,root->val)&&BST(root->right,root->val,maximum);
    }
    bool isValidBST(TreeNode* root) {
        return BST(root,LONG_MIN,LONG_MAX);
    }





    // 235. Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small=min(p->val,q->val);
        int large=max(p->val,q->val);
        while(root){
            if(root->val<small){
                root=root->right;
            }
            else if(root->val>large){
                root=root->left;
            }
            else return root;
        }
        return NULL;
    }





    // Floor in a BST: Codestudio
     template <typename T>
    class TreeNodes {
       public:
        T val;
        TreeNodes<T> *left;
        TreeNodes<T> *right;

        TreeNodes(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

    int floorInBST(TreeNodes<int> * root, int X)
{
    int ans=-1;
    while(root){
        if(root->val<=X){
            ans=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return ans;
}





// Ceil from BST: Codestudio
int findCeil(TreeNode *node, int x){
    // Write your code here.
    int ans=-1;
    while(node){
        if(node->val>=x){
            ans=node->val;
            node=node->left;
        }
        else{
            node=node->right;
        }
    }
    return ans;
}








// 230. Kth Smallest Element in a BST
void kthsmallest(TreeNode *root, int k, int &count, int &ans){
        if(root==NULL)return;
        kthsmallest(root->left,k,count,ans);
        count++;
        if(count==k)ans=root->val;
        kthsmallest(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans=0;
        kthsmallest(root,k,count,ans);
        return ans;
    }





    // Find K-th largest element in BST   GfG
    void kthlargest(TreeNode *root, int k, int &count, int &ans){
         if(root==NULL)return;
         kthlargest(root->right,k,count,ans);
         count++;
         if(count==k)ans=root->val;
         kthlargest(root->left,k,count,ans);
     }
    int kthLargest(TreeNode *root, int K)
    {
        //Your code here
        int count=0,ans=0;
        kthlargest(root,K,count,ans);
        return ans;
    }






// 215. Kth Largest Element in an Array
 int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<k;i++){
            nums.pop_back();
        }
        int n=nums.size();
        return nums[n-1];
    }





    // Implement stack using array  GfG
    class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
    void MyStack ::push(int x) {
    // Your Code
    top++;
    arr[top]=x;
}

int MyStack ::pop() {
    // Your Code
    if(top==-1)return -1;
    int ans=arr[top];
    top--;
    return ans;
}





// Implement Queue using array: GfG
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
void MyQueue :: push(int x)
{
        // Your Code
        arr[rear]=x;
        rear++;
}

int MyQueue :: pop()
{
        // Your Code   
        if(rear<=front)return -1;
        int ans=arr[front];
        front++;
        return ans;
}






// 225. Implement Stack using Queues
queue<int>q;
    
    void push(int x) {
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }





    // 232. Implement Queue using Stacks
    stack<int>s1;
    #include<stack>
stack<int>s2;
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }





    // 496. Next Greater Element I
     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        vector<int>v(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty())v[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=v[j];
                }
            }
        }
        return ans;
    }





    //  Sort a Stack: CodeStudio
    void insertStack(stack<int>&stack,int num){
	if(stack.empty() || (!stack.empty() && stack.top()<num)){
		stack.push(num);
		return;
	}
	int x=stack.top();
	stack.pop();
	insertStack(stack,num);
	stack.push(x);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())return;
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insertStack(stack,num);
}
