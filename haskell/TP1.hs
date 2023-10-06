import Data.Complex

-- ex01


double x = x*2

carre x = x**2





-- ex02

-- a

poly x = 2 + 3*x + 4*x**2 + x**3 + 2*x**4



-- b

-- poly x = let x2 = x**2 in let x3 = x**3 in let x4 == x**4 in 2 + 3 * x + 4 * x2 + x3 + 2 * x4


-- ex03 

joursemaine x = if x==1 then "lundi" else if x==2 then "mardi" else if x==3 then "mercredi" else if x==4 then "jeudi" else if x==5 then "vendredi" else if x==6 then "samedi" else "dimanche"




-- ex04

mois x = if x==1 then "janvier" else if x==2 then "fevrier" else if x==3 then "mars" else if x==4 then "avril" else if x==5 then "mai" else if x==6 then "juin" else if x==7 then "juillet" else if x==8 then "août" else if x==9 then "septembre" else if x==10 then "octobre" else if x==11 then "novembre" else "décembre"


--ex 05

date (jour, nbJour, moi, annee) ="le " ++ joursemaine(jour) ++ " " ++ show(nbJour) ++ " " ++ mois(moi) ++ " " ++ show(annee)



--ex 06

-- a
{-
discriminant (a, b, c) = b**2 - 4 * a * c


-- b



solution a b c = let delta = discriminant(a,b,c) in 
    if delta > 0 
    then let a1 = (-b) - sqrt(delta) in let a2 = 2 * a in let a3 = a1 / a2 in a3 
    else if delta == 0 
        then let a1 = b + sqrt(delta) in let a2 = 2 * a in let a3 = a1 / a2 in a3 
        else "error"

-} 

{-
discriminant a b c = b**2 - 4 * a * c


solution a b c =
    let delta = discriminant a b c
    in if delta > 0
           then let a1 = (-b) - sqrt delta
                    a2 = 2 * a
                    a3 = a1 / a2
                in right (a3, a3 + sqrt delta / a2)
           else if delta == 0
                    then let a1 = b + sqrt delta
                             a2 = 2 * a
                             a3 = a1 / a2
                         in right (a3, a3)
                    else left "Pas de solution réelle"


-}


-- Exercice7 


{-

-- 1


revenuImposable revenuBrut = revenuBrut * 0.72


-- 2

parts_couple situation =
    if situation == "seul"
        then 1
    else if situation == "couple"
        then 2
    else
        error("entré invalide")




parts_enfants nbEnfants = 
    if nbEnfants == 0
        then 0
    else if nbEnfants == 1
        then 0.5
    else
        nbEnfants - 1


parts situation nbEnfants = parts_couple situation + parts_enfants nbEnfants




-- 3




-}





--  Recursivite


-- 1



puissance(x,n) =
    if n == 0
        then 1
    else
        puissance(x,n-1) * x

pgcd(a,b) =
    if b == 0
        then a
    else
        pgcd(b,a `mod` b)

fibonacci(x) =
    if x==0
        then 0
    else if x==1
        then 1
    else
        fibonacci(x-2)+fibonacci(x-1)




exist_diviseur(n,d)=
    if d == n 
        then False
    else if n `mod` d == 0
        then True
    else
        exist_diviseur(n,d + 1)



premier(n)=
    if n <= 1
        then False
    else if exist_diviseur(n,2)
        then False
    else
        True
-- 2

paiement(s,a,b,c,d) = 
    if s == 0
        then True
    else if s>=a && a /=0
        then paiement(s-200,a-1,b,c,d)
    else if s>=b && b /=0
        then paiement(s-100,a,b-1,c,d)
    else if s>=c && c /=0
        then paiement(s-50,a,b,c-1,d)
    else if s>=d && d /=0
        then paiement(s-10,a,b,c,d-1)
    else
        False

-- 3



nb_add_fib(n) = 
    if n == 0 || n == 1
        then 0
    else
        nb_add_fib(n-2) + 1 + nb_add_fib(n-1)


-- 4

my_fib n =
    if n == 0
        then (0,1)
    else
        let (fib, fib1) = my_fib(n-1) in
            (fib1,fib+fib1)


-- 5

total_diviseur(n,nDiv) = 
    if n < nDiv
        then 0
    else if n `mod` nDiv == 0
        then total_diviseur(n, nDiv + 1) + nDiv
    else
        total_diviseur(n, nDiv + 1)


est_parfait n =
    if total_diviseur(n, 1) == 2*n
        then True
    else
        False


-- 6

champernowne(n) =
    if n == 0
        then "0,"
    else 
        champernowne(n-1) ++ show(n)


{- version avec flotant etant pas assez precis
champernowne(n) = 
    if n == 0
        then 0
    else if n > 10
        then champernowne(n-1) + 100 ** (n * ( -1)) * n
    else
        champernowne(n-1) + 10 ** (n * ( -1)) * n

-}



-- 7

erdos n =
    if n == 0
        then "0,"
    else if premier(n)
        then erdos(n-1) ++ show(n)
    else
        erdos(n-1)



