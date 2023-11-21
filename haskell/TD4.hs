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

-- pas au tp

-- 1

applyn f x n =
    if n == 0
        then x
    else
        f (applyn f x (n-1))


apply f x n =
    if n == 0
        then x
    else
        apply f (f x) (n-1)


-- 2

puiss x n = applyn (\y -> y*x) 1 n


-- 3

sigma u p =
    if p == 0
        then u p -- ou u 0
    else
        u (p-1) + u p

-- 4

inv100 x = sigma (\k -> puiss (1-x) k) 100


-- -------------------------exercice3-------------------

-- 5

suite_rec f u0 = \n -> if n==0 then u0 else f (suite_rec f u0) (n-1)

-- ou

-- suite_rec f u0 n =
--     if n==0
--         then u0
--     else
--         f(suite_rec f u0 (n-1))

-- pareil que applyn

suite_rec = applyn


-- 6


suite_arith r u0 = suite_rec (\x -> x + r) u0 

-- suite_arith r u0 = suite_rec (\x -> x + r) u0

-- 7

suite_geo q u0 = suite_rec (\x -> x * q) u0


-- 8

nb_pair = suite_arith 2 1


-- 9

puissance2 = suite_geo 2 2



-- ------------------------exercice4-------------------------------


-- 10

-- le type de t est inconu donc on utilise une inconu

num a => (t->t)->t->a->t


-- 11

curry2 f = \x -> \y -> f(x,y)


((t1->t2)->t)->t1->t2->t



