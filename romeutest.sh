make
TOTAL=0;
AVG=0;
for i in range {1..99}
	do
		ARG=`seq 1 $1 | sort -R`
		RET=`./push_swap $ARG | wc -l`
		TOTAL=$((TOTAL+RET))
		echo $ARG " - " $RET "(total:"$TOTAL")"
		if [ $1 -eq 5 -a $RET -gt 12 ];
			then
			echo "ERROR, more than 12 instructions"
			echo $ARG > last_arg.txt
			exit
		fi
		
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			echo "ERROR, list not ordered"
			echo $ARG > last_arg.txt
			exit
		fi
		
		
		# ./push_swap $ARG
		# ./push_swap $ARG | ./checker $2 $ARG
done
AVG=$((TOTAL/$i+1))
echo "Average: ("$TOTAL"/"$((i+1))")="$AVG