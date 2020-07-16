### Engine Components

#### `public/`

Primary utility library that includes containers, crtlib, the AppFramework and the base XProf implementation.

#### `mathlib/`

Primary math utility library. Currently used sparsely throughout the project, but things will eventually move over to it in the future.

#### `tier1/`

Level 1 AppSystem users. Handles loading of basic engine interfaces like IEngineMalloc, IEngineTrace, IEngineCvar, etc.

Also provides some abstractions away from the raw APIs, such as the Convar class and CONCOMMAND macro.

#### `tier2/`

Level 2 AppSystem users. Handles loading of more advanced interfaces, such as that from the rendering system. Like tier1, it also provides some wrappers 
around these interfaces. Also provides MeshBuilder classes and things like that.

#### `tier3/`

Level 3 AppSystem users. Handles loading of the UI interfaces and provides simple UI abstractions.

#### `mainui/`

Primary UI implementation. Provides various UI controls like buttons and implements the various UIs throughout the game. 

#### `game_launch/`

Game launcher

#### `game/`

All game code goes here. Structured similarly to source.

#### `ref_gl`

Old rendering system or "refresher". This is being replaced by a new rendersystem.

#### `rendersystem/`

New rendering system that's currently work in progress.