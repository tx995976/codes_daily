#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<string>

const int max_process = 100;
const int max_core = 4;

const int wait = 1;
const int run = 2;
const int finish = 3;

int time_now = 0;

struct Proc{
	int pid;
	char name[10];
	int exec_time;
	int need_time;
	int start_time = -1;
	int end_time = -1;
	int priority = 1;
	int status = -1;
};

struct Proc_ptr{
	Proc *p = nullptr;
	Proc *next = nullptr;
	Proc *prev = nullptr;
};

struct Proc_queue{
	Proc_ptr *head = nullptr;
	Proc_ptr *tail = nullptr;
	bool (*cmp)(*Proc_ptr a,*Proc_ptr b);
	//cmp
	void push(Proc *in){
		if(head == nullptr){
			head = new Proc_ptr;
			head->p = in;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
			return;
		}
		Proc_ptr *tmp = head;
		Proc_ptr *new_node = new Proc_ptr;
		new_node->p = in;
		while(tmp->next != nullptr){
			if(cmp(tmp,new_node)){
				new_node->next = tmp;
				new_node->prev = tmp->prev;
				tmp->prev->next = new_node;
				tmp->prev = new_node;
				return;
			}
		}
	}

	*Proc top(){
		return head->p;
	}

	void pop(){
		if(head == nullptr) return;
		Proc_ptr *tmp = head;
		head = head->next;
		delete tmp;
	}
};

struct Core{
	Proc *proc;
	int last_time;
};

Proc *proc_list[max_process];
Core run_list[max_core];
Proc_queue plan_list,wait_list;

///////////////////////////////////////

void print_proc_list(){
     printf("wait_list:\n");
	 printf("pid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tstatus\n");
	 Proc_ptr *tmp = wait_list.head;
	 while(tmp != nullptr){
		 printf("%-4d %-8s %-4d %-4d %-4d %-4d %-4d %-4d\n",
				 tmp->p->pid,
				 tmp->p->name,
				 tmp->p->exec_time,
				 tmp->p->need_time,
				 tmp->p->start_time,
				 tmp->p->end_time,
				 tmp->p->priority,
				 tmp->p->status
				);
		 tmp = tmp->next;
	 }
	 printf("rb_list:\n");
	 printf("pid\tname\t\texec_time\tneed_time\tstart_time\tend_time\tpriority\tstatus\n");
	 for(int i = 0;i < max_core;i++){
		 if(run_list[i].proc != nullptr){
			 printf("%-4d %-8s %-4d %-4d %-4d %-4d %-4d %-4d\n",
					 run_list[i].proc->pid,
					 run_list[i].proc->name,
					 run_list[i].proc->exec_time,
					 run_list[i].proc->need_time,
					 run_list[i].proc->start_time,
					 run_list[i].proc->end_time,
					 run_list[i].proc->priority,
					 run_list[i].proc->status
					);
		 }
	 }
}

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
    if(new_p->start_tme <= time_now){
		new_p->status = wait;
		wait_list.push(new_p);
	}
	else{
		plan_list.push(new_p);
	}
}

void step_time(){}

bool cmp_priority(Proc_ptr *a,Proc_ptr *b){
	if(a->p->priority != b->p->priority)
		return a->p->priority < b->p->priority;
	if(a->p->need_time != b->p->need_time)
		return a->p->need_time < b->p->need_time;
	return a->p->pid < b->p->pid;
}

bool cmp_time(Proc_ptr *a,Proc_ptr *b){
	if(a->p->start_time != b->p->start_time)
		return a->p->start_time < b->p->start_time;
	return a->p->pid < b->p->pid;
}



void alo_priority(){
	wait_list.cmp = cmp_priority;

}

void alo_time(){}

void alo_round(){}

int main(){
	

    return 0;
}
