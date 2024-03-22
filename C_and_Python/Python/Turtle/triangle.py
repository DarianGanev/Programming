import turtle
from shape import Shape

class Triangle(Shape):
    def __init__(self, side1, side2, side3):
        self.__side1 = side1
        self.__side2 = side2
        self.__side3 = side3

    def draw(self):
        turtle.begin_fill()
        turtle.color("blue")  # You can choose any color
        for _ in range(3):
            turtle.forward(self.__side1)
            turtle.left(120)
        turtle.end_fill()

        turtle.penup()
        turtle.goto(0, 0)
        turtle.pendown()
        turtle.color("black")

        if self.__side1 > (self.__side2 + self.__side3):
            turtle.write("Larger: {}".format(self.__side1), align="center")
        elif self.__side2 > (self.__side1 + self.__side3):
            turtle.write("Larger: {}".format(self.__side2), align="center")
        elif self.__side3 > (self.__side1 + self.__side2):
            turtle.write("Larger: {}".format(self.__side3), align="center")
        else:
            turtle.write("Equal", align="center")
