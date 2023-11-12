-- Function to calculate the total number of items in a list
totalItems :: [a] -> Int
totalItems [] = 0
totalItems (_:rest) = 1 + totalItems rest

-- Function to alter a list in a reverse way
alterList :: [a] -> [a]
alterList [] = []
alterList (x:xs) = alterList xs ++ [x]

-- Function to check if a list is a miroir list
isMiroirList :: Eq a => [a] -> Bool
isMiroirList xs
    | length xs < 2 = False
    | otherwise = xs == alterList xs

-- Example usage:
main :: IO ()
main = do
    print $ totalItems [2,9,5,6,1]
    print $ alterList [2,9,5,6,1]
    print $ isMiroirList [1,9,4,3,4,9,1]
    print $ isMiroirList [2,9,5,6,1]

