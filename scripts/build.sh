curr=$PWD

cd /home/yu/library/chainsaw

cmake -B build -S .
cmake --build build/

cd ${curr}