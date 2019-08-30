package myakka


//import akka.actor.Actor
//import akka.actor.ActorSystem
//import akka.stream._
//import akka.stream.scaladsl._
//import akka.actor
//import akka.actor.Props
//import scala.concurrent._ // future
//import duration._ // seconds
//import akka.pattern._ // gracefulStop
//
//object Application {
//  implicit val system: ActorSystem = ActorSystem("http-slow-server")
//  implicit val mat: ActorMaterializer = ActorMaterializer()
//  import system.dispatcher
//
//  def main(args: Array[String]): Unit = {
//    val route = extractUri { uri =>
//      onSuccess(slowOp(uri)) {
//        complete(StatusCodes.NoContent)
//      }
//    }
//
//    val binding = Http().bindAndHandle(route, "0.0.0.0", 4000)
//    println("Server online at http://0.0.0.0:4000/")
//    StdIn.readLine()
//    binding.flatMap(_.unbind()).onComplete(_ => system.terminate())
//  }
//
//  def slowOp(requestUri: Uri): Future[Unit] = Future {
//    blocking {
//      println(s"[${LocalDateTime.now}] --> ${requestUri.authority.host}")
//      Thread.sleep(5000)
//    }
//  }
//}
