#pragma once

#include "rcs.h"

#include <google/protobuf/service.h>

BEGIN_RCS_NAMESPACE

class CRcsRpcServer
{
private:
	bool m_strict;
	bool m_publicEnabled;
public:
	CRcsRpcServer();

	/* Exports a public service. e.g. one that can be accessed by anyone */
	void ExportPublicService(int port, google::protobuf::Service* service);

	/* When set to false, public services will be disabled */
	void SetPublicServicesEnabled(bool enabled);
	bool PublicServicesEnabled() const { return m_publicEnabled; }

	/* Exports a private service on a port. Only authorized IPs can use this */
	void ExportService(int port, google::protobuf::Service* service);

	/* Adds a IP address to the allowed IPs list */
	void AddAllowedIP(unsigned int ip);
	void RemoveAllowedIP(unsigned int ip);

	/* Returns true if the IP is authorized */
	bool IsIPAuthorized(unsigned int ip);

	/* When set to true, strict-mode only allows authorized IPs to access private interfaces */
	void SetStrict(bool strict);
	bool Strict() const { return m_strict; };
};

END_RCS_NAMESPACE