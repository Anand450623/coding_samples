This repository contains algorithm implementation for various Game Theory related problems.

Game theory in general includes games of chance, games of imperfect knowledge, and games in which players can move simultaneously.

Combinatorial games are two-person games with perfect information and no chance moves (no randomization like coin toss is involved 
that can effect the game). These games have a win-or-lose or tie outcome and determined by a set of positions, including an initial position, 
and the player whose turn it is to move.

The specialty of Combinatorial Game Theory (CGT) is that the coding part is relatively very small and easy. The key to the 
Game Theory problems is that hidden observation, which can be sometimes very hard to find.
Chess, Game of Nim, Tic-Tac-Toe all comes under the category of Combinatorial Game Theory.

We can divide these games into two categories as shown below:
In Impartial Games all the possible moves from any position of game are the same for the players, whereas in Partisan Games 
the moves for all the players are not the same.

Eg. Impartial game - Removing sticks from pile
	Partisan Game - Chess

Minimum Exclusive: Mex

Mex of a set of number can be calculated as minimum f missing integer from set.
M{} = 0
M{0} = 1
M{1} = 0
M{0,1,4} = 2...

Grundy Number is a number that defines a state of a game. 
It is calculated as G(n) = Mex{G(0), G(1),...}
Where, G(0), G(1) are the states which can be reached from G(n)

Sprague-Grundy Theorem:

Suppose there is a composite game (more than one sub-game) made up of N sub-games and two players, A and B. 
Then Sprague-Grundy Theorem says that if both A and B play optimally (i.e., they don’t make any mistakes), 
then the player starting first is guaranteed to win if the XOR of the grundy numbers of position in each sub-games 
at the beginning of the game is non-zero. Otherwise, if the XOR evaluates to zero, then player A will lose definitely, no matter what.

Here, Result, R = XOR(G(1), G(2),...,G(n)) where G(1), G(2), ..., G(n) are the grundy numbers of the initial states for the given 
game configuration.
