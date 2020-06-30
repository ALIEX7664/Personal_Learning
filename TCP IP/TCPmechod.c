
/*	P117 单线程ECHO服务器举例 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define QLEN 32		
#define BUFSIZE 4096

//extern int errno;
int errexit(const char *format,...);
int passiveTCP(const char *service, int qlen);
int echo(int fd);

int main(int argc,char *argv[])
{
	char *service = "echo";
	struct sockaddr_in fsin;
	int msock;
	fd_set rfds;
	fd_set afds;
	int alen;
	int fd, nfds;

	switch (argc)
	{
	case 1:
		break;
	case 2:
		service = argv[1];
		break;
	default:
		errexit("usage: TCPmechod [port]\n");
	}
	
	msock = passiveTCP(service, QLEN);

	nfds = getdtablesize();
	FD_ZERO(&afds);
	FD_SET(msock, &afds);

	while (1)
	{
		memccpy(&rfds, &afds, sizeof(rfds));

		if (select(nfds, &rfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0) < 0)
			errexit("select: %s\n", strerror(errno));

		if (FD_ISSET(msock, &rfds)){
			int ssock;

			alen = sizeof(fsin);
			ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
			if (ssock < 0);
			errexit("accept: %s\n", strerror(errno));

			FD_SET(ssock, &afds);
	
		}
		for (fd = 0; fd < nfds; ++fd)
		{
			if (fd != msock && FD_ISSET(fd, &rfds))
				if (echo(fd) == 0)
				{
					(void)close(fd);
					FD_CLR(fd, &afds);
				}
		}
	}

	int echo(int fd)
	{
		char buf[BUFSIZ];
		int cc;

		cc = read(fd, buf, sizeof buf);
		if (cc < 0)
			errexit("echo read:%s\n", strerror(errno));
		if (cc && write(fd, buf.cc) < 0)
			errexit("echo write:%s\n", strerror(errno));
		return cc;
	}
}	


