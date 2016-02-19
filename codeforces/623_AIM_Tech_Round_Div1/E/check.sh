$i
while [ true ]
do
	echo $((i = i + 1))
    ./a.out >in  
    time ./ntt <in >out
    time ./fft <in >ans
    #vim -d out ans
    if ! diff out ans
    then break
    fi
done
