#include "game_shared.h"
#include "enginecallback.h"
#include "c_base_entity.h"

edict_t *EHANDLE::Get( void )
{
	if( m_pent )
	{
		if( m_pent->serialnumber == m_serialnumber )
			return m_pent;
		else
			return NULL;
	}
	return NULL;
}

edict_t *EHANDLE::Set( edict_t *pent )
{
	if( pent )
	{
		m_pent = pent;
		m_serialnumber = m_pent->serialnumber;
	}
	else
	{
		m_pent = NULL;
		m_serialnumber = 0;
	}
	return pent;
}

EHANDLE::operator CBaseEntity *()
{
	return (CBaseEntity *)GET_PRIVATE( this->Get() );
}

CBaseEntity *EHANDLE::operator = ( CBaseEntity *pEntity )
{
	if( pEntity )
	{
		m_pent = ENT( pEntity->pev );
		if( m_pent )
			m_serialnumber = m_pent->serialnumber;
	}
	else
	{
		m_pent = NULL;
		m_serialnumber = 0;
	}
	return pEntity;
}

EHANDLE::operator int ()
{
	return this->Get() != NULL;
}

CBaseEntity * EHANDLE::operator -> ()
{
	return (CBaseEntity *)GET_PRIVATE( this->Get() );
}