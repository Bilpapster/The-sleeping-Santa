# The sleeping Santa (or else The Santa Claus Problem)
 
The current repository hosts C++ source code that solves the "Santa Claus problem" using ***semaphores***.
The source code is developed alongside with the Operating Systems Course the author attended during their 3rd 
year of studies at [School of Informatics AUTh](https://www.csd.auth.gr/en/).


This is a concurrent programming problem published . The solution of the problem is 
approached using ***semaphores***.

## Problem Description

The "Santa Claus problem" is a concurrent programming exercise initially published by John Trono in 1994.
The problem wording is presented in the following paragraph.


    Santa Claus sleeps in his shop at the North Pole and can only be awakened by either (1) all nine reindeer
    being back from their vacation in the South Pacific, or (2) some of the elves having difficulty making toys;
    to allow Santa to get some sleep, the elves can only wake him when three of them have problems. When three elves
    are having their problems solved, any other elves wishing to visit Santa must wait for those elves to return. 
    If Santa wakes up to find three elves waiting at his shop’s door, along with the last reindeer having come back
    from the tropics, Santa has decided that the elves can wait until after Christmas, because it is more important 
    to get his sleigh ready. (It is assumed that the reindeer do not want to leave the tropics, and therefore they 
    stay there until the last possible moment.) The last reindeer to arrive must get Santa while the others wait in 
    a warming hut before being harnessed to the sleigh.
