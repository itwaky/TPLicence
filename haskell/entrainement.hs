un_seul_chiffre n = (n >= 0 && n <= 10)

somme_chiffre n =
    if un_seul_chiffre n
        then n
    else
        somme_chiffre (n `div` 10) + (n `mod` 10)

est_divisible_par_3 n=
    if n == 0 || n == 3 || n == 6 || n == 9
        then True
    else if un_seul_chiffre n
        then False
    else
        est_divisible_par_3 (somme_chiffre n)


somme_filtre n f=
    if n == 0
        then 0
    else
        (somme_filtre n-1 f)+(if f(n) then n else True)


somme_filtre 6 (\x -> if 6 `mod` x == 0 then True else False)

est_parfait n=
    if somme_filtre 6 (\x -> if 6`mod` x == 0 then True else False) == 2 * n
        then True
    else
        False



