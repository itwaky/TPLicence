#--------------------------------1


def suiteGeom(n,q,u0):
    if n == 0:
        return u0
    else:
        return suiteGeom(n-1,q, u0) * q


print(suiteGeom(4,3,4))


#---------------------------------2

def sommeUnSurNCarre(n):
    if n == 0:
        return 0
    else:
        return sommeUnSurNCarre(n-1) + 1/(n * n)


print(sommeUnSurNCarre(900))



#--------------------------------3
