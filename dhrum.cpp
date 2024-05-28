#include <iostream>
#include <iomanip>
using namespace std;

struct Process {
	char name;
	int arrival_time, burst_time, completion_time, waiting_time, turnaround_time;
	int completed;
	float normalized_turnaround_time;
} processes[10];

int num_processes;

void sortByArrival() {
	struct Process temp;
	int i, j;

	for (i = 0; i < num_processes - 1; i++) {
		for (j = i + 1; j < num_processes; j++) {
			if (processes[i].arrival_time > processes[j].arrival_time) {
				temp = processes[i];
				processes[i] = processes[j];
				processes[j] = temp;
			}
		}
	}
}

int main() {
	int i, j, total_burst_time = 0;
	char name;
	float current_time, average_waiting_time = 0, average_turnaround_time = 0;
	num_processes = 5;

	int arrival_times[] = { 0, 2, 4, 5, 7 };
	int burst_times[] = { 2, 6, 7, 3, 5 };

	for (i = 0, name = 'A'; i < num_processes; i++, name++) {
		processes[i].name = name;
		processes[i].arrival_time = arrival_times[i];
		processes[i].burst_time = burst_times[i];
		processes[i].completed = 0;
		total_burst_time += processes[i].burst_time;
	}

	sortByArrival();
	cout << "P_No.\tAT\tBT\tWT\tTAT\tNTT";

	for (current_time = processes[0].arrival_time; current_time < total_burst_time;) {
		float highest_response_ratio = -9999;
		float temp;
		int loc;
		for (i = 0; i < num_processes; i++) {
			if (processes[i].arrival_time <= current_time && processes[i].completed != 1) {
				temp = (processes[i].burst_time + (current_time - processes[i].arrival_time)) / processes[i].burst_time;
				if (highest_response_ratio < temp) {
					highest_response_ratio = temp;
					loc = i;
				}
			}
		}
		current_time += processes[loc].burst_time;
		processes[loc].waiting_time = current_time - processes[loc].arrival_time - processes[loc].burst_time;
		processes[loc].turnaround_time = current_time - processes[loc].arrival_time;
		average_turnaround_time += processes[loc].turnaround_time;
		processes[loc].normalized_turnaround_time = ((float)processes[loc].turnaround_time / processes[loc].burst_time);
		processes[loc].completed = 1;
		average_waiting_time += processes[loc].waiting_time;
		cout << "\n" << processes[loc].name << "\t" << processes[loc].arrival_time;
		cout << "\t" << processes[loc].burst_time << "\t" << processes[loc].waiting_time;
		cout << "\t" << processes[loc].turnaround_time << "\t" << processes[loc].normalized_turnaround_time;
	}
	cout << "\n\nAverage waiting time: " << average_waiting_time << endl;
	cout << "Average Turn Around time: " << average_turnaround_time << endl;
}
