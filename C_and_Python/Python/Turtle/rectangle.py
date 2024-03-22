import turtle
from shape import Shape

class Rectangle(Shape):
    def __init__(self, length, width):
        self.__length = length
        self.__width = width

    def draw(self):
        turtle.begin_fill()
        turtle.color("yellow")  # You can choose any color
        for _ in range(2):
            turtle.forward(self.__length)
            turtle.left(90)
            turtle.forward(self.__width)
            turtle.left(90)
        turtle.end_fill()

        turtle.penup()
        turtle.goto(0, 0)
        turtle.pendown()
        turtle.color("black")
        turtle.write("Area: {}".format(self.__length * self.__width), align="center")


        
