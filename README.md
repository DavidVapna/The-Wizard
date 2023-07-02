# The Wizard


Description:
"The Wizard" is an exciting jump quest game where players embark on an adventure through various levels, each with its own unique story. The objective of each level is to collect a specific item while facing challenges along the way. Beware of enemies that try to impede your progress by knocking you back!


Installation Instructions:
To install and run "The Wizard" on your system, follow these steps:
Make sure you have a C++ compiler installed.
Install the Box2D and SFML libraries. You can find the installation instructions for these libraries on their respective websites.
Clone the repository or download the source code.
Compile the code using your C++ compiler, linking it with the Box2D and SFML libraries.
Run the compiled executable file to start playing the game.


Controls:
Use the arrow keys to move the wizard character.
Press the spacebar to make the wizard jump.


Design Patterns:
"The Wizard" incorporates several design patterns to enhance its functionality and efficiency:

Multimethods are utilized to handle collisions between objects simultaneously, ensuring smooth gameplay.
The Factory pattern is employed to create objects quickly and specifically for each level, including items, enemies, menus, and other elements.
The State pattern is used to manage different states of the game, such as the main menu, help screens, the game itself, and the pause state.
Singleton design pattern is employed to load essential game elements uniquely, optimizing memory usage and preventing unnecessary duplication.
Contributing:
We welcome contributions from the community to enhance "The Wizard." If you would like to contribute, please feel free to fork the repository and submit pull requests with your proposed changes. We appreciate your support in making the game even better!


Get ready to immerse yourself in the enchanting world of "The Wizard" and overcome challenging levels to collect valuable items. Enjoy the adventure and have fun!


Note: This game is still under development and may contain unfinished features or areas.
