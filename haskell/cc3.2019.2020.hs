

---------1


twice f = \x -> f(f(x))

---20


------2

puiss4 x = twice (\y -> y*y) x


------3


tous_distincts list = case list of{
    h:t ->      if elem h t
                    then False
                else
                    tous_distincts t;
    [] -> True
}




-------4

tous_egaux l = case l of{
    [] ->   True;
    [t] ->  True;
    h:t ->  if elem h t
                then tous_egaux t
            else
                False
}






-------5

foldright f b l = case l of {
    [] -> b;
    t:r -> f t (foldright f b r)
}


-------6


myelem x l = foldright (\t p -> (p || t==x)) False l




--------7


-- bool -> (bool -> char) -> char



-- (t1 -> t) -> t1 -> t







----------8

data Image =Noir
            | Blanc
            | Composite (Image, Image, Image, Image)
            deriving (Show, Eq)

-- l’image en haut à droite, en bas à droite, en bas à gauche et en haut à gauche, dans cet ordre)


-- (Composite (Composite (Blanc,Blanc,Blanc,Blanc),Composite (Noir,Noir,Noir,Noir), Composite (Blanc,Blanc,Blanc,Blanc), Composite (Noir,Noir,Noir,Blanc)))

-- (Composite (Blanc, Noir, Blanc, Composite (Noir, Noir, Noir, Blanc)))


----------9

pourcent_blanc i = case i of{
    Blanc -> 100.0;
    Noir -> 0;
    Composite(a1,a2,a3,a4) -> ((pourcent_blanc a1) + (pourcent_blanc a2) + (pourcent_blanc a3) + (pourcent_blanc a4))/4
}



-----------10

sym_diag i = case i of{
    Noir -> True;
    Blanc -> True;
    Composite (a1,a2,a3,a4) ->  let test = (a1 == a3) in (sym_diag a1) && (sym_diag a2) && (sym_diag a3) && (sym_diag a4) && test
}