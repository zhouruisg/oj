package main

import (
	"bufio"
	"fmt"
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

type ListNode struct {
	Val int
	Next *ListNode
}


var (
	//testm = make(map[string]Solution)
	//testarr []*TestInfo
	testList []TestEntry
)

func CreateLinkedList(lst []int) *ListNode{
	dummy := ListNode{0,nil}
	prev := &dummy
	for v:=range lst {
		prev.Next = &ListNode{v, nil}
		prev = prev.Next
	}
	return dummy.Next
}
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

	for idx, pr := range testList {
		fmt.Printf("%d%s%20s\n",idx, "..........", pr.name)
	}

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
