package myakka.manyactor {

  import akka.actor.Actor
  import akka.actor.ActorSystem
  import akka.actor.Props
  import scala.concurrent._ // future
  import duration._ // seconds
  import akka.pattern._ // gracefulStop

  class HelloActor extends Actor {
    def receive: Actor.Receive = {
      case "hello" => println("hello back to you.")
      case HelloActor.ActorStop =>
        context.stop(self)
      case _ => println("huh?")
    }
  }

  object HelloActor {

    case object ActorStop

  }


  object HelloMain extends App {

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

}