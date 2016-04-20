class NestedIterator(object):
    def __init__(self, nestedList):
        self._token = self.get_next(nestedList)
        self._cur = None
        self.next()
        
    def get_next(self, nestedList):
        #print '>>', nestedList
        if isinstance(nestedList, list):
            for item in nestedList:
                for subitem in self.get_next(item):
                    yield subitem
        elif nestedList.isInteger():
            yield nestedList.getInteger()
        else:
            for item in nestedList.getList():
                for subitem in self.get_next(item):
                    yield subitem

    def next(self):
        res = self._cur
        try:
            self._cur = self._token.next()
        except StopIteration, e:
            self._cur = None
        return res

    def hasNext(self):
        return self._cur is not None
