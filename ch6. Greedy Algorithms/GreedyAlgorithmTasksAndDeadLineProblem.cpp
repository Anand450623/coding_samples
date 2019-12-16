/*
 * Problem: Given n events with their durations and deadlines. The goal is to choose an order to perform the task such that (d-x) is maximum
 * 			where d = task's deadline
 * 			and x = moment when the task finished
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct task
{
	string task_label;
	int duration;
	int deadline;

	task()
	{
		this->task_label="";
		this->duration=0;
		this->deadline=0;
	}

	task(string task_label,int duration, int deadline)
	{
		this->task_label="";
		this->duration=duration;
		this->deadline=deadline;
	}

	bool operator<(const task t)
	{
		return this->duration<t.duration;
	}

}task;

int main()
{

	int no_of_events = 4;
	string tasks[] = {"A","B","C","D"};
	int duration[] = {4,3,2,4};
	int deadline[] = {2,5,7,5};

	vector<task> task_list;

	for(int i=0;i<no_of_events;i++)
	{
		task t1(tasks[i],duration[i],deadline[i]);
		task_list.push_back(t1);
	}

	sort(task_list.begin(),task_list.end());
	int score = 0;
	int time_elapsed = 0;

	for(auto i:task_list)
	{
		time_elapsed += i.duration;
		score += i.deadline - time_elapsed;
	}

	cout<<"The maximum possible score is = "<<score<<endl;
	return 0;

}
