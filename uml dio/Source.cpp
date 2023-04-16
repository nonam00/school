#include <iostream>
#include <string>
#include <vector>

class SubjectMark
{
	static int ids;
	int id;
	std::string date;
	int StudentID;
	int SubjectId;
public:
	SubjectMark(std::string _date, int _SubID, int _StudentID) : date{ _date }, SubjectId{ +_SubID }, StudentID{_StudentID}
	{
		ids++;
		id = ids;
	}
	int get_id() { return id; }
	void set_id(int _id) { id = _id; }

	int get_Student() { return StudentID; }
};

int SubjectMark::ids = 0;

class Subject
{
	static int ids;
	int id;
	std::string name;

public:
	Subject(std::string _name) :name{ _name }
	{
		ids++;
		id = ids;
	}

	void set_name(std::string _name) { name = _name; }
	std::string get_name() { return name; }

	void set_id(int _id) { id = _id; }
	int get_id() { return id; }

};

int Subject::ids = 0;

class Student
{
	static int count;
	int id;
	std::string name;
	int age;
	int groupID;
	std::vector<SubjectMark>marks;

public:

	Student() : Student("", 0) {}

	Student(std::string _name, int _age) : name{ _name }, age{ _age }
	{
		count++;
		id = count;
	}

	Student(const Student& temp) : name{ temp.name }, age{ temp.age }
	{
		count++;
		id = count;
	}

	void print() { std::cout << "Group ID: " << groupID << "; Student id: " << id << "; Name: " << name << "; Age: " << age << std::endl; }

	void setGroupID(int _ID) { groupID = _ID; }

	int getID() { return id; }

	std::string getName() { return name; }

	void Mark(SubjectMark temp) { marks.push_back(temp); }
};

int Student::count = 0;

class Group
{
	static int ids;
	int ID;
	std::vector<Student>group;
	std::string name;

public:

	Group(std::string _name) : name{_name}
	{
		ids++;
		ID = ids;
	}

	void addStudent(std::string _name, int _age)
	{
		Student temp(_name, _age);
		temp.setGroupID(ID);
		group.push_back(temp);
	}

	void deleteStudent(int id)
	{
		for (int i = 0; i < group.size(); i++)
			if (group[i].getID() == id)
			{
				group.erase(group.begin() + i);
				break;
			}
	}

	void deleteStudent(std::string name)
	{
		int count = 0;
		int index = -1;
		for (int i = 0; i < group.size(); i++)
		{
			if (group[i].getName() == name)
			{
				count++;
				if (count >= 2)
				{
					std::cout << "There are more than 1 student with this name" << std::endl;
					break;
				}
				index = i;
			}
			if (i == group.size() - 1 && index != -1)
				group.erase(group.begin() + index);
		}
	}

	void set_mark(SubjectMark mark)
	{
		for (auto item : group)
		{
			if (mark.get_Student() == item.getID())
				item.Mark(mark);
		}
	}

	int get_id() { return ID; }
};

int Group::ids = 0;