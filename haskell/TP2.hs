-- -----------------------------------exercice1-----------------------




-- Char -> Bool -> Bool

-- \x -> \y -> if x == 'c' && y == True then True else False


-- (Char -> Bool) -> Bool

-- \x -> if x('c') == True then True else False


-- Char -> Bool -> Char

-- \x -> \y -> if x == 'c' && y == True then 'b' else 'c'


-- (Char -> Bool) -> (Bool -> Char) -> Char


-- \x -> \y -> if x('x') == True then if y(True) == 'c' then 'c' else 'b' else 'b'




-- -------------------------------exercice2-------------------------------------


----a

f = \x -> 2*x**2+1

g = \x -> cos x

derivee f x = let h = 0.0000001 in (f (x + h) - f x) / h

compose g f x = g(f x)

----b

-- derivee (compose g f) 2

----c

-- (derivee f 2) * (compose (derivee g) f 2)


----d

verif xmin xmax h =
    if xmin > xmax
        then True
    else if (not(abs((derivee (compose g f) xmin) - ((derivee f xmin) * (compose (derivee g) f xmin))) < 0.001))
        then False
    else
        verif (xmin + h) xmax h


-- --------------------------exercice3----------------------


sigma f n =
    if n == 0
        then f(n)
    else
        sigma f (n-1) + f(n)


-- ----------------------exercice4----------------------


inv100 x = sigma (\n -> (1-x)**n) 100 















