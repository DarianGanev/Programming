import turtle
import math
from shape import Shape

class Circle(Shape):
    def __init__(self, radius):
        self.__radius = radius

    def draw(self):
        turtle.penup()
        turtle.goto(0, -self.__radius)
        turtle.pendown()
        turtle.color("red")  # You can choose any color
        turtle.circle(self.__radius)

        turtle.penup()
        turtle.goto(0, 0)
        turtle.pendown()
        turtle.color("black")
        turtle.write("Circumference: {:.2f}".format(2 * math.pi * self.__radius), align="center")