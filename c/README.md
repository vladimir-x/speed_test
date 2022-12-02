gcc -O3 main.c -o main && ./main  incrementator 17 10000000000
gcc -O3 main.c -o main && ./main  multiplier 17 10000000000
gcc -O3 main.c -o main && ./main  divider 17 10000000000
gcc -O3 main.c -o main && ./main  modder 17 10000000000
gcc -O3 main.c -o main && ./main  xorder 17 10000000000
gcc -O3 main.c -o main && ./main  factorial 17 100000000

gcc -O3 main.c -o main && ./main crc 31221 1

gcc -O3 main.c -o main && ./main array_cp 5000000 10000
gcc -O3 main.c -o main && ./main list_custom_check_append 1000000 5000
gcc -O3 main.c -o main && ./main tree_set_custom 1000000 4000000
gcc -O3 main.c -o main && ./main hash_set_custom 1000000 10000000

#сет превратился в лист
gcc -O3 main.c -o main && ./main hash_set_bad_custom 1000000 1000000
gcc -O3 main.c -o main && ./main array_cp_prepare_to_qsort 1000000 20
gcc -O3 main.c -o main && ./main qsort_custom 1000000 20
gcc -O3 main.c -o main && ./main qsort_standart 1000000 20
