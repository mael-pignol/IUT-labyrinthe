/*
* NAME:            load_lab
*
* DESCRIPTION:     Loads the labyrinth described in a file as an internal data structure (not directly accessible by the user)
*
* INPUTS:
*           char* filePath      The path to the file where the labyrinth is described
*
* OUTPUTS:
*           None (an internal data structure is created, it is not directly accessible by the user)
*/
void load_lab(char* filepath);

/*
* NAME:            set_start
*
* DESCRIPTION:     Set the starting position in the internal data structure describing a labyrinth
*
* INPUTS:
*           int x      The x coordinate of the starting position
*           int y      The y coordinate of the starting position
*
* OUTPUTS:
*           None (the internal data structure is updated)
*
* NOTE: Should not be used before calling load_lab
*/
void set_start(int x, int y);

/*
* NAME:            set_arrival
*
* DESCRIPTION:     Set the goal position in the internal data structure describing a labyrinth
*
* INPUTS:
*           int x      The x coordinate of the goal position
*           int y      The y coordinate of the goal position
*
* OUTPUTS:
*           None (the internal data structure is updated)
*
* NOTE: Should not be used before calling load_lab
*/
void set_arrival(int x, int y);

/*
* NAME:            exists_solution
*
* DESCRIPTION:     Checks whether or not the current labyrinth has a solution
*
* INPUTS:
*           None
*
* OUTPUTS:
*           int (0 if the labyrinth has no solution, 1 if the labyrinth has a solution)
*
* NOTE: Should not be used before calling load_lab, set_start, and set_arrival
*/
int exists_solution();

/*
* NAME:            is_valid_move
*
* DESCRIPTION:     Checks if a move is possible
*
* INPUTS:
*           int x      The x coordinate of the position where the move leads to
*           int y      The y coordinate of the position where the move leads to
*
* OUTPUTS:
*           int (0 if the move is not valid, 1 if the move is valid)
*
* NOTE: Should not be used before calling load_lab, set_start, and set_arrival
*
* NOTE: A move is valid if
*   - it leads to a position immediately next to the current one (no diagonal moves allowed)
*   - it actually changes the position (staying at current position is not a valid move)
*   - it does not require to cross a wall
*   - it does not go out of the bounds of the arena
*
* NOTE: The current position is initially set to the starting position
*/
int is_valid_move(int x, int y);

/*
* NAME:            move
*
* DESCRIPTION:     Changes the current position according to a valid move
*
* INPUTS:
*           int x      The x coordinate of the new position
*           int y      The y coordinate of the new position
*
* OUTPUTS:
*           None
*
* NOTE: Should not be used before calling load_lab, set_start, and set_arrival
*
* NOTE: An error is raised if a non valid moved is performed
*
* NOTE: The current position is initially set to the starting position
*/
void move(int x, int y);

/*
* NAME:            set_display_mode
*
* DESCRIPTION:     Changes the way of displaying moves in the labyrinth
*
* INPUTS:
*           int mode      The chosen mode:
*                            - 0      Moves are numbered
*                            - anything else      Only the current position is displayed
*
* OUTPUTS:
*           None
*/
void set_display_mode(int mode);

/*
* NAME:            display_lab
*
* DESCRIPTION:     Display the labyrinth and the moves done since the last call to display_lab
*
* INPUTS:
*           None
*
* OUTPUTS:
*           None
*
* NOTE: Should not be used before calling load_lab, set_start, and set_arrival
*/
void display_lab();

/*
* NAME:            close_lab
*
* DESCRIPTION:     Cleans the internal data structures
*
* INPUTS:
*           None
*
* OUTPUTS:
*           None
*
* NOTE: Should be used at the end of each program using this library
*
* NOTE: After a call to close_lab it is possible to call load_lab again
*/
void close_lab();

/*
* NAME:            submit
*
* DESCRIPTION:     Submits a result to the competition server
*
* INPUTS:
*           char* id        Your email adress at the University (ex "prenom.nom@etu.univ-nantes.fr")
*           char* server    The server adress (ex "127.0.0.1")
*           int solvable    0 if the current lab is not solvable, 1 if it is solvable
*
* OUTPUTS:
*           int (1 if you can proceed to the next lab,  2 if you used a wrong id, 3 if you tried to solve a wrong lab)
*
* NOTE: In any case, the next lab you have to solve will be displayed on the terminal
*/
int submit(char* id, char* server, int solvable);
