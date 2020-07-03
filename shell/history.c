#define len 100000
struct node{
    char *val;
    struct node *next;
    struct node *prev;
};
struct node *enque(struct node *rear, char data[len])
{
    struct node *q=(struct node *)malloc(sizeof(struct node));
    q->next=NULL;
    // strcpy(q->val,data);
    q->val = data;
    q->prev=NULL;
    if(rear==NULL)
    rear=q;
    else
    {
        rear->prev=q;
        q->next=rear;
        rear=q;   
    }
    return rear;
}
struct node *deque(struct node *front)
{
    if(front==NULL||front->prev==NULL)
    return NULL;
    struct node *q=front->prev;
    free(front);
    front=q;
    return front;
}

struct node *hw(int counter, struct node *rear, struct node *front, char *str1,char *xl)
{
    // printf("%d ",counter);
    if(counter<20)
    {
        counter++;
        if(rear==NULL)
        {
            // printf("k");
            rear = enque(rear, str1);
            front = rear;
        }
        else 
            rear = enque(rear,str1);
    }
    else 
    {
        front = deque(front);
        rear = enque(rear,str1);
    }
    char sk[len],file2[len],file1[len];
    sprintf(file2,"%s/history.txt",xl);
    // printf("%s",file2);
    sprintf(file1,"%s/point.txt",xl);
    FILE *fp,*fp1;
    // int f2;
    // f2 = open(file2, O_WRONLY | O_CREAT, 0644);
    fp = fopen(file2,"w");
    if(fp==NULL)
    {
        perror("error");
    }
    struct node *o1=rear;
    struct node *o2=front;
    // printf("**%s\n ",o1->val);
    // printf("x");
    int x = 0;
    char *ch = "\n";

    while(o2!=NULL)
    {
        int lo = strlen(o2->val);
        // printf("^^%s",o2->val);
        // write(f2,sk,sizeof(char)*strlen(sk));
        if((o2->val)[lo-1]=='\n')
            fprintf(fp,"%s",o2->val);
        else 
            fprintf(fp,"%s\n",o2->val);

        o2=o2->prev;
    }
    fclose(fp);
    fp1 = fopen(file1,"w");
    fprintf(fp1,"%p",&front);
    fprintf(fp1,"%p",&rear);
    // printf("%p",&front);

    struct node *gk;
    gk = rear;
    gk->prev = front;
    return gk;
}
void hp(char *st, char *xl)
{
    int sum = 0;
    sum = atoi(st);
    char sk[len],file2[len];
    sprintf(file2,"%s/history.txt",xl);
    FILE *fp;
    fp = fopen(file2,"r");
    int cnt =0;
    if(fp==NULL)
    {
        perror("");
        return ;
    }
    else 
    {
        int p8=0;
        size_t p7=0;
        char buf[30][100000],*stri=NULL;
        ssize_t read;
        // printf("sum =%d ",sum);
        while((read=getline(&stri,&p7,fp ))!=-1)
        {
            strcpy(buf[p8],stri);
            p8++;
            fflush(stdout);
        }
        fclose(fp);
        if(stri)
            free(stri);
        if(sum>p8)
        {
            for(int i=0;i<p8;i++)
            {
                printf("%s",buf[i]);
            }
        }
        else 
        {
            for(int i=p8-sum;i<p8;i++)
                printf("%s",buf[i]);
        }
    }
    return ;
}