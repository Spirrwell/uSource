### Repository Structure

#### `docs/`

Engine documentation

#### `scripts/`

Utility and common scripts needed by the engine

#### `thirdparty/`

All thirdparty components of the engine

#### `contrib/`

Individual contributions that should be tracked by source control. People working on the project may add their personal convinence and utility scripts here to 
aid with development.

For example I, jjl77, have a configure script and some others so I dont need to constantly type in a ton of flags.

Feel free to add your own personal scripts to the repo if you're contributing code back to the upstream regularly or if you have write access to the repository.

#### `common/`

Common code and headers will go here.

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