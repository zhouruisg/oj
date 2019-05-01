package main

import (
	"bufio"
	"container/list"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

//type Solution interface {
//}
//
//type TestInfo struct {
//	name string
//	entry interface{}
//}

type TestEntry struct {
	name string
	callback func()
}

//type TestCommand interface {
//	execTest() bool
//}



var (
	//testm = make(map[string]Solution)
	//testarr []*TestInfo
	testList []TestEntry
)

// --------- LIST ---------------------------
type ListNode struct {
	Val int
	Next *ListNode
}

func CreateLinkedList(lst []int) *ListNode{
	dummy := ListNode{0,nil}
	prev := &dummy
	for _,v:=range lst {
		prev.Next = &ListNode{v, nil}
		prev = prev.Next
	}
	return dummy.Next
}

func LinkedListToArr(head *ListNode) []int {
	var ret []int
	for ;head!=nil;head = head.Next {
		ret = append(ret, head.Val)
	}
	return ret
}

// --------- TREE ---------------------------

var (
	null = math.MaxInt32
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func CreateTree(lst []int) *TreeNode {
	if len(lst)==0 {
		return nil
	}

	queue := list.New()
	root:=&TreeNode{lst[0],nil,nil}
	queue.PushBack(root)

	idx:=0
	for queue.Len() > 0 {
		element := queue.Front()
		parent, ok:=interface{}(element.Value).(*TreeNode)
		queue.Remove(element)

		if !ok {
			break
		}

		idx++
		if idx<len(lst) {
			val:= lst[idx];
			if val != null {
				parent.Left = &TreeNode{val,nil,nil}
				queue.PushBack(parent.Left)
			}
		} else {
			break
		}

		idx++
		if idx<len(lst) {
			val := lst[idx]
			if val != null {
				parent.Right = &TreeNode{val,nil,nil}
				queue.PushBack(parent.Right)
			}
		} else {
			break
		}
	}
	return root
}
/*
TreeNode *root = new TreeNode(list[0]);
        std::deque<TreeNode*> toDo{root};

        //for (size_t i=0; i < list.size(); i++) {
        int idx = 0;
        while (!toDo.empty()) {
            TreeNode *parent = toDo.front();
            toDo.pop_front();
            idx++;
            int v1 = list[idx];
            if (v1 != null) {
                parent->left = new TreeNode(v1);
                toDo.push_back(parent->left);
            } else {
                parent->left = nullptr;
            }


            idx++;
            int v2 = list[idx];
            if (v2 != null) {
                parent->right = new TreeNode(v2);
                toDo.push_back(parent->right);
            } else {
                parent->right = nullptr;
            }

        }
        return root;
 */
// --------- TREE ---------------------------



func main() {
	fmt.Println("Hello World LeetCode Golang")
	fmt.Println("---------------------")

	//for idx, pr := range testarr {
	//	fmt.Printf("%d%s%20s",idx, "..........", pr.name)
	//}
	//readText, err := ioutil.ReadAll(os.Stdin)
	//if err != nil {
	//	log.Fatalf("failed to read stdin: %s", err)
	//}
	//fmt.Printf("\nLength: %d", len(readText))
	//fmt.Printf("\nData Read: \n%s", readText)
	//var container = []string{"zero","one","two"}
	for idx, pr := range testList {
		fmt.Printf("%d%s%-30s\n",idx, "..........", pr.name,)
		//container :=map[int]string{0:"zero",1:"one",2:"twp"}
		//fmt.Printf("element value is %q",container[1])
	}
	//fmt.Printf("outter element value is %q",container[1])

	//testList[1].callback()
	reader := bufio.NewReader(os.Stdin)
	idxStr, err:=reader.ReadString('\n')
	idxStr = strings.TrimSuffix(idxStr, "\n")
	if err!=nil {
		fmt.Println(err)
	}
	idx, err := strconv.Atoi(idxStr)
	if err != nil {
		panic(err) //should not happen
	} else {
		//delete(mq.usingPorts, uint32(p))
		fmt.Println(testList[idx].name)
		testList[idx].callback()
	}




	//for key, value := range testm{
	//	fmt.Println(key,value)
	//}
}
