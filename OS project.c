#include<stdio.h>



struct processes_in_queue
{	
	int qpriority, priority, burst_time, remain_time, arrival_time;
}queue1[4],queue2[4],queue3[4];



int mat[3],tbt[3],remain_tbt[3];
int n[3];
    

int rt=0,rc;
int rr;
int time_quant;

void round_robin_overall();
void priority_process();
void fcfs();
void round_robin();

int pt,pc,pr;

int ft,fc,fr;


int main()
{
 	
	printf("\t\t\tQUEUE 1\n");
	printf("Enter the number of processes in queue 1   ----   ");
    	scanf("%d",&n[0]);
    	
    	int sum=0,min=10000;
    	for(int i=0;i<n[0];i++)
    	{	
		printf("\n\nFOR PROCESS %d IN QUEUE 1\n",i+1);
        	printf("Enter the Priority of the Process %d   ----   ",i+1);
        	scanf("%d",&queue1[i].priority);
		printf("Enter the Arrival time of the process %d   ----   ",i+1);
		scanf("%d",&queue1[i].arrival_time);
		printf("Enter the Burst time of the process %d   ----   ",i+1);
		scanf("%d",&queue1[i].burst_time);
        	queue1[i].remain_time=queue1[i].burst_time;
        	sum=sum+queue1[i].burst_time;
        	if(queue1[i].arrival_time<min)
        	{
            		min=queue1[i].arrival_time;
        	}
    	}
    	tbt[0]=sum;
    	remain_tbt[0]=tbt[0];
    	mat[0]=min;
    	printf("\nTotal Burst time of the processes in queue 1   ----   %d",tbt[0]);
	printf("\nMinimum Arrival time among the processes in Queue 1   ----   %d\n\n\n",mat[0]);
    	
	rr=n[0];

    	
	
	printf("\t\t\tQUEUE 2\n");
	printf("\n\nEnter the number of processes in queue 2   ----    ");
    	scanf("%d",&n[1]);
    	
        sum=0;
	min=10000;
    	for(int i=0;i<n[1];i++)
    	{	
		printf("\n\nFOR PROCESS %d IN QUEUE 2\n",i+1);
        	printf("Enter the Priority of the Process %d   ----   ",i+1);
        	scanf("%d",&queue2[i].priority);
		printf("Enter the Arrival time of the process %d   ----   ",i+1);
		scanf("%d",&queue2[i].arrival_time);
		printf("Enter the Burst time of the process %d   ----   ",i+1);
		scanf("%d",&queue2[i].burst_time);
        	queue2[i].remain_time=queue2[i].burst_time;
        	sum=sum+queue2[i].burst_time;
        	if(queue2[i].arrival_time<min)
        	{
            		min=queue2[i].arrival_time;
        	}
    	}
    	tbt[1]=sum;
    	remain_tbt[1]=tbt[1];
    	mat[1]=min;
    	printf("\nTotal Burst time of the processes in queue 2   ----   %d",tbt[1]);
	printf("\nMinimum Arrival time among the processes in Queue 2   ----   %d\n\n\n",mat[1]);
    	
    	pr=n[1];



	printf("\t\t\tQUEUE 3\n");
    	printf("\n\nEnter the number of processes in queue 3   ----   ");
    	scanf("%d",&n[2]);
    	
	sum=0;
	min=10000;
    	for(int i=0;i<n[2];i++)
    	{	
		printf("\n\nFOR PROCESS %d IN QUEUE 3\n",i+1);
        	printf("Enter the Priority of the Process %d   ----   ",i+1);
        	scanf("%d",&queue3[i].priority);
		printf("Enter the Arrival time of the process %d   ----   ",i+1);
		scanf("%d",&queue3[i].arrival_time);
		printf("Enter the Burst time of the process %d   ----   ",i+1);
		scanf("%d",&queue3[i].burst_time);
        	queue3[i].remain_time=queue3[i].burst_time;
        	sum=sum+queue3[i].burst_time;
        	if(queue3[i].arrival_time<min)
        	{
            		min=queue3[i].arrival_time;
        	}
    	}
    	tbt[2]=sum;
    	remain_tbt[2]=tbt[2];
    	mat[2]=min;
    	printf("\nTotal Burst time of the processes in queue 3   ----   %d",tbt[2]);
	printf("\nMinimum Arrival time among the processes in Queue 3   ----   %d\n\n\n",mat[2]);

    	fr=n[2];

    	printf("Enter Time Quantum for round robin Scheduling   ----   "); 
    	scanf("%d",&time_quant);

    	round_robin_overall();
    
}





void round_robin_overall()

{
    	int time=0,flag=0,count=0;
    	int r_time=20, wait_time=0, tat=0;
    	printf("\n\nQueue Number\tTotal remaining Burst Time\tProcess\t\tProcess remaining time\n\n"); 

    	if(mat[0]<=mat[1]&& mat[0]<=mat[2])
    	{
        	count=0;
    	}
    	else if(mat[1]<=mat[2])
    	{
        	count=1;
    	}
    	else
    	count=2;

    	for(time=0;r_time!=0;) 
    	{ 
        	if(remain_tbt[count]<=time_quant && remain_tbt[count]>0) 
        	{ 
        		time+=remain_tbt[count]; 
        		remain_tbt[count]=0; 
        		flag=1; 
        	} 
        	else if(remain_tbt[count]>0) 
        	{ 
        		remain_tbt[count]-=time_quant; 
        		time+=time_quant; 
        	} 
        	if(remain_tbt[count]==0 && flag==1) 
        	{ 
        		r_time--; 
        		wait_time+=time-mat[count]-tbt[count]; 
        		tat+=time-mat[count]; 
        		flag=0; 
        	} 

        	printf("Queue %d\t\t\t%d\t\t\t",count+1,remain_tbt[count]);
        
        	if(count==0)
        	{
            		round_robin();
        	}
        	else if(count==1)
        	{
            		priority_process();
        	}
        	else
        	{
            		fcfs();
        	}



	        if(count==2) 
	        {
            		count=0;
            		printf("\n\n\n");
        	}
        	else if(mat[count+1]<=time) 
        	count++; 
        	else 
        	count=0; 
    	} 
}





void fcfs()
{
        
        int flag=0;
        for(int i=0;i<n[2];i++)
        {
        	if(queue3[i].remain_time>0)
       		{
            		fc=i;
            		break;
        	}
        }
    	if(fr!=0) 
    	{ 
        	if(queue3[fc].remain_time<=time_quant && queue3[fc].remain_time>0) 
        	{ 
       		        ft+=queue3[fc].remain_time; 
            		queue3[fc].remain_time=0; 
            		flag=1; 
       		} 
        	else if(queue3[fc].remain_time>0) 
        	{ 
            		queue3[fc].remain_time-=time_quant; 
            		ft+=time_quant; 
        	} 

        	if(queue3[fc].remain_time==0 && flag==1) 
        	{ 
            		pr--;
            		flag=0; 
        	} 
      		printf("Process%d\t\t %d \n",fc+7,queue3[fc].remain_time);
    	}
}






void round_robin()
{
    
	int flag=0;
        int min=1000;
        if(rt==0)
        for(int i=0;i<n[0];i++)
        {
        	if(queue1[i].arrival_time<min)
        	{
        	        min=queue1[i].arrival_time;
            	        rc=i;
    	        }
        }
    	
	if(rr!=0) 
        { 
        	if(queue1[rc].remain_time<=time_quant && queue1[rc].remain_time>0) 
        	{ 
       		         remain_tbt[0]+=time_quant-queue1[rc].remain_time;
        
       			 rt+=queue1[rc].remain_time; 
     		         queue1[rc].remain_time=0; 
        		 flag=1; 
        	} 
       	       
	        else if(queue1[rc].remain_time>0) 
        	{ 
        		queue1[rc].remain_time-=time_quant; 
        		rt+=time_quant; 
        	} 

        	if(queue1[rc].remain_time==0 && flag==1) 
        	{ 
        		rr--; 
       			flag=0; 
        	} 

        	printf("Process%d\t\t %d \n",rc+1,queue1[rc].remain_time);
       		if(rc==n[0]-1) 
        	{
        	        rc=0;
            		while(queue1[rc].remain_time==0)
                	{
                    		rc++;
			}    
	        }
		
		else if(queue1[rc+1].arrival_time<=rt) 
                {
    	                rc++;
                
            	        while(queue1[rc].remain_time==0)
                	rc++; 
                }
                else 
                rc=0;
        
        	
        } 
         
    


}






void priority_process()
{
	
        int flag=0;
        int pty=1000;
        for(int i=0;i<n[1];i++)
        {
        	if(queue2[i].priority<pty && queue2[i].remain_time>0)
        	{
                        pty=queue2[i].priority;
                	pc=i;
        	}
    	}
        if(pr!=0) 
        { 
        	if(queue2[pc].remain_time<=time_quant && queue2[pc].remain_time>0) 
        	{ 
                      pt+=queue2[pc].remain_time; 
            	      queue2[pc].remain_time=0; 
                      flag=1; 
        	} 
        	else if(queue2[pc].remain_time>0) 
        	{ 
            	      queue2[pc].remain_time-=time_quant; 
                      pt+=time_quant; 
        	} 

        	if(queue2[pc].remain_time==0 && flag==1) 
        	{ 
            		pr--; 
              		flag=0; 
       		} 

        	printf("Process%d\t\t %d \n",pc+4,queue2[pc].remain_time);        
        }    
}


