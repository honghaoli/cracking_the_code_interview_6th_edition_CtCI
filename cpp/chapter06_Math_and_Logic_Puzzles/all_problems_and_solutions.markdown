
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

#### Answer:
Start from 1 person, he immediately knows the only person is himself, so he leaves on the 1st day;
If there are 2 persons, A would notice B did not leave on the 1st day, then he knows himself is blue too.
Following the same logic, if there are N blue-eyed persons, they will simultaneously leave on the Nth day.


### 7. The Apocalypse:
In the new post-apocalyptic world, the world queen is desperately concerned about the birth rate. Therefore, she decrees that all families should ensure that they have one girl or else they face massive fines. If all families abide by this policy -- that is, they have continue to have children until they have one girl, at which point they immediately stop -- what will the gender ratio of the new generation be? (Assume that the odds of someone having a boy or a girl on any given pregnancy is equal.) Solve this out logically and then write a computer simulation of it.

#### Answer:
The probability of having i boys is
P(i) = (1/2)^i * (1/2)
So the expectation of number of boys is:
N = sum_{i = 0}^{i = infinity} i * (1/2) ^ (i + 1);
The sum is exactly 1, the same as the number of girls.
So the ratio is still 1 : 1


### 8. The Egg Drop Proble:
There is a building of 100 floors. If an egg drops from the Nth floor or above, it will break. If it's dropped from any floor below, it will not break. You're given two eggs. Find N while minimizing the number of drops for the worst case.
