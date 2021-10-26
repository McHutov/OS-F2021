echo Dastan >> _ex3_1.txt
echo Permissions at the beginning, without any change:  >>  ex3_1.txt
ls -l >> ex3_1.txt
echo After removing execute permission to everybody: >> ex3_1.txt
chmod a-x _ex3.txt
ls -l >> ex3_1.txt
echo Then, granted all permissions to owner and others: >> ex3_1.txt
chmod uo+rwx _ex3.txt
ls -l >> ex3_1.txt
echo Made group permissions equal to user permissions: >> ex3_1.txt
chmod g=u _ex3.txt
ls -l >> ex3_1.txt
