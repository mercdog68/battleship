# battleship
CS10 homework 16 Battleship game
****************** SRJC - CS 10A - HOMEWORK 16 - ALLEN ZHAO ***************** 
 
############# # OBJECTIVE # ############# 
 
Create a program titled battleship.cpp. This program allows the user to play a game of battleship against the computer. Since the full game would actually a significant amount of time to develop, we’ll just make a simplified version that acts as a high score run. Set up a game grid of 6x6. The computer must then place three ships: each one being 2, 3, and 4 units long respectively (I will refer to these as Cruiser for the 2 unit one, Destroyer for the 3 unit one, and Carrier for the 4 unit one). Place the ships in random positions, but keep it valid. That is, the ships cannot be overlapping or poke outside the grid boundaries. Once the ships are placed, the user will then enter a coordinate to fire at ((1, 1) is the top-leftmost position). Place an X if the ship is hit. Place an O if it’s a miss. Indicate when a ship is successfully sunk. Count the number of turns needed to successfully sink all three ships and report it back to the player when the game is over. Save the high score (the lowest number of turns, maximum would be the grid size) in a text file battleship_highscore.txt and make sure the game acknowledges when a new high score has been achieved. 
 
Define as many functions as you need to modularize your approach in developing this game. Avoid hard-coding. Refer to the solution of the array version of HW9 if you need some hints on game design. Note that despite the use of a grid and coordinates, a 2D array is not necessary for this problem. 
 
Hint: When using the RNG for ship placement, it’s recommended that you place the Carrier first, since that’s the largest ship of the three. 
 
############### # EXPECTED IO # ############### 
 
> ./battleship.exe    Current Battle Status:   Current Battle Status:   +---+---+---+---+---+---+   +---+---+---+---+---+---+   | O |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   | X | X |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   Fire at: 4 6   Fire at: 1 1     A hit!   A miss!      Current Battle Status:   Current Battle Status:   +---+---+---+---+---+---+   +---+---+---+---+---+---+   | O |   |   |   |   |   |   | O |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   | X | X |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   | X |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   Fire at: 4 1   Fire at: 2 4     A miss!   A hit!      ...   Current Battle Status:   Final Battle Status:   +---+---+---+---+---+---+   +---+---+---+---+---+---+   | O |   |   |   |   |   |   | O |   | O | O |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   | X |   |   |   |   |   |   | X | X | O |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   | O |   |   |   | X |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   | O |   | O | O |   | X |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   |   |   |   |   | O | X |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   |   |   |   |   |   |   |   | X | X | X | X |   |   |   +---+---+---+---+---+---+   +---+---+---+---+---+---+   Fire at: 2 5     All enemy ships sunk in 18 turns   A hit! Enemy cruiser sunk!   New high score! 
 
########################### # ADDITIONAL REQUIREMENTS # ########################### 
 
Inside the program, make sure there are two lines of comments. One for your name, and another for the date. 
 
Make sure to eliminate out-of-bound inputs and repeat inputs when the user selects a firing position. 
 
Assume that the high score text file does not exist by default. Your program should be able to handle both its existence and absence. Do not manually create it beforehand. The file can just consist of a single number. 
 
######################## # SUBMISSION MATERIALS # ######################## 
 
battleship.cpp 
 
********************* SRJC - CS 10A - END OF HOMEWORK 16 ******************** 
