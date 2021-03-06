echo "" 
hostname=$(hostname)
echo "hostname is ${hostname}"
echo "Enter the file path to be executed: "
read inputFilePathWithExtension
echo "You entered: \n${inputFilePathWithExtension}"
echo "" 

inputFilePath=${inputFilePathWithExtension%.*}
extension=${inputFilePathWithExtension##*.}
echo "filename=${inputFilePath}"
echo "extension=${extension}"
if [ "${extension}" = "cpp" ];
then
  echo "Going to compile and run C++ CODE: ${inputFilePathWithExtension}"
  echo "\n------------ OUTPUT START ------------"
  echo "--------------------------------------"
  if [ "${hostname}" = "sanath-10401" ]
  then
    g++ -pthread -std=c++17 -o ${inputFilePath} ${inputFilePathWithExtension}; ./${inputFilePath}
  else
    clang++-7 -pthread -std=c++17 -o ${inputFilePath} ${inputFilePathWithExtension}; ./${inputFilePath}
  fi
  echo "\n--------------------------------------"
  echo "------------ OUTPUT END --------------"
elif [ "${extension}" = "py" ];
then
  echo "Going to run PYTHON CODE: ${inputFilePathWithExtension}"
  echo "\n------------ OUTPUT START ------------"
  echo "--------------------------------------"
  python3 ${inputFilePathWithExtension}
  echo "\n--------------------------------------"
  echo "------------ OUTPUT END --------------"
elif [ "${extension}" = "sh" ];
then
  echo "Going to run SHELL CODE: ${inputFilePathWithExtension}"
  echo "\n------------ OUTPUT START ------------"
  echo "--------------------------------------"
  sh ${inputFilePathWithExtension}
  echo "\n--------------------------------------"
  echo "------------ OUTPUT END --------------"
else
  echo "Oops, sorry unsupported file execution. "
  exit 1
fi