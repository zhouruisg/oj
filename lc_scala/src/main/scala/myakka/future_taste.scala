package myakka

import scala.concurrent.Future
import scala.concurrent.ExecutionContext.Implicits.global

object Futuretaste extends App {
  def sleep(millis:Long) = {
    Thread.sleep(millis)
  }
  def doWork(index:Int) = {
    println(Thread.currentThread() + s"$index")
    sleep((math.random * 1000).toLong)
    index
  }

  (1 to 5) foreach {
    index=>{
      val future = Future {doWork(index)}
      future onSuccess {
        case answer:Int=>println(s"Success! returned:$answer")
      }
      future onFailure {
        case th:Throwable =>println(s"FAILURE! returned:$th")
      }
    }
  }
  sleep(1000)
  println("Finito!")

}
