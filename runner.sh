#!/bin/bash



_1MLRD=$((1000*1000*1000))
_5M=$((5*1000*1000))

REPEATS_1MLRD=$((1000*1000*1000))
REPEATS_100M=$((1000*1000*100))
REPEATS_10M=$((10*1000*100))
REPEATS_5M=$((5*1000*100))
REPEATS_4M=$((4*1000*100))
REPEATS_1M=$((1*1000*100))
REPEATS_10=$((10))
REPEATS_20=$((20))
REPEATS_10K=$((10000))
REPEATS_5K=$((5000))
REPEATS_500=$((500))

CALC_REPEATS=$((1000*1000*1000))
CALC_REPEATS_BIG=$((10*1000*1000*1000))
FACTORIAL_REPEATS=$((10*1000*1000*100))
CRC_REPEATS=$((1000*1000*100))

ARRAY_CP_SIZE_BIG=$((1000*1000*1000))
ARRAY_CP_RETRY_BIG=$((10))

LIST_SIZE=$((1000*1000))
LIST_RETRY=$((5*1000))
SET_RETRY=$((100*1000*1000))
HASH_SET_RETRY=$((200*1000*1000))
HASH_SET_BAR_RETRY=$((100*1000))
SORT_RETRY=$((100))

cd c
gcc -O3 main.c -o main

./main incrementator   17 $CALC_REPEATS_BIG
./main multiplier      17 $CALC_REPEATS_BIG
./main divider 2132134117 $CALC_REPEATS
./main modder  2132134117 $CALC_REPEATS
./main xorder  2132134117 $CALC_REPEATS_BIG
./main factorial  17 $FACTORIAL_REPEATS
./main crc 123456 $CRC_REPEATS

./main array_cp $ARRAY_CP_SIZE_BIG $ARRAY_CP_RETRY_BIG

./main list_custom_check_append $LIST_SIZE $LIST_RETRY
./main tree_set_custom $LIST_SIZE $SET_RETRY
./main hash_set_custom $LIST_SIZE $HASH_SET_RETRY
./main hash_set_bad_custom $LIST_SIZE $HASH_SET_BAR_RETRY

./main array_cp_prepare_to_qsort $LIST_SIZE $SORT_RETRY
./main qsort_custom $LIST_SIZE $SORT_RETRY
./main qsort_standart $LIST_SIZE $SORT_RETRY
cd ..

cd cpp
g++ -O3 main.cpp -o main
./main  incrementator   17 $CALC_REPEATS_BIG
./main  multiplier      17 $CALC_REPEATS_BIG
./main  divider 2132134117 $CALC_REPEATS
./main  modder  2132134117 $CALC_REPEATS
./main  xorder  2132134117 $CALC_REPEATS_BIG
./main  factorial  17 $FACTORIAL_REPEATS
./main  crc 123456 $CRC_REPEATS

./main  array_cp $ARRAY_CP_SIZE_BIG $ARRAY_CP_RETRY_BIG

./main  list_custom_check_append_clear $LIST_SIZE $LIST_RETRY
./main  list_custom_check_append_recreate $LIST_SIZE $LIST_RETRY
./main  list_standart_check_append_clear $LIST_SIZE $LIST_RETRY
./main  list_standart_check_append_recreate $LIST_SIZE $LIST_RETRY
./main  tree_set_standart $LIST_SIZE $SET_RETRY
./main  hash_set_standart $LIST_SIZE $HASH_SET_RETRY

./main  array_cp_prepare_to_qsort $LIST_SIZE $SORT_RETRY
./main  sort_with_array_cp $LIST_SIZE $SORT_RETRY
cd ..

cd java/src
javac Main.java
java Main incrementator   17 $CALC_REPEATS_BIG
java Main multiplier      17 $CALC_REPEATS_BIG
java Main divider 2132134117 $CALC_REPEATS
java Main modder  2132134117 $CALC_REPEATS
java Main xorder  2132134117 $CALC_REPEATS_BIG
java Main factorial  17 $FACTORIAL_REPEATS
java Main crc  123456 $CRC_REPEATS

java -Xmx7g Main array_cp $ARRAY_CP_SIZE_BIG $ARRAY_CP_RETRY_BIG

java -Xmx7g Main list_custom_check_append_clear $LIST_SIZE $LIST_RETRY
java -Xmx7g Main list_custom_check_append_recreate $LIST_SIZE $LIST_RETRY
java -Xmx7g Main list_standart_check_append_clear $LIST_SIZE 0
java -Xmx7g Main list_standart_check_append_recreate $LIST_SIZE 0
java -Xmx7g Main tree_set_standart $LIST_SIZE $SET_RETRY
java -Xmx7g Main hash_set_standart $LIST_SIZE $HASH_SET_RETRY

java -Xmx7g Main list_cp_prepare_to_qsort $LIST_SIZE $SORT_RETRY
java -Xmx7g Main array_cp_prepare_to_qsort $LIST_SIZE $SORT_RETRY
java -Xmx7g Main sort_standart_list $LIST_SIZE $SORT_RETRY
java -Xmx7g Main sort_standart_array $LIST_SIZE $SORT_RETRY
cd ../..

