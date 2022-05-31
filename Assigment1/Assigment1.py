import hashlib                      #for using sha256
import timeit                       #for calculating time 
str1 = input("Enter the string: ")   #input
i = 0                                #take number starting from 0
while (1):
    strs = str1+str(i)                # convert it to string and add it to the last of input string
    x=hashlib.sha256(strs.encode())   #conversion
    x = x.hexdigest()                 # conversion 2.0
    if(x<"00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"):   # comparing to the target 
        break
    i=i+1
print(i)                               #printing nonce(number used once as loop is strictly
                                       #increasing it will be used just once )
print(timeit.timeit('output = 10*5'))  #net se uthaya hai 
