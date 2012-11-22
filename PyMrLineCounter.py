#!/usr/bin/env python
# -*- encoding: utf-8 -*- 
import sys,os

def LineCounter(i_path):
	return open(i_path).read().count('\n')

if(__name__=='__main__'):
	allinall=0
	filesum=0
	for root, dirs, files in os.walk(sys.path[0]):
		for item in files:
			ext=item.split('.')[-1]
			if(ext in ['cc','java','cpp','c','py','cxx','hs']):
				path=root+'/'+item
				if('模版' in path):
					continue
				filesum+=1
				print path
				allinall+=LineCounter(path)
	print "Total problem sloved :",filesum
	print "Total lines of your code :",allinall


'''
#!/usr/bin/env python
#coding: utf-8                                                                                                                                                

import os
import sys


# 好吧其实我现在写这种短代码不太考虑怎么写的好了，不过还是有个人习惯在里面                                                                                    

EXTS = ['cc', 'java', 'cpp', 'c', 'py', 'cxx', 'hs', 'lisp', 'scm', 'el', 'clj']
# EXTS = ['lisp']


def lineCounter(path):
    with open(path, 'r') as fd:
        return len(fd.readlines())


def isCodeFile(string):
    return filter(lambda x : string.endswith(x), EXTS) != []


def main():
    linesum = 0
    filesum = 0
    
    code_path = os.path.join(os.getenv('HOME'), 'workspace', 'ptdk')
    for root, dirs, files in os.walk(code_path):
        code_files = filter(isCodeFile, files)
        code_files_paths = map(lambda x : os.path.join(root, x), code_files)
        non_tpl_code_files_paths = filter(lambda x : '模板' not in x, code_files_paths)
        filesum += len(non_tpl_code_files_paths)

        lines_of_files = map(lineCounter, non_tpl_code_files_paths)
        linesum += sum(lines_of_files)

    print('Total problem solved: ' + str(filesum))
    print('Total lines of your code: ' + str(linesum))


if __name__ == '__main__':
    main()
'''
