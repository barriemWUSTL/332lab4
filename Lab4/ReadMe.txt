Mustapha Barrie and Alex Chow Lab 4.

We divided up the work based on who was more experienced with the components. The majority of setting up the classes was done by Alex, while Mustapha handled operators 
and the tictactoe functions. We also split the gomoku operations.

Errors: Arithmetic overflow Using operator "-"
When going to TA office hours the TA said it would be okay if we left this warning.

Testing TicTacToe:
TicTacToe:
H:\CSE332_Repositories\Lab4\Lab4\Debug>Lab4.exe TicTacToe
4
3
2
1
0
 0 1 2 3 4
X's turn
Please input coordinates for your next piece in the format 'x,y', or 'quit' to quit.
anjnksdf
Invalid coordinates, please reenter
Please input coordinates for your next piece in the format 'x,y', or 'quit' to quit.
2,2
4
3
2    X
1
0
 0 1 2 3 4


 I have check for correctness in all ways with draws, wins, quits.
O's turn
Please input coordinates for your next piece in the format 'x,y', or 'quit' to quit.
quit
O quit the game in 2 turns!



Testing Gomuku:
The done function refuses to work at this current point. 
We're fairly sure that draw() works, and obviously turn works.

Quit also quits, much like TicTacToe, and it correctly displays the board and moves