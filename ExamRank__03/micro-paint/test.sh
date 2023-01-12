gcc micro_paint.c -o a.out -Wall -Wextra -Werror
gcc criteria.c -o original -Wall -Wextra -Werror
echo "-------------------------------------------------------"
echo "TEST - <ex_1>"
echo "내가한거"
./a.out ./test/ex_1
echo "정답"
./original ./test/ex_1
echo "-------------------------------------------------------"
echo "TEST - <ex_2>"
echo "내가한거"
./a.out ./test/ex_2
echo "정답"
./original ./test/ex_2
echo "-------------------------------------------------------"
echo "TEST - <ex_3>"
echo "내가한거"
./a.out ./test/ex_3
echo "정답"
./original ./test/ex_3
echo "-------------------------------------------------------"
echo "TEST - <ex_4>"
echo "내가한거"
./a.out ./test/ex_4
echo "정답"
./original ./test/ex_4
echo "-------------------------------------------------------"
echo "TEST - <NULL>"
echo "내가한거"
./a.out
echo "정답"
./original
echo "-------------------------------------------------------"
echo "TEST - <Error file>"
echo "내가한거"
./a.out ./test/ex
echo "정답"
./original ./test/ex
rm a.out
rm original