| 遍历 | Easy   | 94.中序遍历                                                  |
| ---- | ------ | ------------------------------------------------------------ |
|      | Medium | 95.不同的二叉搜索树II                                        |
|      | Medium | 98.[验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/) |
|      | Medium | 99.[恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/) |





## 94.中序遍历

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> node_stk;
        TreeNode* temp = root;
        while(temp!=nullptr || !node_stk.empty()){
            while(temp){
                node_stk.push(temp);
                temp = temp->left;
            }
            temp = node_stk.top();
            node_stk.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
        return ans;
    }
};
```

## 95.不同的二叉搜索树II

递归思路：

generate(start, end)用于生成start到end之间全部二叉搜索树，用一个vector返回生成结果，具体思路是遍历`start<=i<=end `，将每一个节点作为根节点，然后递归调用generate(start, i-1), generate(i+1, end)生成全部可能的左子树和全部可能的右子树，然后遍历全部子树组合，将i作为根节点。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate(int start, int end){
        if(start > end){
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees = generate(start, i-1);

            vector<TreeNode*> rightTrees = generate(i+1, end);

            for(auto left:leftTrees){
                for(auto right:rightTrees){
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.push_back(currTree);
                }
            }
        }

        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = generate(1, n);

        return ans;
    }
};
```



## 98.验证二叉搜索树

其实就是中序遍历，遍历过程要保证二叉搜索树的特征

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        bool first = true;
        int cur = 0;
        while(!stk.empty()||node!=nullptr) {
            while(node){
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if(first){
                first = false;
                cur = node->val;
            }
            else{
                if(cur >= node->val)
                    return false;
                cur = node->val;
            }
            node = node->right;
        }
        return true;
    }
};
```



## 99.恢复二叉搜索树

先中序遍历，找到不满足增序的两个点，然后交互值。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans;
        stack<TreeNode*> node_stk;
        TreeNode* temp = root;
        while(temp!=nullptr || !node_stk.empty()){
            while(temp){
                node_stk.push(temp);
                temp = temp->left;
            }
            temp = node_stk.top();
            node_stk.pop();
            ans.push_back(temp);
            temp = temp->right;
        }
        int x=-1, y=-1;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]->val > ans[i+1]->val){
                if(x==-1){
                    x = i;
                }
                else if(y==-1){
                    y = i+1;
                }
            }
        }

        if(y == -1)
            y = x+1;

        int t = ans[x]->val;
        ans[x]->val = ans[y]->val;
        ans[y]->val = t;

    }
};
```

