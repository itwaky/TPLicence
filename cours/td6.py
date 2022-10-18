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


def est_pair(n):
    if n == 0:
        return True
    elif n == 1:
        return False
    else:
        return est_pair(n-2)


print(est_pair(13))



def est_divisible_par(n, b):
    if n == 0:
        return True
    elif n<0:
        return False
    else:
        return est_divisible_par(n-b,b)



print(est_divisible_par(20,3))



def quotientDivision(n,b):
    if b > n:
        return 0
    else:
        return quotientDivision(n-b,b)+1


print(quotientDivision(55,10))


def nbChiffres(n):
    if n==0:
        return 0
    else:
        return nbChiffres(n//10)+1


print(nbChiffres(1334))


def ordreDeGrandeur(n):
    if n<10:
        return 1
    else:
        return 10 * ordreDeGrandeur(n//10)

print(ordreDeGrandeur(4567))



def fibo_iter(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        return fibo_iter(n-1)+fibo_iter(n-2)


print(fibo_iter(6))
