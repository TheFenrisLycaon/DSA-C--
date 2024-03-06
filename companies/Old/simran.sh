mkdir src
mv ./DSA-C--/Algorithms/integerToRoman.cpp ./src/integerToRoman.cpp
mv ./DSA-C--/Algorithms/isPallidrome.cpp ./src/isPallindrome.cpp
cd ./DSA-C--
git add .
git commit " cleanup "
git push
echo ""
echo "Done cleaning up."
echo ""
git checkout -b patch-1
cp ../src/integerToRoman.cpp ./Algorithms/integerToRoman.cpp
git add .
git commit -m "Added algo"
git push --set-upstream origin patch-1
git push
echo ""
echo "Done with first one"
echo ""
git checkout master
git checkout -b patch-2
cp ../src/isPallindrome.cpp ./Algorithms/isPallindrome.cpp
git add .
git commit -m "Added algo"
git push --set-upstream origin patch-2
git push
echo ""
echo "Done with 2nd one"
echo ""

