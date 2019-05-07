package main

import (
	"fmt"
	"time"
)

type Msg struct {
	name string
	id int
}

func test_channel() {
	ch:=make(chan *Msg)
	go func() {
		for x:=0;;x++{
			ch<-&Msg{"test",x}
			time.Sleep(1000*10)
		}
	}()
	for i:=0;;i++ {
		msg:=<-ch
		fmt.Printf("Recv :#%d %s \n",msg.id,msg.name)
	}
}


func init() {
	testList = append(testList, TestEntry{"test channel", func() {
		test_channel()
	}})
}