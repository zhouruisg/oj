object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val m = nums.zipWithIndex.groupBy(_._1) //=> it is a collection,map(item:idx)
    nums.zipWithIndex.withFilter(pair => {
      val diff = target - pair._1
      m.contains(diff) && m(diff).exists(_._2 != pair._2)
    }).map(_._2)
  }
}

object Solution1 {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val map = scala.collection.mutable.HashMap[Int,Int]()
    var ret:Array[Int] = Array(0,0)
    var i=0
    for (i <- 0 until nums.length) {
      val complement = target - nums(i)
      if (map.contains(complement)) {
        ret(0) = map(complement)
        ret(1) = i
      } else {
        map(nums(i)) = i
      }
    }
    ret
  }
}

object Test {
  def main(args:Array[String]){
    //println("HelloWorld")
    val arr=Array(2,7,11,15)
    println(Solution.twoSum(arr,9).deep == Array(0,1).deep)
    println(Solution1.twoSum(arr,9).deep == Array(0,1).deep)
  }
}
