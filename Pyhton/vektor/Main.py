import math


class Vektor:
    """
    >>> v1 = Vektor(2, 4)
    >>> v2 = Vektor(2, 1)
    >>> v1 + v2
    Vektor(4, 5)

    >>> v = Vektor(3,4)
    >>> abs(v)
    5.0

    >>> v * 3
    Vektor(9, 12)
    >>> abs(v * 3)
    15.0

    >>> True if Vektor(0, 0) else False
    False
    >>> True if Vektor(1, 0) else False
    True
    """
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return str(self)

    def __bool__(self):
        return bool(abs(self))

    def __str__(self):
        myString = "Vektor({}, {})".format(self.x, self.y)
        return myString

    def __add__(self, other):
        totalx = self.x + other.x
        totaly = self.y + other.y
        return Vektor(totalx, totaly)

    def __mul__(self, number):
        totalx = self.x * number
        totaly = self.y * number
        return Vektor(totalx, totaly)

    def __abs__(self):
        test = math.sqrt(self.x * self.x + self.y * self.y)
        return test


if __name__ == "__Main__":
    import doctest
    doctest.testmod()




"""
v1 = Vektor(2, 4)
v2 = Vektor(2, 1)
v3 = (v1 + v2) * 2
print(v3)
v4 = Vektor(3, 4)
print(abs(v4))
print(abs(v4 * 3))
"""


