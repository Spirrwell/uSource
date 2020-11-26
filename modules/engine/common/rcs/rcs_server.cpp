#include "rcs_server.h"

rcs::CRcsRpcServer::CRcsRpcServer()
{

}

void rcs::CRcsRpcServer::ExportPublicService(int port, google::protobuf::Service *service)
{

}

void rcs::CRcsRpcServer::SetPublicServicesEnabled(bool enabled)
{

}

void rcs::CRcsRpcServer::ExportService(int port, google::protobuf::Service *service)
{

}

void rcs::CRcsRpcServer::AddAllowedIP(unsigned int ip)
{

}

void rcs::CRcsRpcServer::RemoveAllowedIP(unsigned int ip)
{

}

bool rcs::CRcsRpcServer::IsIPAuthorized(unsigned int ip)
{
	return false;
}

void rcs::CRcsRpcServer::SetStrict(bool strict)
{

}

