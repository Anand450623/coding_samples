/*
 * Problem: Given n events with their starting and ending times, find a schedule that includes as many events as possible.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct task
{
	string task_label;
	int start_time;
	int finish_time;

	task()
	{
		this->start_time=0;
		this->finish_time=0;
		this->task_label="";
	}

	task(string task_label,int start_time, int finish_time)
	{
		this->task_label=task_label;
		this->start_time=start_time;
		this->finish_time=finish_time;
	}

	bool operator<(const task t)
	{
		return this->finish_time<t.finish_time;
	}

}task;

int main()
{

	int no_of_events = 4;
	string tasks[] = {"A","B","C","D"};
	int start_time[] = {1,2,3,6};
	int final_time[] = {3,5,9,8};

	vector<task> task_list;
	vector<task> possible_tasks;

	for(int i=0;i<no_of_events;i++)
	{
		task t1(tasks[i],start_time[i],final_time[i]);
		task_list.push_back(t1);
	}

	sort(task_list.begin(),task_list.end());
	possible_tasks.push_back(task_list[0]);

	int index = 0;
	for(long long unsigned i=1;i<task_list.size();i++)
	{
		if(task_list[i].start_time >= possible_tasks[index].finish_time)
		{
			possible_tasks.push_back(task_list[i]);
			index++;
		}
	}

	for(long long unsigned i=0;i<possible_tasks.size();i++)
		cout<<possible_tasks[i].task_label<<" "<<possible_tasks[i].start_time<<" "<<possible_tasks[i].finish_time<<endl;

	return 0;

}
