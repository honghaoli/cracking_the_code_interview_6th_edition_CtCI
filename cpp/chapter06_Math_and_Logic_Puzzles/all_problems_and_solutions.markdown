
### 1. The Heavy Pill:
You have 20 bottles of pills. 19 bottles have 1.0 grams pills, but one has pills of weight 1.1 grams. Given a scale that provides an exact measurement, how would you find the heavy bottle? You can only use the scale once.

#### Answer
pick i pills from the ith bottle, sum up all the weights, then we know how many pills are 1.1 grams, thus we know which bottle has heavier pills.



### 2. Basketball:
You have a basketball hoop and someone says that you can play one of two games.
Game 1: You get one shot to make the hoop.
Game 2: You ge three shots and you have to make two of three shots.
If p is the probability of making a particular shot, for which values of p should you pick one game or the other?

#### Answer:
Game 2 has prob = C(2, 3) * p^2 (1 - p) + p^3
If Game 2 > Game 1:  prob > p. So when 1/2 < p < 1, we should choose Game 2. Otherwise choose Game 1.


### 3. Dominos:
There is an 8x8 chessboard in which two diagonally opposite corners have been cut off. You are given 31 dominos, and a single domino can cover exactly two squares. Can you use the 31 dominos to cover the entire board? Prove your answer (by providing an example or showing why it's impossible).

#### Answer:
No way.
Two diagonally opposite corners have the same color.


### 4. Ants on a Triangle:
There are three ants on different vertices of a triangle. What is the probability of collision (between any two or all of them) if they start walking on the sides of the triangle? Assume that each ant randomly picks a direction, with either direction being equally likely to be chosen, and that they walk at the same speed.
Similarly, find the probability of collision with n ants on an n-vertex polygon.

#### Answer:
Probability of no collision at all, they either all choose left or right, two cases.
Out of all the possibility = 2^n;
So it's   2 / 2^n = 1 / 2^(n-1) with no collision
P(collision) = 1 - 1 / 2^(n-1).


### 5. Jugs of water:
You have a five-quart jug, a three-quart jug, and an unlimited supply of water (but no measuring cups). How would you come up with exactly four quarts of water? Note that the jugs are oddly shaped, such that filling up exactly "half" of the jug would be impossible.

#### Answer:
1. put 3 into 5 jug;
2. put another 3 into 5 jug, 5 jug is full, and left 1 in 3 jug.
3. empty the 5 jug, put the 1 into 5 jug.
4. add another 3 into 5 jug. now 5 jug has 4 water.


### 6. Blue-Eyed Island:
A bunch of people are living on an island, when a visitor comes with a strange order: all blue-eyed people must leave the island as soon as possible. There will be a flight out at 8:00pm every evening. Each person can see everyone else's eye color, but they do not know their own (nor is anyone allowed to tell them). Additionally, they do not know how many people have blue eyes, although they do know that at least one person does. How many days will it take the blue-eyed people to leave?
