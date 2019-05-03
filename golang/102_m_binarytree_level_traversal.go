package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	ret:=[][]int{}
	stack:=[]*TreeNode{root}
	count:=1
	for ;len(stack)>0; {
		levelCount:=0
		level := []int{}
		for i:=0;i<count;i++ {
			node:=stack[0]
			stack = stack[1:]
			if node!=nil {
				level = append(level, node.Val)
				stack = append(stack, node.Left, node.Right)
				levelCount+=2
			}
		}
		if len(level)>0 {
			ret = append(ret, level)
		}
		count = levelCount
	}
	return ret
}

func init() {
	testList = append(testList,TestEntry{"102_binary_tree_level_traversal",func (){
		{
		}
	}})
}