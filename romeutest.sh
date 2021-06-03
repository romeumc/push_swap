make

for i in range {1..99}
	do
		ARG=`seq 1 $1 | sort -R`
		echo $ARG > last_arg.txt
		./push_swap $ARG
		./push_swap $ARG | ./checker $2 $ARG
		cat last_arg.txt
done