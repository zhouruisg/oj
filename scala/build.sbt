name := "lc_scala"

version := "0.1"

scalaVersion := "2.11.8"

libraryDependencies ++= Seq(
  "org.reflections" % "reflections" % "0.9.9-RC1",
  "com.typesafe.akka" %% "akka-actor" % "2.5.22",
  "com.typesafe.akka" %% "akka-stream" % "2.5.22",
  "com.typesafe.akka" %% "akka-stream-testkit" % "2.5.22" % Test,
  "com.typesafe.akka" %% "akka-http" % "10.1.8",
  "com.typesafe.akka" %% "akka-http-testkit" % "10.1.8" % Test

  
)
