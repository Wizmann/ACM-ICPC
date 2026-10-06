class File(object):
    def __init__(self, name, content=""):
        self.name = name
        self.content = content
        
class Directory(object):
    def __init__(self, name):
        self.name = name
        self.subdir = {}

class FileSystem(object):
    def __init__(self):
        self.root = Directory("")
        
    def find_path(self, path, create=False, file_content=None):
        if path == '/':
            return self.root
            
        path = filter(lambda x: x, path.split("/"))
        cur = self.root
        for i, item in enumerate(path):
            if item in cur.subdir:
                cur = cur.subdir[item]
            elif create == False:
                return None
            elif i == len(path) - 1 and file_content != None:
                cur.subdir[item] = File(item, file_content)
                cur = cur.subdir[item]
            else:
                cur.subdir[item] = Directory(item)
                cur = cur.subdir[item]
                
        return cur

    def ls(self, path):
        cur = self.find_path(path)

        if cur == None:
            return []
        if isinstance(cur, File):
            return [cur.name]
        else:
            return self.ls_dir(cur)
        
    def ls_dir(self, directory):
        return sorted(directory.subdir.keys())

    def mkdir(self, path):
        self.find_path(path, True)


    def addContentToFile(self, filePath, content):
        cur = self.find_path(filePath)
        if cur == None:
            self.find_path(filePath, True, content)
        else:
            cur.content += content
        

    def readContentFromFile(self, filePath):
        cur = self.find_path(filePath)
        if cur:
            return cur.content
        else:
            return ""
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
