class Person:
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber
    def printPerson(self):
        print "Name:", self.lastName + ",", self.firstName
        print "ID:", self.idNumber
        
class Student(Person):
    def __init__(self, firstName, lastName, idNumber, scores):
        self.scores = scores
        Person.__init__(self, firstName, lastName, idNumber)
        
    def calculate(self):
        ave = 1.0 * sum(self.scores) / len(self.scores)
        if ave >= 90:
            return 'O'
        elif ave >= 80:
            return 'E'
        elif ave >= 70:
            return 'A'
        elif ave >= 55:
            return 'P'
        elif ave >= 40:
            return 'D'
        else:
            return 'T'
        
line = raw_input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(raw_input()) # not needed for Python
scores = map(int, raw_input().split())
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print "Grade:", s.calculate()
