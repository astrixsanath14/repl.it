echo "Enter the cpp file name: "
read cppFileName
echo "cppFileName: ${cppFileName}"
cppFileNameWithExtension="${cppFileName}.cpp"
echo "Going to compile and run ${cppFileNameWithExtension}"
echo "\n------------ OUTPUT START ------------"
echo "--------------------------------------"
clang++-7 -pthread -std=c++17 -o ${cppFileName} ${cppFileNameWithExtension}; ./${cppFileName}
echo "\n--------------------------------------"
echo "------------ OUTPUT END --------------"