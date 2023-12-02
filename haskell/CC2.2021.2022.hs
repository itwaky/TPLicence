
-- ---------------------------1.interference de type


-- Bool -> t -> t
-- :t \x -> \y -> if x then y  else y



-- (Bool -> t) -> t
-- :t \x -> x(True)


-- (Char, t) -> Bool
-- :t \(x,y) -> if x == 'y' then True else False


-- (Char, t -> Bool)
-- :t ('c', \x -> True)



-- --------------------------------2.fonctionnelle d'ordre sup


derivee f x = let h = 0.00000001 in (f (x+h) - f x) / h

compose f g x = f(g x)

somme f g = \x -> f x + g x


