Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, gold-hoarding monster
who likes to eat people who disturb its sleep. The player's goal is to guide an adventurer to kill
the Wumpus, find its hidden gold, and escape alive. The Wumpus lives in a large cave of rooms
arranged in a grid, where each room has four tunnels leading to the rooms to the north, east,
south, and west.

The adventurer starts the game in a random empty room in the Wumpus’ cave. Her starting
position is also the location of the escape rope that she must use to escape after she's
completed her task.
Each room may be empty, or it may contain one (and only one) of four "events" (all described
below): two kinds of dangerous hazards, the terrifying Wumpus, and the gold treasure. When
the adventurer is in a room that’s adjacent to one containing an "event", the player will receive a
percept (a message) to inform them about the event the adventurer is close to.
If the adventurer perishes while searching for the Wumpus, the player should be presented with
the option to start the game over with the same cave configuration, start the game over with a
new random cave configuration, or quit the game entirely.
The player wins the game if they can safely guide the adventurer through the cave to kill the
Wumpus, pick up the gold, and make it back to the escape rope unharmed!


---!!!IMPORTANT!!!---
In order to correctly compile program type "make" after that "./prog (size of grid) (true/false)
If you want to play in Admin mode and unhiden everything you should type "./prog (size of grid) true"
If you want to play in normal mode you should run program with "./prog (size of grid) false"
Size of grid should be given as single integer, for example 5 will be interpreted as 5x5 grid.