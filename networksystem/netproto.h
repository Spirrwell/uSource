/*
 *
 * netproto.h - Networksystem protocol
 *
 */
#pragma once

#include "reflection.h"

namespace NetworkSystem
{
	struct usrmsg_hdr_t;
	struct varupd_hdr_t;
	struct action_hdr_t;
#pragma pack(1)

	enum {
		HDR_USRMSG, /* Usermessage */
		HDR_VARUPD, /* Var update */
	};

	struct msg_hdr_t
	{
		unsigned short type; /* HDR_USRMSG, etc. */
	};

	struct usrmsg_hdr_t
	{
		unsigned int id;
		unsigned int length;
	};

	struct varupd_hdr_t
	{

	};

	/* Description for a class that is to be updated */
	struct varupd_desc_t
	{

	};

#pragma pack()
}

