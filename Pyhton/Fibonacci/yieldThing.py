class Fibonacci:
    def __init__(self, number_of_elements):
        self.number_of_elements = number_of_elements
        self.number0 = 0
        self.number1 = 1

    def run(self):
        for time in range(self.number_of_elements):
            number_0_holder = self.number0

            self.number0 = self.number1
            self.number1 = number_0_holder + self.number1
            yield number_0_holder


tg = Fibonacci(3157).run()
print(tuple(tg))
