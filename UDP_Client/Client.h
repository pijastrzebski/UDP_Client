#pragma once

#include <iostream>
#include <string>
#include <WS2tcpip.h> // win sockets lib

#pragma comment (lib, "ws2_32.lib")

using namespace std;

class Client
{
public:
	Client(string&& arg) : m_arg(std::move(arg)) {}
	~Client() = default;

	Client& startupWinsock();
	Client& initServerMetaData();
	Client& initSocket();
	Client& sendMsg();

	void closeClient();

private:
	string      m_arg;
	sockaddr_in m_server;
	SOCKET      m_outSocket;
};

