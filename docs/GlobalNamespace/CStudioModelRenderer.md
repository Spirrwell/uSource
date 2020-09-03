# class CStudioModelRenderer

*Defined at line 18 of ./game/client/StudioModelRenderer.h*

====================CStudioModelRenderer

====================



## Members

public double m_clTime

public double m_clOldTime

public int m_fDoInterp

public int m_fGaitEstimation

public int m_nFrameCount

public cvar_t * m_pCvarHiModels

public cvar_t * m_pCvarDeveloper

public cvar_t * m_pCvarDrawEntities

public cl_entity_t * m_pCurrentEntity

public model_t * m_pRenderModel

public player_info_t * m_pPlayerInfo

public int m_nPlayerIndex

public float m_flGaitMovement

public studiohdr_t * m_pStudioHeader

public mstudiobodyparts_t * m_pBodyPart

public mstudiomodel_t * m_pSubModel

public int m_nTopColor

public int m_nBottomColor

public model_t * m_pChromeSprite

public int m_nCachedBones

public char [128][32] m_nCachedBoneNames

public float [128][3][4] m_rgCachedBoneTransform

public float [128][3][4] m_rgCachedLightTransform

public float m_fSoftwareXScale

public float m_fSoftwareYScale

public float [3] m_vUp

public float [3] m_vRight

public float [3] m_vNormal

public float [3] m_vRenderOrigin

public int * m_pStudioModelCount

public int * m_pModelsDrawn

public float (*)[3][4] m_protationmatrix

public float (*)[3][4] m_paliastransform

public float (*)[128][3][4] m_pbonetransform

public float (*)[128][3][4] m_plighttransform



## Functions

### CStudioModelRenderer

*public void CStudioModelRenderer()*

*Defined at line 83 of ./game/client/StudioModelRenderer.cpp*

 Construction/Destruction

====================CStudioModelRenderer

====================

### ~CStudioModelRenderer

*public void ~CStudioModelRenderer()*

*Defined at line 111 of ./game/client/StudioModelRenderer.cpp*

====================~CStudioModelRenderer

====================

### Init

*public void Init()*

*Defined at line 59 of ./game/client/StudioModelRenderer.cpp*

 Initialization

====================Init

====================

### StudioDrawModel

*public int StudioDrawModel(int flags)*

*Defined at line 1076 of ./game/client/StudioModelRenderer.cpp*

 Public Interfaces

====================StudioDrawModel

====================

### StudioDrawPlayer

*public int StudioDrawPlayer(int flags, struct entity_state_s * pplayer)*

*Defined at line 1358 of ./game/client/StudioModelRenderer.cpp*

====================StudioDrawPlayer

====================

### StudioGetAnim

*public mstudioanim_t * StudioGetAnim(model_t * m_pSubModel, mstudioseqdesc_t * pseqdesc)*

*Defined at line 374 of ./game/client/StudioModelRenderer.cpp*

 Look up animation data for sequence

====================StudioGetAnim

====================

### StudioSetUpTransform

*public void StudioSetUpTransform(int trivial_accept)*

*Defined at line 441 of ./game/client/StudioModelRenderer.cpp*

 Interpolate model position and angles and set up matrices

====================StudioSetUpTransform

====================

### StudioSetupBones

*public void StudioSetupBones()*

*Defined at line 781 of ./game/client/StudioModelRenderer.cpp*

 Set up model bone positions

====================StudioSetupBones

====================

### StudioCalcAttachments

*public void StudioCalcAttachments()*

*Defined at line 1522 of ./game/client/StudioModelRenderer.cpp*

 Find final attachment points

====================StudioCalcAttachments

====================

### StudioSaveBones

*public void StudioSaveBones()*

*Defined at line 967 of ./game/client/StudioModelRenderer.cpp*

 Save bone matrices and names

====================StudioSaveBones

====================

### StudioMergeBones

*public void StudioMergeBones(model_t * m_pSubModel)*

*Defined at line 990 of ./game/client/StudioModelRenderer.cpp*

 Merge cached bones with current bones for model

====================StudioMergeBones

====================

### StudioEstimateInterpolant

*public float StudioEstimateInterpolant()*

*Defined at line 572 of ./game/client/StudioModelRenderer.cpp*

 Determine interpolation fraction

====================StudioEstimateInterpolant

====================

### StudioEstimateFrame

*public float StudioEstimateFrame(mstudioseqdesc_t * pseqdesc)*

*Defined at line 719 of ./game/client/StudioModelRenderer.cpp*

 Determine current frame for rendering

====================StudioEstimateFrame

====================

### StudioFxTransform

*public void StudioFxTransform(cl_entity_t * ent, float [3][4] transform)*

*Defined at line 675 of ./game/client/StudioModelRenderer.cpp*

 Apply special effects to transform matrix

====================Studio_FxTransform

====================

### StudioSlerpBones

*public void StudioSlerpBones(vec4_t [] q1, float [][3] pos1, vec4_t [] q2, float [][3] pos2, float s)*

*Defined at line 342 of ./game/client/StudioModelRenderer.cpp*

 Spherical interpolation of bones

====================StudioSlerpBones

====================

### StudioCalcBoneAdj

*public void StudioCalcBoneAdj(float dadt, float * adj, const byte * pcontroller1, const byte * pcontroller2, byte mouthopen)*

*Defined at line 121 of ./game/client/StudioModelRenderer.cpp*

 Compute bone adjustments( bone controllers )

====================StudioCalcBoneAdj

====================

### StudioCalcBoneQuaterion

*public void StudioCalcBoneQuaterion(int frame, float s, mstudiobone_t * pbone, mstudioanim_t * panim, float * adj, float * q)*

*Defined at line 188 of ./game/client/StudioModelRenderer.cpp*

 Get bone quaternions

====================StudioCalcBoneQuaterion

====================

### StudioCalcBonePosition

*public void StudioCalcBonePosition(int frame, float s, mstudiobone_t * pbone, mstudioanim_t * panim, float * adj, float * pos)*

*Defined at line 274 of ./game/client/StudioModelRenderer.cpp*

 Get bone positions

====================StudioCalcBonePosition

====================

### StudioCalcRotations

*public void StudioCalcRotations(float [][3] pos, vec4_t * q, mstudioseqdesc_t * pseqdesc, mstudioanim_t * panim, float f)*

*Defined at line 593 of ./game/client/StudioModelRenderer.cpp*

 Compute rotations

====================StudioCalcRotations

====================

### StudioRenderModel

*public void StudioRenderModel()*

*Defined at line 1547 of ./game/client/StudioModelRenderer.cpp*

 Send bones and verts to renderer

====================StudioRenderModel

====================

### StudioRenderFinal

*public void StudioRenderFinal()*

*Defined at line 1685 of ./game/client/StudioModelRenderer.cpp*

 Finalize rendering

====================StudioRenderFinal

====================

### StudioRenderFinal_Software

*public void StudioRenderFinal_Software()*

*Defined at line 1585 of ./game/client/StudioModelRenderer.cpp*

 GL&D3D vs. Software renderer finishing functions

====================StudioRenderFinal_Software

====================

### StudioRenderFinal_Hardware

*public void StudioRenderFinal_Hardware()*

*Defined at line 1630 of ./game/client/StudioModelRenderer.cpp*

====================StudioRenderFinal_Hardware

====================

### StudioPlayerBlend

*public void StudioPlayerBlend(mstudioseqdesc_t * pseqdesc, int * pBlend, float * pPitch)*

*Defined at line 411 of ./game/client/StudioModelRenderer.cpp*

 Player specific data Determine pitch and blending amounts for players

====================StudioPlayerBlend

====================

### StudioEstimateGait

*public void StudioEstimateGait(entity_state_t * pplayer)*

*Defined at line 1189 of ./game/client/StudioModelRenderer.cpp*

 Estimate gait frame for player

====================StudioEstimateGait

====================

### StudioProcessGait

*public void StudioProcessGait(entity_state_t * pplayer)*

*Defined at line 1260 of ./game/client/StudioModelRenderer.cpp*

 Process movement of player

====================StudioProcessGait

====================



