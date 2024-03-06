{-
  Multiline COmment
-}

-- Importing ::

import Data.List

trueAndFalse = False

num :: Integer
num = 69
-- Use a ' to denote a similar variable.True
num' = 69.00
noSwim = 420.00 :: Float
-- Default type for decimals is Double
noSwim' = 420.00
letter = 'a'
word = "Alpha"
word' = ['A', 'l', 'p', 'h', 'a']

-- Mod is done using "mod"
modNum = mod 4 2
modNum' = 4 `mod` 2

-- Lists
nums = [1..5]
alphas = ['a'..'z']
evens = [2,4.. 100]
odds = [1,3..100]
sumsEven = sum evens
sumsOdd = sum odds
prodEvens = product evens

findElement = num `elem` odds
findElement' = num `elem` evens

fib1 = [1,1,2,3,5,8]
fib2 = [13,21,34]
fib = fib1 ++ fib2

maxFib = maximum nums
minFib = minimum nums

addedList = zipWith (+) evens odds
infOdds = [1,3..]
odds20 = take 20 infOdds
inf5 = repeat 5
fives20 = take 20 inf5
repl5 = replicate 20 5
cycleFives = cycle fib
takeCycle = take 50 $ cycle [1,2,3]
-- $ abc is same as (abc)
