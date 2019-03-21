#include <iostream>
#include <vector>

/*
submitted


*/
using namespace std;

class RmAppAttempt
{
	public:
		string name;
		string status;
		RmAppAttempt(string name)
		{
			this->name = name;
			status = "submitted";
			cout << name << "|" << status << ";";
		}
		
		void Recv(string src, string event)
		{
			if(src == "ResouceScheduler" && status == "submitted" && event == "app_accepted")
			{
				status = "scheduled";
				cout << name << "|" << status << ";";
			}
			else if(src == "RmContainer" && status == "scheduled" && event == "container_allocated")
			{
				status = "allocated";
				cout << name << "|" << status << ";";
			}
			else if(src == "ApplicationMasterLauncher" && status == "scheduled" && event == "launched")
			{
				status = "running";
				cout << name << "|" << status << ";";
			}
			else if(src == "ResouceScheduler" && status == "running" && event == "finished")
			{
				status = "finished";
				cout << name << "|" << status << ";";
			}
			else if(src == "RmApp" && status != "finished" && event == "kill")
			{
				status = "killed";
				cout << name << "|" << status << ";";
			}
		}
};

int main()
{
	string str = "";
	getline(cin, str);
	vector<RmAppAttempt> apps;
	size_t pos;
	while((pos = str.find(" ") ) != str.npos)
	{
		string temp = str.substr(0, pos);
		size_t fir = temp.find("|");
		string src = temp.substr(0, fir);
		temp = temp.substr(fir + 1);
		fir = temp.find("|");
		string tar = temp.substr(0, fir);
		string op = temp.substr(fir + 1);
		str = str.substr(pos + 1);
		
		int index = -1;
		for(int i = 0; i < apps.size(); i++)
		{
			if(apps[i].name == tar)
			{
				index = i;
				break;
			}
		}
		
		if(index != -1)
		{
			apps[index].Recv(src, op);
		}
		else if(op == "start" && src == "RmApp")
		{
			RmAppAttempt ra(tar);
			apps.push_back(ra);
		}
	}
	if(str == "")
		return 0 ;
	
	string temp = str;
	size_t fir = temp.find("|");
	string src = temp.substr(0, fir);
	temp = temp.substr(fir + 1);
	fir = temp.find("|");
	string tar = temp.substr(0, fir);
	string op = temp.substr(fir + 1);
	
	int index = -1;
	for(int i = 0; i < apps.size(); i++)
	{
		if(apps[i].name == tar)
		{
			index = i;
			break;
		}
	}
	
	if(index != -1)
	{
		apps[index].Recv(src, op);
	}
	else if(op == "start" && src == "RmApp")
	{
		RmAppAttempt ra(tar);
		apps.push_back(ra);
	}
}
