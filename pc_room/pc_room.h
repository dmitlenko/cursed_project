#pragma once
#include <string>
#include <queue>
#include <functional>

#include "computer/computer.h"
#include "../tools/tools.h"
using namespace std;


class pc_room {

	
	priority_queue<computer> pc_pq;
	computer edit_helper(computer);
	priority_queue<computer> find_helper(string values, int field);
public:
	void newlist();
	void print();
	void print(string title, priority_queue<computer> v);
	void add(bool);
	void load();
	void save();
	void find();
	void edit();
	void del();
};