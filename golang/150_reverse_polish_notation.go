package main

import "strconv"

func evalRPN(tokens []string) int {
	var stack []int
	for _, s :=range tokens {
		if s=="+" || s=="-" || s=="*" || s=="/" {
			n:=len(stack)
			lhs := stack[n-2]
			rhs := stack[n-1]
			switch (s) {
			case "+":
				stack[n-2] = lhs + rhs
			case "-":
				stack[n-2] = lhs - rhs
			case "*":
				stack[n-2] = lhs * rhs
			case "/":
				stack[n-2] = lhs / rhs
			}
			stack = stack[:n-1]
		} else {
			val,err:=strconv.Atoi(s)
			if err==nil {
				stack = append(stack, val)
			}
		}
	}
	return stack[0]
}

func init() {
	testList = append(testList,TestEntry{"150_reverse_polish_notation",func (){
		{
			tokens :=[]string{"2","1","+","3","*"}
			println(evalRPN(tokens) == 9)
		}
	}})
}
