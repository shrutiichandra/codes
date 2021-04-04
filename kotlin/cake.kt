fun main() {
    val age = 5
    printCake()
    println("Happy Birthdayy!")
    println("You are ${age}!")
    println("Yayya")
}
fun printCake() {
    println("   ,,;;,   ")
    println("   |||||   ")
    printBorder(11, "=")
    println("|@@@@@@@@@|")
    println("|~@~@~@~@~|")
    println("|@@@@@@@@@|")
	printBorder(11, "-")
}

fun printBorder(times: Int, sym: String) {
    repeat(times) {
        print(sym)
    }
    println()
}