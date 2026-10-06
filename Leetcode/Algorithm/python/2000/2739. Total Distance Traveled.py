#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution(object):
    def distanceTraveled(self, mainTank, additionalTank):
        fuel = 0
        while mainTank >= 5:
            fuel += 5
            mainTank -= 5
            if additionalTank:
                mainTank += 1
                additionalTank -= 1
        return (fuel + mainTank) * 10


'''
^^^^TEST^^^^^
5
10
---------
60
$$$$TEST$$$$

^^^^TEST^^^^^
1
2
---------
10
$$$$TEST$$$$

^^^^TEST^^^^^
9
2
---------
110
$$$$TEST$$$$


'''

