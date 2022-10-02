# Snake Game

# Objective:
Gaming industry is a multibillion-dollar industry and has maligned the youth to itself. Being fresh CS students
and having interest in gaming, we built a snake game using the practical knowledge of C++ GAINED IN
Programming Fundamentals Lab classes.
Following is the detail of the components of our code:

# Libraries:
We used iostream for regular input-output functions, windows,h for mode(), setup(), draw(), input(), logic()
functions and conio.h is necessarily for _kbhit((), _getch() functions.

# Variable:
- gameover to keep a check on game.
- width and height are constants which are used to set the size of the walls.
- choice for choosing among menu options.
- mood for choosing the mode.
- x and y for snake’s head position.
- fruitx and fruity for positioning of fruit.
- score for showing the score.
- tailx and taily for positioning of tail.
- ntail for the length of tail.
- eDirection for control.

# Mood Function:
This function is for the wall mode off the game in which when the head of the snake collides with the wall, it is
game over.
