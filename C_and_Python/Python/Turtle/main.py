import turtle
from rectangle import Rectangle
from circle import Circle
from triangle import Triangle
from comparator import Comparator

def main():
    turtle.speed(1)

    rectangle = Rectangle(100, 50)
    rectangle.draw()

    turtle.clear()

    circle = Circle(50)
    circle.draw()

    turtle.clear()

    triangle = Triangle(80, 90, 100)
    triangle.draw()

    turtle.clear()

    comparator = Comparator()
    result = comparator.compare_shapes(rectangle, circle)
    print(result)

    turtle.done()

if __name__ == "__main__":
    main()