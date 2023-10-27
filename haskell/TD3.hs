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


puissance (n,x) = 
    if n == 0
        then 1
    else
        puissance(n-1, x) * x


-- 5


factoriel (n) = 
    if n == 1 || n == 0
        then 1
    else
        factoriel(n-1)*n

-- 6


sommeK n =
    if n == 0
        then 0
    else
        sommeK(n-1) + n * n

-- 7


carre n =
    if n == 0
        then 0
    else
        carre(n-1) + 2 * (n-1) + 1



-- ---------------------exercice2-------------------------


-- l'entré est un couple 
division(a,b) = 
    if a < b
        then 0
    else
        division(a-b,b) + 1


-- les entré sont 2 arguments
divisionSansCouple a b =
    if a<b
        then 0
    else
        division (a-b) b + 1



reste(a,b) =
    if a < b
        then a
    else
        reste(a-b,b)


nombreChiffre(n) =
    if n<10
        then 1
    else
        nombreChiffre(n`div`10) + 1

renverse(n) = 
    if n < 10
        then n
    else
        renverse(n `div` 10) + (n `mod` 10) * puissance(10, nombreChiffre(n `div` 10))


renverseAux(a,b) = 
    if a == 0
        then b
    else
        renverseAux(a `div` 10,b * 10 + (a `mod` 10))



renverseOpti(n) = renverseAux(n,0)


-- -----------------------exercice3------------------------




exist_diviseur(n,d)=
    if d < 2
        then False
    else if n `mod` d==0
        then True
    else
        exist_diviseur(n,(d-1))


est_premier n =
    if n == 1
        then False
    else if n==2
        then True
    else
        not(exist_diviseur (n, (n-1)))





-- ---------------------exercice4----------------------------



divisionCouple a b =
    if a < b
        then (0,a)
    else
        let (q,r) = divisionCouple(a-b) b in (q+1,r)



-- ----------------exercice5--------------------

chaine_extraite s1 s2 =
    if s1 == ""
        then True else if s2 == "" then False
    else if head s1 == head s2
        then chaine_extraite(tail s1, tail s2)
    else
        chaine_extraite s1, (tail s2)


est_debut s1 s2 =
    if s1 == ""
        then True
    else if s2 == ""
        then False
    else if head s1 == head s2
        then est_debut(tail s1) (tail s2)
    else
        False




est_sous_chaine s1 s2 =
    if s1 == ""
        then True
    else if s2 == ""
        then False
    else if est_debut s1 s2
        then True
    else
        est_sous_chaine s1 (tail s2)










