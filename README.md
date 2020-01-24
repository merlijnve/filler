# filler
### A game player algorithm

#### Summary
Create your player program to compete against other students on the
famous (or not) Filler board. The principle is simple: two players take on each other on
a board, and take turns placing the piece that the master of the game (supplied in the
form of a Ruby executable) gives them, earning points. The game stops as soon as a
piece can no longer be placed. 

#### Usage
- compile player using make
- move mvan-eng.filler to resources/players
- run filler_vm from resources directory
```
./filler_vm -f maps/map01 -p1 mvan-eng.filler -p2 carli.filler
```
#### Algorithm
On every turn, the program will loop through the range of possible coordinates to place the piece. Per coordinate, the distance to the closest opponent character will be calculated. This value will be compared to the saved coordinate, discarding the one that has a greater distance. 
The algorithm simply tries to place pieces as close to the opponent every turn. It will look like the player is following the borders of the opponents area, closing it in fast.
