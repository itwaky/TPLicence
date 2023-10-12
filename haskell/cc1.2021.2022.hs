-- -------------------------exercie1------------------


oteDers m n = 
    if m == 0
        then n
    else
        oteDers (m-1) (n `div` 10)



-- ---------------------------exercice2-----------------

nbDers c n =
    if (n `mod` 10) /= c
        then 0
    else
        nbDers c (n `div` 10) + 1

-- ----------------------------exercice3--------------------

conwaySuiv n = 
    if n == 0
        then 0
    else
        let a = n `mod` 10 in
        let b = nbDers a n in
        let suiv = oteDers b n in
        let c = b * 10 + a in conwaySuiv suiv * 100 + c

-- -------------------------exercice4------------------------


conwayNieme n =
    if n == 1
        then 1
    else
        conwaySuiv (conwayNieme (n-1))