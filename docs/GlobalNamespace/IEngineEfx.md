# class IEngineEfx

*Defined at line 9 of ./engine/efx_int.h*

Inherits from IAppInterface



## Functions

### AllocParticle

*public particle_t * AllocParticle(void (*)(struct particle_s *, float) callback)*

### BlobExplosion

*public void BlobExplosion(const float * org)*

### Blood

*public void Blood(const float * org, const float * dir, int pcolor, int speed)*

### BloodSprite

*public void BloodSprite(const float * org, int colorindex, int modelIndex, int modelIndex2, float size)*

### BloodStream

*public void BloodStream(const float * org, const float * dir, int pcolor, int speed)*

### BreakModel

*public void BreakModel(const float * pos, const float * size, const float * dir, float random, float life, int count, int modelIndex, char flags)*

### Bubbles

*public void Bubbles(const float * mins, const float * maxs, float height, int modelIndex, int count, float speed)*

### BubbleTrail

*public void BubbleTrail(const float * start, const float * end, float height, int modelIndex, int count, float speed)*

### BulletImpactParticles

*public void BulletImpactParticles(const float * pos)*

### EntityParticles

*public void EntityParticles(struct cl_entity_s * ent)*

### Explosion

*public void Explosion(float * pos, int model, float scale, float framerate, int flags)*

### FizzEffect

*public void FizzEffect(struct cl_entity_s * pent, int modelIndex, int density)*

### FireField

*public void FireField(float * org, int radius, int modelIndex, int count, int flags, float life)*

### FlickerParticles

*public void FlickerParticles(const float * org)*

### FunnelSprite

*public void FunnelSprite(const float * org, int modelIndex, int reverse)*

### Implosion

*public void Implosion(const float * end, float radius, int count, float life)*

### LargeFunnel

*public void LargeFunnel(const float * org, int reverse)*

### LavaSplash

*public void LavaSplash(const float * org)*

### MultiGunshot

*public void MultiGunshot(const float * org, const float * dir, const float * noise, int count, int decalCount, int * decalIndices)*

### MuzzleFlash

*public void MuzzleFlash(const float * pos1, int type)*

### ParticleBox

*public void ParticleBox(const float * mins, const float * maxs, unsigned char r, unsigned char g, unsigned char b, float life)*

### ParticleBurst

*public void ParticleBurst(const float * pos, int size, int color, float life)*

### ParticleExplosion

*public void ParticleExplosion(const float * org)*

### ParticleExplosion2

*public void ParticleExplosion2(const float * org, int colorStart, int colorLength)*

### ParticleLine

*public void ParticleLine(const float * start, const float * end, unsigned char r, unsigned char g, unsigned char b, float life)*

### PlayerSprites

*public void PlayerSprites(int client, int modelIndex, int count, int size)*

### Projectile

*public void Projectile(const float * origin, const float * velocity, int modelIndex, int life, int owner, void (*)(struct tempent_s *, struct pmtrace_s *) hitcallback)*

### RicochetSound

*public void RicochetSound(const float * pos)*

### RicochetSprite

*public void RicochetSprite(const float * pos, struct model_s * pmodel, float duration, float scale)*

### RocketFlare

*public void RocketFlare(const float * pos)*

### RocketTrail

*public void RocketTrail(float * start, float * end, int type)*

### RunParticleEffect

*public void RunParticleEffect(const float * org, const float * dir, int color, int count)*

### ShowLine

*public void ShowLine(const float * start, const float * end)*

### SparkEffect

*public void SparkEffect(const float * pos, int count, int velocityMin, int velocityMax)*

### SparkShower

*public void SparkShower(const float * pos)*

### SparkStreaks

*public void SparkStreaks(const float * pos, int count, int velocityMin, int velocityMax)*

### Spray

*public void Spray(const float * pos, const float * dir, int modelIndex, int count, int speed, int spread, int rendermode)*

### Sprite_Explode

*public void Sprite_Explode(TEMPENTITY * pTemp, float scale, int flags)*

### Sprite_Smoke

*public void Sprite_Smoke(TEMPENTITY * pTemp, float scale)*

### Sprite_Spray

*public void Sprite_Spray(const float * pos, const float * dir, int modelIndex, int count, int speed, int iRand)*

### Sprite_Trail

*public void Sprite_Trail(int type, float * start, float * end, int modelIndex, int count, float life, float size, float amplitude, int renderamt, float speed)*

### Sprite_WallPuff

*public void Sprite_WallPuff(TEMPENTITY * pTemp, float scale)*

### StreakSplash

*public void StreakSplash(const float * pos, const float * dir, int color, int count, float speed, int velocityMin, int velocityMax)*

### TracerEffect

*public void TracerEffect(const float * start, const float * end)*

### UserTracerParticle

*public void UserTracerParticle(float * org, float * vel, float life, int colorIndex, float length, unsigned char deathcontext, void (*)(struct particle_s *) deathfunc)*

### TracerParticles

*public particle_t * TracerParticles(float * org, float * vel, float life)*

### TeleportSplash

*public void TeleportSplash(const float * org)*

### TempSphereModel

*public void TempSphereModel(const float * pos, float speed, float life, int count, int modelIndex)*

### TempModel

*public TEMPENTITY * TempModel(const float * pos, const float * dir, const float * angles, float life, int modelIndex, int soundtype)*

### DefaultSprite

*public TEMPENTITY * DefaultSprite(const float * pos, int spriteIndex, float framerate)*

### TempSprite

*public TEMPENTITY * TempSprite(float * pos, const float * dir, float scale, int modelIndex, int rendermode, int renderfx, float a, float life, int flags)*

### Draw_DecalIndex

*public int Draw_DecalIndex(int id)*

### Draw_DecalIndexFromName

*public int Draw_DecalIndexFromName(const char * name)*

### DecalShoot

*public void DecalShoot(int textureIndex, int entity, int modelIndex, float * position, int flags)*

### AttachTentToPlayer

*public void AttachTentToPlayer(int client, int modelIndex, float zoffset, float life)*

### KillAttachedTents

*public void KillAttachedTents(int client)*

### BeamCirclePoints

*public BEAM * BeamCirclePoints(int type, float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

### BeamEntPoint

*public BEAM * BeamEntPoint(int startEnt, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

### BeamEnts

*public BEAM * BeamEnts(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

### BeamFollow

*public BEAM * BeamFollow(int startEnt, int modelIndex, float life, float width, float r, float g, float b, float brightness)*

### BeamKill

*public void BeamKill(int deadEntity)*

### BeamLightning

*public BEAM * BeamLightning(float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed)*

### BeamPoints

*public BEAM * BeamPoints(float * start, float * end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

### BeamRing

*public BEAM * BeamRing(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b)*

### CL_AllocDlight

*public dlight_t * CL_AllocDlight(int key)*

### CL_AllocElight

*public dlight_t * CL_AllocElight(int key)*

### CL_TempEntAlloc

*public TEMPENTITY * CL_TempEntAlloc(const float * org, struct model_s * model)*

### CL_TempEntAllocNoModel

*public TEMPENTITY * CL_TempEntAllocNoModel(const float * org)*

### CL_TempEntAllocHigh

*public TEMPENTITY * CL_TempEntAllocHigh(const float * org, struct model_s * model)*

### CL_TentEntAllocCustom

*public TEMPENTITY * CL_TentEntAllocCustom(const float * origin, struct model_s * model, int high, void (*)(struct tempent_s *, float, float) callback)*

### GetPackedColor

*public void GetPackedColor(short * packed, short color)*

### LookupColor

*public short LookupColor(unsigned char r, unsigned char g, unsigned char b)*

### DecalRemoveAll

*public void DecalRemoveAll(int textureIndex)*

### FireCustomDecal

*public void FireCustomDecal(int textureIndex, int entity, int modelIndex, float * position, int flags, float scale)*



