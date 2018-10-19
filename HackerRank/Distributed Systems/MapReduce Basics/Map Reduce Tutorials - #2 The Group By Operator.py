# This template is based on the framework supplied for a similar challenge, in a Coursera Data Science course: https://www.coursera.org/course/datasci
# And the code supplied here: https://github.com/uwescience/datasci_course_materials/blob/master/assignment3/wordcount.py
import json
import sys
from collections import OrderedDict
class MapReduce:
    def __init__(self):
        self.intermediate = OrderedDict()
        self.result = []
	

    def emitIntermediate(self, key, value):
	self.intermediate.setdefault(key, [])       
        self.intermediate[key].append(value)

    def emit(self, value):
        self.result.append(value) 

    def execute(self, data, mapper, reducer):
	
        for line in data:
            record = json.loads(line)
            mapper(record)

        for key in self.intermediate:
            reducer(key, self.intermediate[key])

        jenc = json.JSONEncoder()
        for item in self.result:
            print "{\"key\":\""+item[0]+"\",\"value\":\"" + str(item[1]) + "\"}"

mapReducer = MapReduce()

def mapper(record):
    key = record["key"]
    value = record["value"]
    mapReducer.emitIntermediate(key, value)

def reducer(key, list_of_values):
    # COMPLETE THE LINE BELOW BY FILLING UP THE QUESTION MARKS 
    mapReducer.emit((key, ','.join(sorted(list_of_values))))


if __name__ == '__main__':
  inputData = []
  counter = 0
  for line in sys.stdin:
   counter += 1
   state, city = line.strip().split("\t")
   inputData.append(json.dumps({"key":state,"value":city}))
  mapReducer.execute(inputData, mapper, reducer)
