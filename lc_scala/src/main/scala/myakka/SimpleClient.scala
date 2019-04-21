package myakka

package com.eleansa.spike

import akka.actor.ActorSystem
import akka.util.ByteString

import scala.concurrent.{Await, Future}
import akka.stream.ActorMaterializer
import akka.http.scaladsl.model._
import akka.http.scaladsl.Http
import scala.concurrent.duration._

object SpikeAkkaHttpClient extends App {

  implicit val system = ActorSystem()
  implicit val materializer = ActorMaterializer()

  val responseFuture: Future[HttpResponse] =
    Http().singleRequest(HttpRequest(uri = "http://www.zhihu.com"))

  import system.dispatcher

  val response = Await.result(responseFuture, 5.seconds)

  response.entity.dataBytes.runFold(ByteString.empty)(_ ++ _).map(_.utf8String).foreach(println)

  Http().shutdownAllConnectionPools().onComplete(_ => system.terminate())
}
