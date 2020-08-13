/**
 *
 * game_int.h - Common game interfaces
 *
 */
#pragma once

#include "appframework.h"

#define IGAMEPRESENCE_001	 "IGamePresence001"
#define IIGAMEPRESENCE_INTERFACE IIGAMEPRESENCE_001

class IGamePresence : public IAppSystem
{
public:
	virtual void ClearPresence() = 0;

	virtual void SetGameState(const char* state)		= 0;
	virtual void SetGameDetails(const char* details)	= 0;
	virtual void SetStartTimestamp(unsigned long long time) = 0;
	virtual void SetEndTimestemp(unsigned long long time)	= 0;
};