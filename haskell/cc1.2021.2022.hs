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
    if n == 1
        then 11
    else
        let a = n `mod` 10 in
        let b = nbDers a n in
        let c = 