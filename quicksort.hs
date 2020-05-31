--CECS 424 ASSIGNMENT 1
--quicksort.hs
--Dominique Oyco (014605758)

qsort :: Ord a => [a] -> [a]                                                    --the required function for quicksort

qsort [] = []                                                                   --creating an empty list. An empty list brings out an empty list

-- in quicksort you are going to have a pivot x
-- where there are going to be values <= x on and value > x 
-- in haskell we feed this to the a by (a | a <-xs, a <= x) or (a | a <-xs, a > x)
-- to combine the smaller and larger values, you concatenate it to the pivot in the form
-- left side ++ [x] ++ right side

-- qsort(x:xs) = 
--	 let smallValues = qsort[a | a <- xs, a <= x]
--	     bigValues = qsort[a | a <- xs, a > x]
--	 in smallValues ++ [x] ++ bigValues                      

--This line of code below simplifies the block of code above 
qsort (x:xs) = qsort[a | a <- xs, a <= x] ++ [x] ++ qsort[a | a <- xs, a > x]	--sorting the left and the right side and concatenating it in one line of code	

main = print(qsort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])                        --print the sorted list using quicksort                