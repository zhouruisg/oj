import scala.util.Try
package lc007 {
  object Solution {
    def reverse(x: Int): Int = {
      val rev = x.toString.reverse
      if (x < 0) {
        Try(rev.init.toInt * -1).getOrElse(0)
      } else {
        Try(rev.toInt).getOrElse(0)
      }
      //Try(rev.init.toInt * x.signum).getOrElse(0)
    }
  }
}