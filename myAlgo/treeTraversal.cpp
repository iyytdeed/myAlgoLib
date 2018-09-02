	// postorderTraversal_recruse
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ivec;
        if(root == NULL) return ivec;
        vector<int> lvec = postorderTraversal(root->left);
        vector<int> rvec = postorderTraversal(root->right);
        ivec.insert(ivec.end(), lvec.begin(), lvec.end());
        ivec.insert(ivec.end(), rvec.begin(), rvec.end());
        ivec.push_back(root->val);
        return ivec;
    }
	
	// postorderTraversal_no_recruse _ Method1-reverse preOrder method (not correct!!!)
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while(!stk.empty() || cur != NULL){
            if(cur != NULL){
                stk.push(cur);
                res.insert(res.begin(), cur->val);
                cur = cur->right;
            }
            else{
                cur = stk.top(), stk.pop();
                cur = cur->left;
            }
        }
        return res;
    }
	
	// postorderTraversal_no_recruse _ Method2-general method
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root, *pre = NULL;
        while(!stk.empty() || cur != NULL){
			// 左子树入栈
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
				// 拿到栈顶元素の右儿子
                cur = stk.top()->right;
				// 栈顶元素 右儿子 存在且未访问过
                if(cur != NULL && cur != pre){
                    stk.push(cur);
                    cur = cur->left;
                }
				// 栈顶元素 右儿子 不存在或已访问过
                else{
                    cur = stk.top(), stk.pop();
                    res.push_back(cur->val);
                    pre = cur;
                    cur = NULL; // trick 下个循环直接访问栈顶元素
                }
            }
        }
        return res;
    }
	
	// inorderTraversal no_recruse
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while(!stk.empty() || cur != NULL){
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top(), stk.pop();
                if(cur == NULL) continue;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
	
	// preorderTraversal_no_recruse 
	vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while(!stk.empty() || cur != NULL){
            if(cur != NULL){
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            else{
                cur = stk.top(), stk.pop();
                cur = cur->right;
            }
        }
        return res;
    }
	
	// levelOrder
	vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<int> lvec;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        int lnum = que.size();
        while(!que.empty()){
            for(int i = 0; i < lnum; i++){
                TreeNode* t = que.front();
                que.pop();
                lvec.push_back(t->val);
                if(t->left != NULL) que.push(t->left);
                if(t->right != NULL) que.push(t->right);
            }
            res.push_back(lvec);
            lvec.clear();
            lnum = que.size();
        }
        return res;
    }
	
	// zigzagOrder
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> lvec;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        int lnum = que.size();
        bool lft2rht = true;
        while(!que.empty()){
            for(int i = 0; i < lnum; i++){
                TreeNode* t = que.front();
                que.pop();
				// levelOrder advancement
                if(lft2rht) lvec.push_back(t->val);
                else lvec.insert(lvec.begin(), t->val);
                if(t->left != NULL) que.push(t->left);
                if(t->right != NULL) que.push(t->right);
            }
            lft2rht = !lft2rht;
            res.push_back(lvec);
            lvec.clear();
            lnum = que.size();
        }
        return res;
    }
