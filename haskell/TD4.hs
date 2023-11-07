-- --------------------------------exercice1---------------------------


-- (a) (Bool, Char -> Char)

-- (True, \x -> if x == 'c' then 'f' else 'd')

-- (b) (Bool -> Char, Char)

-- (\x -> if x == True then 'c' else 'd', 'c') 

-- (c) Bool -> Char -> Char

-- \x -> \y -> if x == True || y == 'c' then 'c' else 'd'

-- (d) (Bool -> Char) -> Char

-- \x -> if x(True) == 'c' then 'c' else 'd'




-- ---------------------------exercice2--------------------------------



applyn f x n =
    if n == 0
        then x
    else
        f (rapplyn f x (n-1))


apply f x n =
    if n == 0
        then x
    else
        rapplyn f (f x) (n-1)

 