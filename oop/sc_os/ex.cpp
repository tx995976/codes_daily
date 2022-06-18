#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iostream>

const int max_process = 100;
const int max_core = 4;
const int wait = 1;
const int run = 2;
const int finish = 3;
const int plan = -1;
int time_now = 0;

struct Proc{
	int pid;
	char name[10];
	int need_time;
	int exec_time = 0;
	int start_time = -1;
	int end_time = -1;
	int priority = 1;
	int status = -1;
};

struct Core{
	Proc *proc;
	int cpu_time;
};

struct Proc_ptr{
	Proc *p = nullptr;
	Proc_ptr *next = nullptr;
	Proc_ptr *prev = nullptr;
};

struct Proc_queue{
	Proc_ptr *head = nullptr;
	Proc_ptr *tail = nullptr;
	bool (*cmp)(Proc_ptr *a,Proc_ptr *b);
	
	void push(Proc *in){
		if(head == nullptr){
			head = new Proc_ptr;
			head->p = in;
			tail = head;
			return;
		}
		Proc_ptr *tmp = head;
		Proc_ptr *new_node = new Proc_ptr;
		new_node->p = in;
		
		while(tmp != nullptr){
			if(cmp(new_node,tmp)){
				if(tmp == head){
					new_node->next = head;
					head->prev = new_node;
					head = new_node;
					return;
				}
				else{
					new_node->next = tmp;
					new_node->prev = tmp->prev;
					tmp->prev->next = new_node;
					tmp->prev = new_node;
					return;
				}
			}
			tmp = tmp->next;
		}
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}

	void push_back(Proc *in){
		if(head == nullptr){
			head = new Proc_ptr;
			head->p = in;
			tail = head;
			return;
		}
		Proc_ptr *tmp = new Proc_ptr;
		tmp->p = in;
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}

	Proc* top(){
		return head->p;
	}

	void pop(){
		if(head == nullptr) return;
		Proc_ptr *tmp = head;
		head = head->next;
		delete tmp;
	}

	bool empty(){
		return head == nullptr;
	}
};
//////////////////////////////////////


Proc *proc_list[max_process];
Core run_list[max_core];
Proc_queue plan_list,wait_list;

int proc_num = 0;

///////////////////////////////////////

void show_all_proc(){
	 printf("pid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tstatus\n");
	 for(int i = 0;i < max_process;i++){
	 	if(proc_list[i] == nullptr) continue;
	 	printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",
		 	proc_list[i]->pid,
	 		proc_list[i]->name,
	 		proc_list[i]->exec_time,
	 		proc_list[i]->need_time,
	 		proc_list[i]->start_time,
	 		proc_list[i]->end_time,
	 		proc_list[i]->priority,
	 		proc_list[i]->status == wait ? "wait" : proc_list[i]->status == run ? "run" : proc_list[i]->status == finish ? "finish" : "plan"
			);
	 }
}

void print_proc_list(){
	printf("\ntime:%d\n",time_now);
	printf("plan_list:\n");
	printf("pid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tstatus\n");
	Proc_ptr *tmp = plan_list.head;
	while(tmp != nullptr){
		printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",
			tmp->p->pid,
			tmp->p->name,
			tmp->p->exec_time,
			tmp->p->need_time,
			tmp->p->start_time,
			tmp->p->end_time,
			tmp->p->priority,
			"plan"
			);
		tmp = tmp->next;
	}
    printf("\nwait_list:\n");
	printf("pid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tstatus\n");
	tmp = wait_list.head;
	while(tmp != nullptr){
		printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",
				tmp->p->pid,
				tmp->p->name,
				tmp->p->exec_time,
				tmp->p->need_time,
				tmp->p->start_time,
				tmp->p->end_time,
				tmp->p->priority,
				"wait"
			);
		tmp = tmp->next;
	}
	printf("\nrun_list:\n");
	printf("\tpid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tcpu_time\tstatus\n");
	for(int i = 0;i < max_core;i++){
	 	printf("core %d: ",i);
		if(run_list[i].proc != nullptr){
			printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",
					run_list[i].proc->pid,
					run_list[i].proc->name,
					run_list[i].proc->exec_time,
					run_list[i].proc->need_time,
					run_list[i].proc->start_time,
					run_list[i].proc->end_time,
					run_list[i].proc->priority,
					run_list[i].cpu_time,
					"run"
				);
		}
		else
			printf("\n");
	 }
	 system("pause");
	 system("cls");
}
// type = 1 : wait -> run , type = 2 : run -> wait 
// type = 3 : plan -> wait, type = 4 : run -> finish 
void show_dispatch(Proc *p,int type){
	printf("pid: %d\tname: %s\ttype: %s\n",
			p->pid,
			p->name,
			type == 1 ? "wait -> run" : type == 2 ? "run -> wait" : type == 3 ? "plan -> wait" : "run -> finish"
			);

}
//////////////////////////////////////////
bool new_process(Proc *new_p){
	bool flag = 0;
	for(int i = 0;i < max_process;i++){
		if(proc_list[i] == nullptr){
			proc_list[i] = new_p;
			new_p->pid = i;
			flag = 1;
			break;
		}
	}
	if(!flag) 
		return 0;
    if(new_p->start_time <= time_now){
		new_p->status = wait;
		wait_list.push(new_p);
	}
	else{
		plan_list.push(new_p);
	}
	proc_num++;
	return 1;
}

int init_test(int num){
	srand(time(NULL));
	for(int i = 0;i < num;i++){
		Proc *new_p = new Proc;
		new_p->start_time = rand()%2;
		new_p->need_time = rand()%4 + 1;
		new_p->priority = 1;
		sprintf(new_p->name,"proc_%d",i);
		new_process(new_p);
	}
	return 0;
}

//type = 1 priority, type = 2 start_time, type = 3 round;
bool step_time(int type){
	//scan run_list
	for(int i = 0;i < max_core;i++){
		if(wait_list.empty())
				break;
		if(run_list[i].proc == nullptr){
			run_list[i].proc = wait_list.top();
			if(type == 2)
				run_list[i].cpu_time = run_list[i].proc->need_time;
			else
				run_list[i].cpu_time = run_list[i].proc->priority;
			run_list[i].proc->status = run;
			show_dispatch(run_list[i].proc,1);
			wait_list.pop();
		}
	}
	print_proc_list();
	time_now++;
	//time step;
	for(int i = 0;i < max_core;i++){
		if(run_list[i].proc != nullptr){
			run_list[i].cpu_time--;
			run_list[i].proc->exec_time++;

			if(run_list[i].proc->exec_time == run_list[i].proc->need_time){
				run_list[i].proc->end_time = time_now;
				run_list[i].proc->status = finish;
				proc_num -= 1;
				show_dispatch(run_list[i].proc,4);
				run_list[i].proc = nullptr;
			}
			else if(run_list[i].cpu_time == 0){
				run_list[i].proc->status = wait;
				show_dispatch(run_list[i].proc,2);
				if(type == 1)
					run_list[i].proc->priority++;

				if(type == 3)
					wait_list.push_back(run_list[i].proc);
				else
					wait_list.push(run_list[i].proc);
				run_list[i].proc = nullptr;
			}
		}
	}
	//check plan_list
	Proc_ptr *tmp = plan_list.head;
	while(tmp != nullptr){
		if(tmp->p->start_time == time_now){
			tmp->p->status = wait;
			show_dispatch(tmp->p,3);
			if(type == 3)
				wait_list.push_back(tmp->p);
			else
				wait_list.push(tmp->p);
			plan_list.pop();
			tmp = plan_list.head;
		}
		else
			break;
	}
	print_proc_list();
	if(proc_num == 0)
		return 0;
	return 1;
}

/////////////////////////////////////////////////////

bool cmp_priority(Proc_ptr *a,Proc_ptr *b){
	return a->p->priority < b->p->priority;
}

bool cmp_time(Proc_ptr *a,Proc_ptr *b){
	return a->p->start_time < b->p->start_time;
}

bool menu(int i){
	int flag;
	system("cls");
	show_all_proc();
	printf("\n1.step_time\n0.exit\n");
	scanf("%d",&flag);
	if(flag == 1){
		if(proc_num == 0){
			printf("all process finish\n");
			system("pause");
		}
		else{
			system("cls");
			step_time(i);
		}

	}
	else
		return 0;
	return 1;
}

int main(){
	int num = 0,type = 0;
	printf("num for init test: ");
	scanf("%d",&num);
	printf("type for alo\n1.priority\n2.start_time\n3.round\n:");
	scanf("%d",&type);
	wait_list.cmp = cmp_time;
	plan_list.cmp = cmp_time;
	switch(type){
		case 1:{
			wait_list.cmp = cmp_priority;
			init_test(num);
			while(menu(1));
			break;
		}
		case 2:{
			init_test(num);
			while(menu(2));
			break;
		}
		case 3:{
			init_test(num);
			while(menu(3));
			break;
		}
		default:
			printf("type error\n");
			break;
	}
    return 0;
}
