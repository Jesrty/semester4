class Fibonacci:
    def __init__(self, number):
        self.number = number
        self.number0 = 0
        self.number1 = 1

    def run(self):
        if self.number >= self.number0:
            number_0_holder = self.number0

            self.number0 = self.number1
            self.number1 = number_0_holder + self.number1
            print(number_0_holder)
            self.run()


#fib = Fibonacci(145)
#fib.run()

Fibonacci(173402521172797813159685037284371942044301).run()
