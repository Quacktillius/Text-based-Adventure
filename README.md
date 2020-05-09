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
You are a combat pilot sent as part of the UN Space Exploration Team (UNSET) to the newly discovered exoplanet Astrid. However, upon arrival you quickly find out that the planet was a trap set up by Alien Demons. With all of your crew members dead, you must fight your way back through an endless onslaught of Demons, killing as many as you can.

##### Objective: Destroy waves of enemies before they reach the bottom of the screen, and survive by avoiding incoming projectiles.

##### Player Mechanics
The player will control a ship at the bottom of the screen.
* Can move horizontally
* Can fire projectiles towards enemies
* Can pick up "power-ups" that grant special abilities such as increased damage, faster movement etc.
* Has 3 lives, i.e can take damage thrice without having to restart

##### Enemies
Enemies will randomly appear at the top of the screen and move downwards. There will be distinct classes of enemies and each class will add some nuances to the core gameplay loop.
Some enemies will have armor, and will be harder to gun down.

##### Power Ups (tentative list)
* BFB (inspired by the BFG from the Doom games, it kills all enemy ships in one shot, but is one use only)
* Extra Life (lets the player respawn once more without losing progress)
* Hyperjets (makes player movements 100% faster)

### Game Features (Corresponding to Coding Requirements)

| Coding Requirements                      | Feature                                                                                                    |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| Generation of Random Events              | Enemies and power-ups are spawned randomly into the game world                              |                               
| Data Structures for Storing Game Status  | We use classes and objects in order to store game status in binary files and handle related functions in a seamless manner                               |
| Dynamic Memory Management (DMM)          | We implement DMM to maintain dynamic queues of objects to be spawned into the game world, as well as dynamically initialise save files upon starting the game            |
| File Input/Output                        | We use file handling for reading and writing binary file saves as mentioned above, along with text file handling in order to maintain a record of top scores                     |
| Multiple Files of Program Code           | We use separate files for various features of the game (player actions, enemy actions, save/load, menu etc.)       |

## DISCLAIMER
Regarding the intro sequence that plays at the beginning of the game:
* It is purely for comedic purposes, and thus, should be taken in a light hearted mannar.
* The first line serves not to disregard the worth of the project, calling it "mediocre", but rather to set the tone for intro
* The second line furthers this
* We are NOT saying that this is the best project. The 3rd line was purely comedic. No one was bribed, or said that.

## Controls:
### Menu:
1- Make a new Game (No need to press Enter)  
2- Leaderboard (No need to press Enter)   
3- Exit (No need to press Enter)  

### In-game:
A- Strafe left  
D- Strafe right  
W- Shoot  
