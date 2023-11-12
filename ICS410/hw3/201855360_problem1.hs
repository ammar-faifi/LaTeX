neighborMax :: [Int] -> [Int]
neighborMax [] = []
neighborMax [_] = []
neighborMax [_, _] = []
neighborMax (x:y:z:rest)
    | y > x && y > z = y : neighborMax (y:z:rest)
    | otherwise = neighborMax (y:z:rest)

main = do
    print $ neighborMax [2,9,5,6,1]
    print $ neighborMax [2,3,4,1,5]
    print $ neighborMax [1,2,3,4,5]
