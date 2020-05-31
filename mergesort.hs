--CECS 424 ASSIGNMENT 1
--mergesort.hs
--Dominique Oyco (014605758)

merge :: Ord a => [a] -> [a] -> [a]									--Order mergesort based on the datatype I put in.
merge xs [] = xs													--return the second argument if the first argument is empty
merge [] ys = ys													--return the first argument if the second argument is empty

--if statement that decides what to do when merge calls two non-empty lists (x:xs) & (y:ys). 
merge (x:xs) (y:ys) | x <= y    = x : merge xs (y:ys)				--Compare the first element in the two lists and if element x <= element y, 
																	--insert element x into list xs
                    | otherwise = y : merge (x:xs) ys				--If element x > element y, insert element y into list ys

msort :: Ord a => [a] -> [a]										--required function. Order msort based on the datatype I put in.
msort [] = []														--Creating an empty list. An empty list brings out an empty list
msort [a] = [a] 													--if msort is followed by a list containing only 1 item, label the item as 'a', and then return 'a'
msort xs = merge(msort (leftSide xs)) (msort (rightSide xs))		--merge together the sorted list of the left side and the list of the right side

--Splitting portion. In this portion continuously split the list in 2 until the length of the list is 1 (the elements are by themselves)
leftSide  xs = let n = length xs            						--Left side of the array is the first half. 
               in take (div n 2) xs									--We use take to get the elements in the first half.

rightSide xs = let n = length xs            						--Right side of the array is the remaining elements. 
               in drop (div n 2) xs									--We use drop to get the remaining elements of the original array
               
main = print(msort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])			--print the sorted list using mergesort