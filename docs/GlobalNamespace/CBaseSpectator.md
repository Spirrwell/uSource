# class CBaseSpectator

*Defined at line 20 of ./game/server/spectator.h*

Inherits from CBaseEntity



## Functions

### Spawn

*public void Spawn()*

*Defined at line 143 of ./game/server/spectator.cpp*

===========Spawn

  Called when spectator is initialized:  UNDONE:  Is this actually being called because spectators are not allocated in normal fashion?============

### SpectatorConnect

*public void SpectatorConnect()*

*Defined at line 35 of ./game/server/spectator.cpp*

===========SpectatorConnect

called when a spectator connects to a server============

### SpectatorDisconnect

*public void SpectatorDisconnect()*

*Defined at line 51 of ./game/server/spectator.cpp*

===========SpectatorDisconnect

called when a spectator disconnects from a server============

### SpectatorThink

*public void SpectatorThink()*

*Defined at line 121 of ./game/server/spectator.cpp*

================SpectatorThink

Called every frame after physics are run================

### SpectatorImpulseCommand

*private void SpectatorImpulseCommand()*

*Defined at line 62 of ./game/server/spectator.cpp*

================SpectatorImpulseCommand

Called by SpectatorThink if the spectator entered an impulse================



