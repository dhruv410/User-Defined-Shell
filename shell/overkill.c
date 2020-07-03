void overkill(int job[],char name[][100])
{
	for(int i = 0; i < 100 ;i++)
	{
		if(job[i]!=-1)
		{
			kill(job[i],9);
			// job[i]=-1;
		}
	}
}