package main

import (
	"fmt"
	"reflect"
	"math"
)

func reverse(x int) int {
	var ret int64 = 0
	for ;x!=0;x=x/10 {
		ret = int64(int(ret*10) + x%10)
	}
	if ret>math.MaxInt32 || ret<math.MinInt32{
		return 0
	} else {
		return int(ret)
	}
}

func init() {
	testList = append(testList,TestEntry{"reversenumber", func(){
		{
			exp := 0
			ret := reverse(1534236469)
			fmt.Println(reflect.DeepEqual(ret, exp))
		}
		{
			exp := -321
			ret := reverse(-123)
			fmt.Println(reflect.DeepEqual(ret, exp))
		}

	}})
}
