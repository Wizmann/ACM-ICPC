import sys

if(__name__=='__main__'):
    l=raw_input()
    l=l.split()
    r1=int(l[0]);r2=int(l[1]);
    l=raw_input()
    l=l.split()
    c1=int(l[0]);c2=int(l[1]);
    l=raw_input()
    l=l.split()
    d1=int(l[0]);d2=int(l[1]);
    
    a2=(r1-c1+d2)/2
    a1=r1-a2
    a3=c1-a1
    a4=d1-a1
    
    if(a1+a2==r1 and a3+a4==r2 and a1+a3==c1 and a2+a4==c2 and a2+a3==d2 and a1+a4==d1):
        if(a1>0 and a1<10 and a2>0 and a2<10 and a3>0 and a3<10 and a4>0 and a4<10):
            if(a1!=a2 and a1!=a3 and a1!=a4 and a2!=a3 and a2!=a4 and a3!=a4):
                print a1,a2
                print a3,a4
            else:
                print -1
        else:
            print -1
    else:
        print -1
