

-- Char -> Bool -> Bool

\x -> \y -> if x == 'c' && y == True then True else False


-- (Char -> Bool) -> Bool

\(x,y) -> if x == 'c' && y == True then True else False

-- Char -> Bool -> Char

\x -> \y -> if x == 'c' && y == True then 'b' else 'c'

-- (Char -> Bool) -> (Bool -> Char) -> Char

\(a,b) -> \(c,d) -> if a == 'c' || b == True then 'c' else if c == True || d == 'c' then 'b'