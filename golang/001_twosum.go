package main

import (
	"reflect"
	"fmt"
)

func init() {
	//testm["twosum"] = func() []int  {
	//	return twoSum([]int{2, 7, 11, 15},9)
	//}
	//
	//testarr = append(testarr,
	//	&TestInfo{"twosum",func() bool  {
	//		var ret = twoSum([]int{2, 7, 11, 15},9)
	//		var exp = []int{0,1}
	//		return reflect.DeepEqual(ret, exp)
	//		//return ret == exp
	//	}})

	testList = append(testList,TestEntry{"twosum",func (){
		fmt.Println("execute two sum test")
		{
			var ret = twoSum([]int{2, 7, 11, 15},9)
			var exp = []int{0,1}
			fmt.Println(reflect.DeepEqual(ret, exp))
		}
	}})


	//testList = append(testList,
	//	&TestInfo{"twosum",func() bool  {
	//		var ret = twoSum([]int{2, 7, 11, 15},9)
	//		var exp = []int{0,1}
	//		return reflect.DeepEqual(ret, exp)
	//		//return ret == exp
	//	}})

	//var testInfo TestInfo
	//testInfo.name="twosum"
	//testInfo.entry = func() []int{
	//	return twoSum([]int{2, 7, 11, 15}, 9)
	//}

	//fmt.Printf(testInfo.name)

}


func twoSum(nums []int, target int) []int {
	tmpMap := make(map[int]int)
	for i, num := range nums {
		if _, ok := tmpMap[target-num]; ok {
			return []int{tmpMap[target-num], i}
		}
		tmpMap[num] = i
	}
	return []int{}
}



//var _ int64 = a()
//func init() {
//	fmt.Println("init in a.go")
//}
//func a() int64 {
//	fmt.Println("calling a() in a.go")
//	return 2
//}