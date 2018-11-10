#include "Client.h"

Client & Client::startupWinsock()
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);

	int wsOk = WSAStartup(version, &data);

	try
	{
		if (wsOk)
		{
			throw runtime_error("Can't start Win Socket: " + to_string(wsOk));
		}

	}
	catch (const std::exception& e)
	{
		cout << "Error: " << e.what();
	}

	return *this;
}

Client & Client::initServerMetaData()
{	
	m_server.sin_family = AF_INET;
	m_server.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &m_server.sin_addr);

	return *this;
}

Client & Client::initSocket()
{
	m_outSocket = socket(AF_INET, SOCK_DGRAM, 0);

	return *this;
}

Client & Client::sendMsg()
{
	// Write out to socket
	auto sendOK = sendto(m_outSocket,
				  m_arg.c_str(),
				  static_cast<int>(m_arg.size()) + 1,
				  0,
				  (sockaddr*)&m_server,
				  sizeof(m_server));

	if (sendOK == SOCKET_ERROR)
	{
		cout << "That aint work!" << "\n";
	}

	return *this;
}

void Client::closeClient()
{
	closesocket(m_outSocket);
}
