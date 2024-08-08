#include<iostream>
using namespace std;

// 73. Set Matrix Zeroes
#include<vector>
#include<unordered_set>
 void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_set<int>setRows;
        unordered_set<int>setColumns;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(setRows.count(i) || setColumns.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }





    // 75. Sort Colors
    void sortColors(vector<int>& nums) {
        int ones=0,zeroes=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeroes++;
            else if(nums[i]==1)ones++;
        }
        for(int i=0;i<zeroes;i++){
            nums[i]=0;
        }
        for(int i=zeroes;i<ones+zeroes;i++){
            nums[i]=1;
        }
        for(int i=ones+zeroes;i<n;i++){
            nums[i]=2;
        }
    }





    // 53. Maximum Subarray
    #include<limits.h>
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }
        return ans;
    }




    // 121. Best Time to Buy and Sell Stock
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            if(prices[i]-buy >profit){
                profit=prices[i]-buy;
            }
        }
        return profit;
    }




    // 88. Merge Sorted Array
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int>v(m+n);
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                v[k++]=nums1[i++];
            }else{
                v[k++]=nums2[j++];
            }
        }
        while(i<m){
            v[k++]=nums1[i++];
        }
        while(j<n){
            v[k++]=nums2[j++];
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=v[i];
        }
    }




    // 287. Find the Duplicate Number
     int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int num:nums){
            if(s.find(num)!=s.end()){
                return num;
            }
            s.insert(num);
        }
        return -1;
    }





    // 56. Merge Intervals
    #include<algorithm>
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(  ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }




// 48. Rotate Image
 void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }





// 74. Search a 2D Matrix
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0,e=row*col-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int element=matrix[mid/col][mid%col];
            if(element==target){
                return true;
            }
            else if(element<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }





    // 50. Pow(x, n)
     double power(double x, int n){
        if(n==0)return 1;
        if(n==1)return x;
        double ans=power(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }
    double myPow(double x, int n) {
        double ans=power(x,n);
        if(n<0){
            return 1/ans;
        }
        return ans;
    }






    // 169. Majority Element
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(majority==nums[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                majority=nums[i];
                count++;
            }
        }
        return majority;
    }





    // 229. Majority Element II
    #include<unordered_map>
    #include<vector>
     vector<int> majority_Element(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int x=nums.size()/3;
        for(int num:nums)mp[num]++;
        for(auto a:mp){
            int element=a.first;
            int count=a.second;
            if(count>x){
                ans.push_back(element);
            }
        }
        return ans;
    }





    // 1. Two Sum
     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int l=0,r=n-1;
        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            if(mp.count(complement)){
                return {mp[complement],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }






    // 94. Binary Tree Inorder Traversal
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    void inorder(TreeNode *root,vector<int>&ans){
        if(root==NULL)return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;

        inorder(root,ans);
        return ans;
    }






    // 144. Binary Tree Preorder Traversal
     void preorder(TreeNode *root,vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;

        preorder(root,ans);
        return ans;
    }





    // 145. Binary Tree Postorder Traversal
    void postorder(TreeNode *root,vector<int>&ans){
    if(root==NULL)return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
   }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        postorder(root,ans);
        return ans;
    }





    // Left View of Binary Tree; GfG
    struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
    void leftView(Node *root,vector<int>&ans,int level){
    if(root==NULL)return;
    if(ans.size()==level)ans.push_back(root->data);
    leftView(root->left,ans,level+1);
    leftView(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   leftView(root,ans,0);
   return ans;
}






// 206. Reverse Linked List
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 void solve(ListNode *&head,ListNode *curr,ListNode *prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode *forward=curr->next;
        solve(head,forward,curr);
        curr->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head;
        ListNode *prev=NULL;
        solve(head,curr,prev);
        return head;
    }





    // 876. Middle of the Linked List
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        if(head->next->next==NULL)return head->next;

        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast){
            fast=fast->next;
            if(fast)fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }





    // 21. Merge Two Sorted Lists
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans=new ListNode(-1);
        ListNode *temp=ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
              temp->next=list1;
                temp=list1;
                list1=list1->next;
        }
        while(list2!=NULL){
            temp->next=list2;
                temp=list2;
                list2=list2->next;
        }
        return ans->next;
    }





    // 19. Remove Nth Node From End of List
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *first=dummy;
        ListNode *second=dummy;
        for(int i=0;i<=n;i++){
            first=first->next;
        }
        while(first){
            first=first->next;
            second=second->next;
        }
        ListNode *temp=second->next;
        second->next=second->next->next;
        delete temp;
        return dummy->next;
    }






// 2. Add Two Numbers
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        int carry=0;
        while(l1 || l2 || carry){
            int digit1=(l1!=NULL)?l1->val:0;
            int digit2=(l2!=NULL)?l2->val:0;
            int sum=digit1+digit2+carry;
            int digit=sum%10;
            carry=sum/10;

            ListNode *newNode=new ListNode(digit);
            temp->next=newNode;
            temp=temp->next;

            l1=(l1!=NULL)?l1->next:0;
            l2=(l2!=NULL)?l2->next:0;
        }
        return dummy->next;
    }





// 237. Delete Node in a Linked List
void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }




// 160. Intersection of Two Linked Lists
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL)return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }





    // 141. Linked List Cycle
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }





    // 25. Reverse Nodes in k-Group
    int getLen(ListNode *head){
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return head;
        int len=getLen(head);
        if(len<k)return head;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *forward=NULL;
        int count=0;
        while(curr && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward){
            head->next=reverseKGroup(curr,k);
        }
        return prev;
    }





    // 142. Linked List Cycle II
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)break;
        }
        if(fast==NULL || fast->next==NULL)return NULL;
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }




    // 234. Palindrome Linked List
     ListNode* getMiddle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forward=NULL;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        ListNode *middle=getMiddle(head);
        ListNode *temp=middle->next;
        middle->next=reverse(temp);
        ListNode *head1=head;
        ListNode *head2=middle->next;
        while(head2){
            if(head1->val!=head2->val)return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
