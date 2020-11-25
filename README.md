# Homework 2

Use functions FindSimpleWithRangeForLoop and FindBinarySearch from the lecture.

1. Modify the TestVectorSet function so that you report the time it takes to create the vector and the set; and running the "find" functions.
2. Modify the main function so that you perform the test for sz values 1000, 10000, 100000, 1000000, 10000000.
3. For each sz value, perform the test for 10 randomly generated ValueToFind values between 0 and sz-1. Do not forget to randomize your seed value for the rand function.
4. Generate a report that lists the average performance of each "find" function for each sz value. Report may look as follows:

|Function | 1000 | 10000 | 100000 | 1000000 | 10000000|
|----| ---- | ---- | ---- | ---- | ----|
|Vector construct 2795 |22485 | 274722|2.28e+06 | 2.29e+07|
|Set construct 47329| 458568| 4.45e+06|5.16e+07 |5.91e+08 | 
|FindSimpleWithRangeForLoop 78.4| 468.6| 2197.9|25562.4 | 277743| 
|FindBinarySearch 8.5| 15.1| 13.8|31.5 | 42.8| 
|Set find 20.2|45.8|39.6 |62.1 |88.2 | 
