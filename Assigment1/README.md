SO question given was

//Write a program that takes some data as string input. Then it tries to find a positive number x such that 
when x is appended to the end of the string, the SHA256 hash of this new string is less than the target, which is
0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
Also print the time it takes to get this nonce value.
You are supposed to use pre-implemented libraries for hashing, such as the js crypto library or the go crypto library,
and not implement your own hashing function. So the task should not be difficult to proceed with.
You can do this in any language of your choice

// my solution 

// logic used 
As we have to append a number in end of string string to get its hash value less than the target
we will start by checking with all possible whole number 
and end our loop when we reached a value which is less than the target value 

//code 
i have used python language and used library hashlib for SHA256 
my code starts wit taking a string as an input, the it takes the string and append a whole number in it by one by one 
for aading integer to string i used typecasting 

then using SHA256 i created hash value for each string and compared it with the target value 
if it was less break statement will break the loop and print the nonce value if not loop will continue 
also i have used hexdigest function it is beacause SHA256 just return the location of the hash value stored.
for taking the value from its location i used hexdigest.

// one more task was to print the time taken 
two method are there 

Method 1 = take number of operation that can be performed by python in one sec 
reverse it and muktiply it with the nonce value (number of times loop had run)

Method 2 = use timeit library 

// working 
as you run the code it will ask you to enter a sring 
and it will output first a nonce value according to your input string 
then in 2nd line it will output time taken for finding that

