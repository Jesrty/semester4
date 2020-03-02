def recursive_fib(num_elements):
    if num_elements == 1:
        return 0
    elif num_elements == 2:
        return 1
    else:
        return recursive_fib(num_elements-2) + recursive_fib(num_elements -1)


def gen_fib():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


if __name__ == '__main__':
    print(recursive_fib(35))
    gf = gen_fib()
    for i in range(35):
        print(next(gf))
