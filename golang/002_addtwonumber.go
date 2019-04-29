package main

import (
	"fmt"
	"reflect"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	cur1 :=l1
	cur2 :=l2
	carry :=0
	dummy := ListNode{0,nil}
	prev := &dummy

	for ;cur1!=nil || cur2!=nil || carry !=0; {
		s1:=0
		s2:=0
		if cur1!=nil {
			s1 = cur1.Val
			cur1 = cur1.Next
		}
		if cur2!=nil {
			s2 = cur2.Val
			cur2 = cur2.Next
		}
		sum:=s1+s2+carry
		node:=&ListNode{sum%10,nil}
		prev.Next = node
		prev = node
		carry = sum/10
	}
	return dummy.Next
}


func init() {
	testList = append(testList,TestEntry{"add two number",func (){
		{
			l1 :=CreateLinkedList([]int{2,4,3}) // slice
			l2 :=CreateLinkedList([]int{5,6,4}) // slice
			var exp = []int{7,0,8}
			ret := LinkedListToArr(addTwoNumbers(l1,l2))
			fmt.Println(reflect.DeepEqual(ret, exp))
		}
	}})

}
