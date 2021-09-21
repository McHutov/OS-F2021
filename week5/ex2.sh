if  [ ! -f ex2.txt ];then
echo 0 > ex2.txt
fi

counter=$(tail -1 ex2.txt)
counter=$(expr $counter + 1)
while [ $counter -lt 100 ]
do

if $(ln ex2.txt ex2.lock);then
echo "Locked"
else
exit
fi

echo $counter >> ex2.txt
counter=$(expr $counter + 1)
rm ex2.lock

done

