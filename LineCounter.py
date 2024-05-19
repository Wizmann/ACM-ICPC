#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import sys
import os

EXTS = set([
    'cc', 'cpp', 'c', 'cxx',
    'java',
    'js',
    'py',
    'php',
    'hs',
    'scala', 'scl',
    'erl',
    'cs',
    'sh',
    'go',
    'fs',
    'sql',
    'swift'])


def LineCounter(i_path):
    with open(i_path) as code_file:
        return code_file.read().count('\n')

if(__name__ == '__main__'):
    code_lines, code_files = 0, 0
    for root, dirs, files in os.walk(sys.path[0]):
        code_list = map(LineCounter, [
            os.path.join(root, item) 
            for item in files 
                if('Exemplars' not in root 
                    and 'utils' not in root
                    and 'Note' not in root
                    and item.split('.')[-1] in EXTS)
            ]
        )
        code_lines += sum(code_list)
        code_files += len(code_list)
    print "Total problems solved :", code_files
    print "Total lines of your code :", code_lines
