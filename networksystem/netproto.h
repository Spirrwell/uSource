/*
 *
 * netproto.h - Networksystem protocol
 *
 */
#pragma once

namespace NetworkSystem
{

#pragma pack(1)

	enum {
		HDR_USRMSG, /* Usermessage */
		HDR_VARUPD, /* Var update */
		HDR_ACTION, /* Networked actions */
	};

	struct msg_hdr_t
	{
		unsigned int type; /* HDR_USRMSG, etc. */
	};

	struct usrmsg_hdr_t
	{
		unsigned int id;
		unsigned int length;
	};

	struct varupd_hdr_t
	{

	};

	struct action_hdr_t
	{
		char action[32]; /* The action name */
	};

#pragma pack()
}