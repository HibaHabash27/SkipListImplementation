# SkipListImplementation
implement Skip Lists.
You will build the data structure and implement these functions
Insert , Search , Delete, GetMax ,GetMin
each one of them will be used to test your implementation

The test case is a transaction file. The first line contains the number of entries that will be inserted and then the number of total commands (insertions , searches and Deletion ).

After that each line in the file represents a command that either: inserts , deletes or searches the entries based on the key.

Using any other technique but the Skip List is not acceptable and you will get a Zero
Cheating will COST YOU THE COURSE
Comment your student ID in the code
Input Format

[ Operation : Key ]

Output Format

The output consists of the following:
first are the results of the searches. You will have a [Yes] for each successful search and a [No] or each failed search.
Following that is the max values and then the min value.

[max value]

[min value]

The values stored in the linked-list.

Sample Input

5 9
[ i : 220 ]
[ i : 130 ]
[ i : 90 ]
[ i : 67 ]
[ i : 40 ]
[ s : 220 ]
[ s : 11 ]
[ d : 90 ]
[ s : 90 ]
Sample Output

[Yes]
[No]
[No]
[220]
[40]
[40,67,130,220]
Explanation

5: Max Number Of Entered Data

9: Number of total operations including insertion of data

[i : 220] i : is for insertion & 220 is the KEY

[s : 220] s : is for Search & 220 is the KEY

[d : 90] i : is for Deletion & 220 is the KEY
