-- -------------------------Exercice1---------------------

-- 1


fibo n = 
    if n == 0
        then 0
    else if n == 1
        then 1
    else
        fibo(n-2)+fibo(n-1)


-- 2

suiteAri (n,a,r) =
    if n == 0
        then a
    else
        suiteAri(n-1,a,r) + r


-- 3


suiteGeo (n,a,r) = 
    if n == 0
        then a
    else
        suiteGeo(n-1,a,r) * r


-- 4


