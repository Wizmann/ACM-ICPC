#!/usr/bin/env python
# -*- encoding: utf-8 -*- 
import sys,os
EXTS = set(['cc', 'java', 'cpp', 'c', 'py', 'cxx', 'hs', 'scala', 'scl'])

def LineCounter(i_path):
    with open(i_path) as code_file:
        return code_file.read().count('\n')

if(__name__=='__main__'):
    code_lines,code_files=0,0
    for root, dirs, files in os.walk(sys.path[0]):
        code_list=map(LineCounter,[os.path.join(root,item)\
                for item in files if('模版' not in root and item.split('.')[-1] in EXTS)])
        code_lines+=sum(code_list)
        code_files+=len(code_list)
    print "Total problem sloved :",code_files
    print "Total lines of your code :",code_lines
