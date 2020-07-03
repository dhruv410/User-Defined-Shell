void back(int job[],char st[])
{
	int jn = atoi(st);
	int pd = job[jn-1];
	kill(pd,SIGCONT);
}