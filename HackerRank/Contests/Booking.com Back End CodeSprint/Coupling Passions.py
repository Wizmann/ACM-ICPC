import math
import sys

from math import sin, cos, pi, acos

def degree2radians(degrees):
    return degrees * (pi / 180.0);

def distance(point1, point2):
    EARTH_RADIUS = 6371
    point1_lat_in_radians  = degree2radians( point1.latitude );
    point2_lat_in_radians  = degree2radians( point2.latitude );
    point1_long_in_radians  = degree2radians( point1.longitude );
    point2_long_in_radians  = degree2radians( point2.longitude );

    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;

class City(object):
    def __init__(self, name, lang, lat, passions):
        self.name = name
        self.longitude = float(lang)
        self.latitude = float(lat)
        self.passions = passions

n = int(raw_input())
passions = set()

for i in xrange(n):
    ps = raw_input().split()[1:]
    passions |= set(ps)
    
m = int(raw_input())
cities = []
for i in xrange(m):
    fields = raw_input().split()
    name, lang, lat = fields[0], fields[1], fields[2]
    ps = fields[4:]
    cities.append(City(name, lang, lat, ps))

ans = ()
dis = 1e100
np = -1
for c1 in cities:
    for c2 in cities:
        if c1.name == c2.name:
            continue
        p = set(c1.passions + c2.passions) & passions
        d = distance(c1, c2)
        if len(p) > np:
            ans = (c1.name, c2.name)
            dis = d
            np = len(p)
        if len(p) == np and d < dis:
            ans = (c1.name, c2.name)
            dis = d

print ' '.join(sorted(list(ans)))
            
        
        
