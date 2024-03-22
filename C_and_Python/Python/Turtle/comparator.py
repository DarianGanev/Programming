from rectangle import Rectangle
from circle import Circle
from triangle import Triangle

class Comparator:
    @staticmethod
    def compare_shapes(shape1, shape2):
        area1 = shape1.calculate_area() if hasattr(shape1, 'calculate_area') else None
        area2 = shape2.calculate_area() if hasattr(shape2, 'calculate_area') else None

        if area1 is not None and area2 is not None:
            if area1 > area2:
                return "Shape 1 is larger."
            elif area2 > area1:
                return "Shape 2 is larger."
            else:
                return "Shapes are equal in area."
        else:
            return "Cannot compare shapes without area calculation."