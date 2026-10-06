class Spreadsheet(object):
    def __init__(self, rows):
        pass

    def setCell(self, cell, value):
        setattr(self, cell, value)

    def resetCell(self, cell):
        setattr(self, cell, 0)
        

    def getValue(self, formula):
        var1, var2 = formula[1:].split('+')
        var1 = int(var1) if var1.isdigit() else getattr(self, var1, 0)
        var2 = int(var2) if var2.isdigit() else getattr(self, var2, 0)
        return var1 + var2
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
