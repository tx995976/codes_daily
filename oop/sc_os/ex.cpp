#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>

const int max_process = 100;
const int max_core = 4;

const int wait = 1;
const int run = 2;
const int finish = 3;

sturct Proc{
	int pid;
	std::string name;
	int exec_time;
	int need_time;
	int start_time = -1;
	int priority = 1;
	int status = -1;
};

sturct Core_time{
	Proc *proc;
	int last_time;
};

Proc *proc_list[max_process];
Core_time run_list[max_core];

int time_now = 0;

int main(){
		

    return 0;
}
