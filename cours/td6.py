import math

#-----------1


def facto(n):
    if n ==0:
        return 1
    return n * facto(n-1)

print(facto(4))


#-------------2


def suite_arith(n,u0,r):
    if n == 0:
        return u0
    else:
        return suite_arith(n-1,u0,r)+r

print(suite_arith(10,23,4))


#------------------3


def mult(a,b):
    if b == 0:
        return 0
    else:
        return a + mult(a,b-1)


print(mult(2,100))



#----------------------4

def sommeNPremierEntier(n):
    if n == 0:
        return 0
    else:
        return n + sommeNPremierEntier(n-1)


print(sommeNPremierEntier(10))


#-------------------5


def sommeNPremierEntierImpair(n):
    if n == 0:
        return 0
    return ((2*n-1) + sommeNPremierEntierImpair(n-1))


print(sommeNPremierEntierImpair(4))


#-----------------------6


def audia_rec(n,p,x):
    if x>p:
        return False
    elif n%x == 0:
        return True
    else:
        return audia_rec(n,p,x+1)

def a_un_diviseur_inferieur_a(n,p):
    return audia_rec(n,p,2)


print(a_un_diviseur_inferieur_a(1024,3))
print(a_un_diviseur_inferieur_a(1025,3))


#------------------------7


def est_premier(n):
    return not a_un_diviseur_inferieur_a(n,math.sqrt(n))


print(est_premier(17))


#----------------------8
