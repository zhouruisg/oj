package rz.codech

import scala.collection.mutable
import scala.collection.mutable.ListBuffer
import org.reflections.Reflections
import scala.collection.JavaConversions._

//https://github.com/wqlin/LeetCode/blob/master/src/ListNode.scala
// https://github.com/XD-DENG/leetcode-scala/tree/master/src
object MainScala {
  private val initCode = new ListBuffer[() => Unit]
  private val entries = new mutable.HashMap[String,() => Unit]

//  def extensions: List[rz.codech.BaseExtension] = {
//    val reflections = new Reflections("org.reflections_example.extension")
//    val subclasses = reflections.getSubTypesOf(classOf[rz.codech.BaseExtension])
//    subclasses.toList.map { x => x.getDeclaredConstructors()(0).newInstance().asInstanceOf[rz.codech.BaseExtension] }
//  }

//  def scan(): Unit = {
//    import org.reflections.Reflections
//    val ref = new Reflections("my.path")
//    val set = ref.getTypesAnnotatedWith(classOf[Nothing])
//
////    Reflections ref = new Reflections("my.path");
////    Set<Class<?>> set = ref.getTypesAnnotatedWith(MyAnnotation.class);
////    Reflections reflections = new Reflections("my.project.prefix");
////    Set<Class<?>> annotated = reflections.getTypesAnnotatedWith(Controller.class);
////
////    for (Class<?> controller : annotated) {
////      RequestMapping request = controller.getAnnotation(RequestMapping.class);
////      String mapping = request.name();
////    }
//  }



  def extensions: List[BaseExtension] = {
    val reflections = new Reflections("rz.leetcode")
    val subclasses = reflections.getSubTypesOf(classOf[BaseExtension])
    subclasses.toList.map { x => x.getDeclaredConstructors()(0).newInstance().asInstanceOf[BaseExtension] }
  }

  def main(args: Array[String]): Unit = {
    println("Started")
    extensions.foreach(println)  // apply println to each element, no sideeffect

    //println("Hello, world!Please input test No#")
    // list
//    val func = lc001.Test.entry()
//    initCode += (()=>func)
//    for (proc <- initCode) proc()
//
//    // hashmap
//    entries += ("twosum" -> (()=>func))
//    for ((name, proc)<-entries) {
//      println(s"executing $name")
//      proc()
//    }


    //val a=scala.io.StdIn.readInt()
    //println("The value of a is "+ a)


    //lc001.Test.entry()
  }
}
