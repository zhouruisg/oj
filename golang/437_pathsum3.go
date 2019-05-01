package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func sumUp(node *TreeNode, prev int, target int) int{
	if node==nil {
		return 0
	}
	current := prev + node.Val
	var count = 0
	if current==target {
		count = 1
	}
	return count + sumUp(node.Left, current, target) + sumUp(node.Right, current, target)
}

func pathSum(root *TreeNode, sum int) int {
	if root==nil {
		return 0
	}
	return sumUp(root, 0, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
	return 0
}



/*
int pathSum(TreeNode* root, int sum) {
            if (!root)
                return 0;
            return sumUp(root, 0, sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
        }


        int sumUp(TreeNode *node,int pre, int target) {
            if (!node)
                return 0;
            int current = pre + node->val;
            return (current==target) + sumUp(node->left, current, target) + sumUp(node->right,current, target);
        }

 */
func init() {
	testList = append(testList,TestEntry{"437_pathsum3",func (){
		{
			h1 :=CreateTree([]int{10,5,-3,3,2,null,11,3,-2,null,1})
			println(pathSum(h1,8)==3)
		}
	}})

}

/*
stack<int> st;
            string::size_type sz;
            for (auto &it:tokens) {
                if (it=="+" || it=="-" || it=="*" ||it=="/") {
                    if (st.size()>=2) {
                        int rhs = st.top();
                        st.pop();
                        int lhs = st.top();
                        st.pop();

                        switch (it[0]) {
                            case '*':
                                st.push(lhs * rhs);
                                break;
                            case '/':
                                st.push(lhs/rhs);
                                break;
                            case '+':
                                st.push(lhs+rhs);
                                break;
                            case '-':
                                st.push(lhs-rhs);
                                break;
                            default:
                                cout << "error" <<endl;
                                break;
                        }
                    } else {
                        cout << "error" <<endl;
                        break;
                    }
                } else {
                    st.push(stoi(it,&sz));
                }
            }
            if (!st.empty()) {
                return st.top();
            } else {
                return 0;
            }
 */