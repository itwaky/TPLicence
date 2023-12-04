
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

-- let f(x) = 3*x*x+1 in let g(x) = sin(x) in let x=2 in (derivee f x)+(derivee g x)


-- let f(x) = 3*x*x+1 in let g(x) = sin(x) in let x=2 in derivee (somme f g) x

prod u n = if n==0 then u 0 else prod u (n-1)*u n

facto n = prod (\n->if n==0 then 1 else n) n


-- ---------------------------------3.type de liste


app l e = case l of {
     [] -> False;
     h:t -> if h == e
                then True
            else
                app t e
}



union l1 l2 = case l1 of {
    [] -> l2;
    h:t ->  if app l2 h
                then union t l2
            else
                h:union t l2
}


valide l = case l of {
    [] -> True;
    h:t ->  if app t h
                then False
            else
                valide t
}
