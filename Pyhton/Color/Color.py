class Color:
    ''' Handles RGB colors from 0 to 1

        >>> print(Color(1, 0, 0) + Color(0, 0, 1))
        Color(r:1, g:0, b:1)

    '''
    def __init__(self, r, g, b):
        self.r = max(min(1, r), 0)
        self.g = max(min(1, g), 0)
        self.b = max(min(1, b), 0)

    def __add__(self, other):
        return Color(self.r + other.r, self.g + other.g, self.b + other.b)

    def __sub__(self, other):
        return Color(self.r - other.r, self.g - other.g, self.b - other.b)

    def __str__(self):
        return f"Color(r:{self.r}, g:{self.g}, b:{self.b})"

'''
hmmm
    if __name__ == "__main__":
        import doctest
        doctest.testmod()
'''

red = Color(1, 0, 0)
green = Color(0, 1, 0)
blue = Color(0, 0, 1)
purple = Color(1, 0, 1)

print(purple + red)


