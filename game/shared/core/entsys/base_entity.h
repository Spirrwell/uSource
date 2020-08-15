/*
 *
 * base_entity.h - Base for all entity classes
 *
 */
#pragma once

#include "public/reflection.h"

#include "game.h"

class CBaseEntity2
{
public:

	/* Basic events */
	virtual void Spawn() {};
	virtual void Precache() {};


	/* Entity type checking */
	virtual bool IsNPC() const { return false; }
	virtual bool IsPlayer() const { return false; }
	virtual bool IsWorld() const { return false; }
	virtual bool IsWeapon() const { return false; }
	virtual bool IsItem() const { return false; }
	virtual bool IsNetClient() const { return false; }

	/* State checking */
	virtual bool IsFrozen() const { return false; }
	virtual bool IsMoving() const { return false; }
	virtual bool IsSneaking() const { return false; }
	virtual bool IsInWorld() const { return false; }
	virtual bool IsAlive() const { return false; }


};