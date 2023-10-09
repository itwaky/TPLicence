-- ---------------------------------------exercice1--------------------------------------


un_seul_chiffre n = (n>=0 && n<=10)

somme_chiffre n =
    if un_seul_chiffre(n)
        then n
    else
        somme_chiffre(n `div` 10) + n `mod` 10


est_divisible_par_3 n =
    if n==0 || n == 3 || n == 6 || n == 9
        then True
    else if un_seul_chiffre n
        then False
    else
        est_divisible_par_3(somme_chiffre(n))



-- ---------------------------exercice2-----------------------------------


mult a b =
    if b == 0
        then 1
    else if b `mod` 2 == 0
        then (2*a)*(b`div`2) + mult a (b-1)
    else
        mult a (b-1)



-- ---------------------Exercice3----------------------


