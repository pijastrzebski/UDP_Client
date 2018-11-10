#include "Client.h"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		Client client(argv[1]);

		client.startupWinsock()
			  .initServerMetaData()
			  .initSocket()
			  .sendMsg()
			  .closeClient();
	}
}