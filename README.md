# ShatteredTextual - Tool for Textual Game
This small tool allow fast creation of textual game.
The functionalities are very limited for the moment.

## Overview 
The engine is structured around objects called states. Those states can be levels or menus. 
The engine goes from state to state depending on user input. 

### State 
Main component
Usually, a state contains multiple choices. 

### Choice 
possible input. 
A choice can have multiple links.

### Link 
Paired with a choice.
A condition can be added to the link. 

### Condition
Can be either a ProgressionEvent, an item or a probability. 


## Version 1.0

v1.0 requires manual data file creation of levels.
The default start level need to be set in the Initialize() method of the GameStateManager. 
The Icon need also to be set manually and it can be cumbersome. 

There are several level files, an icon file and a progressionEventList file in the data folder of STEngine as an example. 

## Ongoing

Version 2.0 will have an Editor allowing data file creation and start level.
The Icon will maybe be set automatically.
