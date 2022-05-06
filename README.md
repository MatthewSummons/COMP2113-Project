# COMP2113-Project
A text-based game created in C/C++ created by Shaheer Ziya &amp; Botagoz Issayeva (Group 169)

// Description of Game & Introduction of Game Rules


Project Requirement:

1. Generation of random game sets or events

The game has 6 major chapters, with four stages in the middle that can appear in any order. The plot of the game is written such that no matter which path you chose, the story will make sense. So the 4 chapters in between the Intorduction & Finale can appear in any order during a playthrough.

2. Data structures for storing game status

We use structs & arrays among other miscellaneous data structures to store the game status. The two key datapoints for the gamestatus are the current stage & the inventory which are represented as a string and an array of strings.

3. Dynamic memory management

The game uses dynamic memory where appropriate. Its major role is in handling the inventory, especially handling the contents of the inventory when saving & loading from a save file.

The inventory is represented in the program as a pointer to an array of strings, generated when neccessary. This choice to make it a pointer is done out of convenince and for the sake of consistency as this is how it is also handled with in the save/load part of the game

4. File input/output (e.g., for loading/saving game status)

The game saves & loads data from a save.save file. The functions in the "Save_Load.cpp" file handle with encapsulating the game status in a struct and then writing and reading it from the save file. The save file primarily holds the next stage and the inventory for the user where they left it off in the game.

Note that due to the structure of the plot the player is only offered to save their game at certain checkpoints, otherwise the management of key events would become increasingly complex & tedious. Thankfully, since the stages themselves aren't too long, we thought it was an appropriate design decision.

5. Program codes in multiple files

The game has been sectioned into multiple *.cpp & *.hpp files for organization purposes. One glance at the main.cpp file can attest to this fact. Some *.cpp files in fact don't even show up in the main file such as the minigames.cpp file which is a dependency for the story.cpp file instead.

6. Proper indentation and naming styles

We used 2-space tabs and used snake_case in our code where appropriate and ensured our best to maintain consitency in the code style for the game. The naming conventions and other stylistic decsisions can be called personal to an extent but are consitent througout the program.

7. In-code documentation

The code is reasonably well documented, with "doc-strings" above functions explaining what their inputs & outputs are (if any) and describe what the accomplish after running.



No non-standard libraries as such were used to make this text-based adventure game.

Quick Start Guide:
Open a terminal and move to the directory with the game's code. Then run the commands

make GAME
./GAME

And enjoy playing the game