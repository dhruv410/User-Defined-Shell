void kjob(char str[], char str1[], int job[])
{
	int i = atoi(str);
	int j = atoi(str1);
	int s=0;
	s = job[i-1];
	if(s==-1)
		return ;
	kill(s,j);
}