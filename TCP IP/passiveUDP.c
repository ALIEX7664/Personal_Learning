int passivesock(const char *service, const char *transport, int qlen);

int passiveUDP(const char *service)
{
	return passivesock(service, "udp", 0);
}