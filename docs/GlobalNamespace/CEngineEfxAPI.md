# class CEngineEfxAPI

*Defined at line 3634 of ./engine/client/cl_game.cpp*

Inherits from IEngineEfx



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 3637 of ./engine/client/cl_game.cpp*

### GetName

*public const char * GetName()*

*Defined at line 3638 of ./engine/client/cl_game.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 3639 of ./engine/client/cl_game.cpp*

### Init

*public _Bool Init()*

*Defined at line 3640 of ./engine/client/cl_game.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 3641 of ./engine/client/cl_game.cpp*

### AllocParticle

*public particle_t * AllocParticle(void (*)(struct particle_s *, float) callback)*

*Defined at line 3643 of ./engine/client/cl_game.cpp*

### BlobExplosion

*public void BlobExplosion(const float * org)*

*Defined at line 3648 of ./engine/client/cl_game.cpp*

### Blood

*public void Blood(const float * org, const float * dir, int pcolor, int speed)*

*Defined at line 3653 of ./engine/client/cl_game.cpp*

### BloodSprite

*public void BloodSprite(const float * org, int colorindex, int modelIndex, int modelIndex2, float size)*

*Defined at line 3658 of ./engine/client/cl_game.cpp*

### BloodStream

*public void BloodStream(const float * org, const float * dir, int pcolor, int speed)*

*Defined at line 3663 of ./engine/client/cl_game.cpp*

### BreakModel

*public void BreakModel(const float * pos, const float * size, const float * dir, float random, float life, int count, int modelIndex, char flags)*

*Defined at line 3668 of ./engine/client/cl_game.cpp*

### Bubbles

*public void Bubbles(const float * mins, const float * maxs, float height, int modelIndex, int count, float speed)*

*Defined at line 3673 of ./engine/client/cl_game.cpp*

### BubbleTrail

*public void BubbleTrail(const float * start, const float * end, float height, int modelIndex, int count, float speed)*

*Defined at line 3678 of ./engine/client/cl_game.cpp*

### BulletImpactParticles

*public void BulletImpactParticles(const float * pos)*

*Defined at line 3683 of ./engine/client/cl_game.cpp*

### EntityParticles

*public void EntityParticles(struct cl_entity_s * ent)*

*Defined at line 3688 of ./engine/client/cl_game.cpp*

### Explosion

*public void Explosion(float * pos, int model, float scale, float framerate, int flags)*

*Defined at line 3693 of ./engine/client/cl_game.cpp*

### FizzEffect

*public void FizzEffect(struct cl_entity_s * pent, int modelIndex, int density)*

*Defined at line 3698 of ./engine/client/cl_game.cpp*

### FireField

*public void FireField(float * org, int radius, int modelIndex, int count, int flags, float life)*

*Defined at line 3703 of ./engine/client/cl_game.cpp*

### FlickerParticles

*public void FlickerParticles(const float * org)*

*Defined at line 3708 of ./engine/client/cl_game.cpp*

### FunnelSprite

*public void FunnelSprite(const float * org, int modelIndex, int reverse)*

*Defined at line 3713 of ./engine/client/cl_game.cpp*

### Implosion

*public void Implosion(const float * end, float radius, int count, float life)*

*Defined at line 3718 of ./engine/client/cl_game.cpp*

### LargeFunnel

*public void LargeFunnel(const float * org, int reverse)*

*Defined at line 3723 of ./engine/client/cl_game.cpp*

### LavaSplash

*public void LavaSplash(const float * org)*

*Defined at line 3728 of ./engine/client/cl_game.cpp*

### MultiGunshot

*public void MultiGunshot(const float * org, const float * dir, const float * noise, int count, int decalCount, int * decalIndices)*

*Defined at line 3733 of ./engine/client/cl_game.cpp*

### MuzzleFlash

*public void MuzzleFlash(const float * pos1, int type)*

*Defined at line 3738 of ./engine/client/cl_game.cpp*

### ParticleBox

*public void ParticleBox(const float * mins, const float * maxs, unsigned char r, unsigned char g, unsigned char b, float life)*

*Defined at line 3743 of ./engine/client/cl_game.cpp*

### ParticleBurst

*public void ParticleBurst(const float * pos, int size, int color, float life)*

*Defined at line 3748 of ./engine/client/cl_game.cpp*

### ParticleExplosion

*public void ParticleExplosion(const float * org)*

*Defined at line 3753 of ./engine/client/cl_game.cpp*

### ParticleExplosion2

*public void ParticleExplosion2(const float * org, int colorStart, int colorLength)*

*Defined at line 3758 of ./engine/client/cl_game.cpp*

### ParticleLine

*public void ParticleLine(const float * start, const float * end, unsigned char r, unsigned char g, unsigned char b, float life)*

*Defined at line 3763 of ./engine/client/cl_game.cpp*

### PlayerSprites

*public void PlayerSprites(int client, int modelIndex, int count, int size)*

*Defined at line 3768 of ./engine/client/cl_game.cpp*

### Projectile

*public void Projectile(const float * origin, const float * velocity, int modelIndex, int life, int owner, void (*)(struct tempent_s *, struct pmtrace_s *) hitcallback)*

*Defined at line 3773 of ./engine/client/cl_game.cpp*

### RicochetSound

*public void RicochetSound(const float * pos)*

*Defined at line 3778 of ./engine/client/cl_game.cpp*

### RicochetSprite

*public void RicochetSprite(const float * pos, struct model_s * pmodel, float duration, float scale)*

*Defined at line 3783 of ./engine/client/cl_game.cpp*

### RocketFlare

*public void RocketFlare(const float * pos)*

*Defined at line 3788 of ./engine/client/cl_game.cpp*

### RocketTrail

*public void RocketTrail(float * start, float * end, int type)*

*Defined at line 3793 of ./engine/client/cl_game.cpp*

### RunParticleEffect

*public void RunParticleEffect(const float * org, const float * dir, int color, int count)*

*Defined at line 3798 of ./engine/client/cl_game.cpp*

### ShowLine

*public void ShowLine(const float * start, const float * end)*

*Defined at line 3803 of ./engine/client/cl_game.cpp*

### SparkEffect

*public void SparkEffect(const float * pos, int count, int velocityMin, int velocityMax)*

*Defined at line 3808 of ./engine/client/cl_game.cpp*

### SparkShower

*public void SparkShower(const float * pos)*

*Defined at line 3813 of ./engine/client/cl_game.cpp*

### SparkStreaks

*public void SparkStreaks(const float * pos, int count, int velocityMin, int velocityMax)*

*Defined at line 3818 of ./engine/client/cl_game.cpp*

### Spray

*public void Spray(const float * pos, const float * dir, int modelIndex, int count, int speed, int spread, int rendermode)*

*Defined at line 3823 of ./engine/client/cl_game.cpp*

### Sprite_Explode

*public void Sprite_Explode(TEMPENTITY * pTemp, float scale, int flags)*

*Defined at line 3828 of ./engine/client/cl_game.cpp*

### Sprite_Smoke

*public void Sprite_Smoke(TEMPENTITY * pTemp, float scale)*

*Defined at line 3833 of ./engine/client/cl_game.cpp*

### Sprite_Spray

*public void Sprite_Spray(const float * pos, const float * dir, int modelIndex, int count, int speed, int iRand)*

*Defined at line 3838 of ./engine/client/cl_game.cpp*

### Sprite_Trail

*public void Sprite_Trail(int type, float * start, float * end, int modelIndex, int count, float life, float size, float amplitude, int renderamt, float speed)*

*Defined at line 3843 of ./engine/client/cl_game.cpp*

### Sprite_WallPuff

*public void Sprite_WallPuff(TEMPENTITY * pTemp, float scale)*

*Defined at line 3848 of ./engine/client/cl_game.cpp*

### StreakSplash

*public void StreakSplash(const float * pos, const float * dir, int color, int count, float speed, int velocityMin, int velocityMax)*

*Defined at line 3853 of ./engine/client/cl_game.cpp*

### TracerEffect

*public void TracerEffect(const float * start, const float * end)*

*Defined at line 3858 of ./engine/client/cl_game.cpp*

### UserTracerParticle

*public void UserTracerParticle(float * org, float * vel, float life, int colorIndex, float length, unsigned char deathcontext, void (*)(struct particle_s *) deathfunc)*

*Defined at line 3863 of ./engine/client/cl_game.cpp*

### TracerParticles

*public particle_t * TracerParticles(float * org, float * vel, float life)*

*Defined at line 3868 of ./engine/client/cl_game.cpp*

### TeleportSplash

*public void TeleportSplash(const float * org)*

*Defined at line 3873 of ./engine/client/cl_game.cpp*

### TempSphereModel

*public void TempSphereModel(const float * pos, float speed, float life, int count, int modelIndex)*

*Defined at line 3878 of ./engine/client/cl_game.cpp*

### TempModel

*public TEMPENTITY * TempModel(const float * pos, const float * dir, const float * angles, float life, int modelIndex, int soundtype)*

*Defined at line 3883 of ./engine/client/cl_game.cpp*

### DefaultSprite

*public TEMPENTITY * DefaultSprite(const float * pos, int spriteIndex, float framerate)*

*Defined at line 3888 of ./engine/client/cl_game.cpp*

### TempSprite

*public TEMPENTITY * TempSprite(float * pos, const float * dir, float scale, int modelIndex, int rendermode, int renderfx, float a, float life, int flags)*

*Defined at line 3893 of ./engine/client/cl_game.cpp*

### Draw_DecalIndex

*public int Draw_DecalIndex(int id)*

*Defined at line 3898 of ./engine/client/cl_game.cpp*

### Draw_DecalIndexFromName

*public int Draw_DecalIndexFromName(const char * name)*

*Defined at line 3903 of ./engine/client/cl_game.cpp*

### DecalShoot

*public void DecalShoot(int textureIndex, int entity, int modelIndex, float * position, int flags)*

*Defined at line 3908 of ./engine/client/cl_game.cpp*

### AttachTentToPlayer

*public void AttachTentToPlayer(int client, int modelIndex, float zoffset, float life)*

*Defined at line 3913 of ./engine/client/cl_game.cpp*

### KillAttachedTents

*public void KillAttachedTents(int client)*

*Defined at line 3918 of ./engine/client/cl_game.cpp*

### BeamCirclePoints

*public BEAM * BeamCirclePoints(int type, float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

*Defined at line 3923 of ./engine/client/cl_game.cpp*

### BeamEntPoint

*public BEAM * BeamEntPoint(int startEnt, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

*Defined at line 3928 of ./engine/client/cl_game.cpp*

### BeamEnts

*public BEAM * BeamEnts(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

*Defined at line 3933 of ./engine/client/cl_game.cpp*

### BeamFollow

*public BEAM * BeamFollow(int startEnt, int modelIndex, float life, float width, float r, float g, float b, float brightness)*

*Defined at line 3938 of ./engine/client/cl_game.cpp*

### BeamKill

*public void BeamKill(int deadEntity)*

*Defined at line 3943 of ./engine/client/cl_game.cpp*

### BeamLightning

*public BEAM * BeamLightning(float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed)*

*Defined at line 3948 of ./engine/client/cl_game.cpp*

### BeamPoints

*public BEAM * BeamPoints(float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

*Defined at line 3953 of ./engine/client/cl_game.cpp*

### BeamRing

*public BEAM * BeamRing(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

*Defined at line 3958 of ./engine/client/cl_game.cpp*

### CL_AllocDlight

*public dlight_t * CL_AllocDlight(int key)*

*Defined at line 3963 of ./engine/client/cl_game.cpp*

### CL_AllocElight

*public dlight_t * CL_AllocElight(int key)*

*Defined at line 3968 of ./engine/client/cl_game.cpp*

### CL_TempEntAlloc

*public TEMPENTITY * CL_TempEntAlloc(const float * org, struct model_s * model)*

*Defined at line 3973 of ./engine/client/cl_game.cpp*

### CL_TempEntAllocNoModel

*public TEMPENTITY * CL_TempEntAllocNoModel(const float * org)*

*Defined at line 3978 of ./engine/client/cl_game.cpp*

### CL_TempEntAllocHigh

*public TEMPENTITY * CL_TempEntAllocHigh(const float * org, struct model_s * model)*

*Defined at line 3983 of ./engine/client/cl_game.cpp*

### CL_TentEntAllocCustom

*public TEMPENTITY * CL_TentEntAllocCustom(const float * origin, struct model_s * model, int high, void (*)(struct tempent_s *, float, float) callback)*

*Defined at line 3988 of ./engine/client/cl_game.cpp*

### GetPackedColor

*public void GetPackedColor(short * packed, short color)*

*Defined at line 3993 of ./engine/client/cl_game.cpp*

### LookupColor

*public short LookupColor(unsigned char r, unsigned char g, unsigned char b)*

*Defined at line 3998 of ./engine/client/cl_game.cpp*

### DecalRemoveAll

*public void DecalRemoveAll(int textureIndex)*

*Defined at line 4003 of ./engine/client/cl_game.cpp*

### FireCustomDecal

*public void FireCustomDecal(int textureIndex, int entity, int modelIndex, float * position, int flags, float scale)*

*Defined at line 4008 of ./engine/client/cl_game.cpp*



