# ENGG1340 Group Project

## Members:

- Anchit Mishra 
  - UID: 3035665665 
  - Username: anchit1729 
- Ajayveer Singh 
  - UID:3035664635 
  - Username: Quacktillius

## Proposal

In this project, we will use the 1981 arcade game **Galaga** as a source of inspiration and design a * *space arcade shooter* *.

### Game Description
##### Name: Astrid Crisis (not final)
The fun game mechanics and its arcadey style will be the game's main feature, but there will also be a minimalistic story-line with a beginning and an end to guide the gameplay.

##### Premise
You are a combat pilot sent as part of the UN Space Exploration Team (UNSET) to the newly discovered exoplanet Astrid. However, upon arrival you quickly find out that the planet was a trap set up by Alien Demons. With all of your crew members dead, you must fight your way back to the interdimensional portal to Earth.

##### Objective: Destroy waves of enemies before they reach the bottom of the screen, and survive by avoiding incoming projectiles.

##### Player Mechanics
The player will control a ship at the bottom of the screen.
* Can move horizontally
* Can fire projectiles towards enemies
* Can pick up "power-ups" that grant special abilities such as increased damage, faster movement etc.

##### Enemies
Enemies will randomly appear at the top of the screen and move downwards. There will be distinct classes of enemies and each class will add some nuances to the core gameplay loop.
Some enemies will have armor, and will be harder to gun down.
Other enemies will be able to fire 'waves' of multiple projectiles, making it harder for the player to dodge them.
Some enemies might move horizontally too, making it harder for the player to hit them.
There will also be 'boss' enemies, with their own set of moves and nuances.

### Game Features (Corresponding to Coding Requirements)

| Coding Requirements                      | Feature                                                                                                    |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| Generation of Random Events              | Enemies, obstacles and power-ups will be spawned randomly into the game world                              |                               
| Data Structures for Storing Game Status  | We will use classes and objects in order to store game status in binary files                              |
| Dynamic Memory Management (DMM)          | We will implement DMM to maintain queues of objects to be spawned into the game world                     |
| File Input/Output                        | We will use file handling for reading and writing binary file saves as mentioned above                     |
| Multiple Files of Program Code           | We will use separate files for various features of the game (player actions, enemy actions, save/load, menu etc.)       |
