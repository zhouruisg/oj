package myakka


import akka.actor.Actor
import akka.actor.ActorSystem
import akka.actor.Props
import akka.pattern.gracefulStop
//import myakka.manyactor.HelloActor
import scala.concurrent._ // future
import duration._ // seconds
import akka.pattern._ // gracefulStop


import scala.concurrent.{Await, Future}

class HelloActor extends Actor {
  def receive = {
    case "hello" => println(Thread.currentThread() + "hey")
    case _       => println("huh?")
  }
}

object HelloActor {
  case object ActorStop
}

object Main extends App {
  val system = ActorSystem("HelloSystem")
  // 缺省的Actor构造函数
  val helloActor = system.actorOf(Props[HelloActor], name = "helloactor")
  helloActor ! "hello"
  helloActor ! "喂"
}



object Main2 extends App {

  // actor need an ActorSystem
  val system = ActorSystem("HelloSystem")
  // create and start the actor
  //println(system.dispatchers.settings)
  val helloActor = system.actorOf(Props[HelloActor], name = "helloActor")

  for (i <- 1 to 10) {
    // send two messages
    helloActor ! "hello"
    helloActor ! "hello"
    helloActor ! "hello"
    helloActor ! "what"
    helloActor ! "what"
    helloActor ! "what"
  }

  // try to stop the actor graceful
  // shutdown the actor system
  try {
    val stopped: Future[Boolean] = gracefulStop(helloActor, 2 seconds, HelloActor.ActorStop)
    Await.result(stopped, 3 seconds)
    println("testActor was stopped")
  } catch {
    case e: akka.pattern.AskTimeoutException => e.printStackTrace
  } finally {
    system.terminate()
  }
}