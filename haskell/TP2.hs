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



