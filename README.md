# 42 Project: Lem_in

The purpose of this project is to find the shortest path on a graph to move 'ants' from start to end. Ants could only move one room per turn, and no more than one ant could occupy a single node at one time.

A text file is given as input, which specifies the number of ants, the rooms, and the links. It would look something like this:

```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```
Which corresponds to a graph:

```
           ______________
         /                \
  ______[5]----[3]----[1] |
/               |    /    |
[6]-----[0]----[4]  /     |
 \    _________/|  /      |
  \ /          [2]/______ /
   [7]_________/
```
We used a breadth first algorithm to find optimal paths and then remove paths as the number of ants decreased. By using this method we were able to find the least number of turns for all ants to reach to end room.
