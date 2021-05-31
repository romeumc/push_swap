OS="linux"
NUM=$1

ARG=`ruby -e "puts (1..$NUM).to_a.shuffle.join(' ')"`;

#ARG='8 4 1 9 3 5 6';

#echo $ARG

#gdb --args push_swap $ARG

# ./push_swap $ARG

echo -n "number of moves: " && \
./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_$OS $ARG

#TOTAL=0
#SAMPLE_SIZE=80
#echo "calculating average"
#for i in $(seq $SAMPLE_SIZE); do
#	ARG=`ruby -e "puts (1..$NUM).to_a.shuffle.join(' ')"`;
#	TOTAL=`expr $TOTAL + $(./push_swap $ARG | wc -l)`
#done
#
#TOTAL=`expr $TOTAL / $SAMPLE_SIZE`
#
#echo "Average is: $TOTAL"