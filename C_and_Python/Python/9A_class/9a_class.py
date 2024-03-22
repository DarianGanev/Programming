import datetime

class Student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade

class GradeProcessor:
    def __init__(self, file_path):
        self.file_path = file_path
        self.students = self.read_file()

    def read_file(self):
        students = []
        with open(self.file_path, 'r', encoding='utf-8') as file:
            for line in file:
                parts = line.strip().split()
                name = ' '.join(parts[1:-1])
                grade = float(parts[-1])
                student = Student(name, grade)
                students.append(student)
        return students

    def process_data(self):
        students_with_6 = [student.name for student in self.students if student.grade == 6]
        count_4s = sum(1 for student in self.students if student.grade == 4)
        total_grades = sum(student.grade for student in self.students)
        average_grade = total_grades / len(self.students)
        return students_with_6, count_4s, average_grade

class ResultWriter:
    def __init__(self, result_data):
        self.result_data = result_data

    def write_result_to_file(self):
        with open('result.txt', 'w', encoding='utf-8') as file:
            file.write("Учениците които имат оценка 6 са: {}\n".format(', '.join(self.result_data[0])))
            file.write("Учениците които имат оценка 4 са {} на брой\n".format(self.result_data[1]))
            file.write("Средно аритметичната оценка е: {:.2f}\n".format(self.result_data[2]))
            file.write("Контролното беше трудно!" if self.result_data[2] < 4.50 else "Контролното беше лесно!\n")
            file.write("Дата и час на запис: {}".format(datetime.datetime.now()))

file_path = '9a class.txt'
processor = GradeProcessor(file_path)
result_data = processor.process_data()

writer = ResultWriter(result_data)
writer.write_result_to_file()
