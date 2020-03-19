// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade() const;

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);
	friend istream & operator>>(istream &, Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade() const
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

istream& operator>>(istream& in, Student& s)
{
	cout << "Initializing student" << endl;
	cout << "Enter name: ";
	cin >> s.name;
	cout << "Enter grade: ";
	cin >> s.grade;
}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

void insertIntoListAscending(list<Student>& students, const Student& s)
{
	list<Student>::iterator i;
	for (i = students.begin(); i != students.end(); i++)
	{
		if (s.getgrade() < i->getgrade())
		{
			students.insert(i, s);
			return;
		}
	}
	// Add to the end
	students.insert(i, s);
}

int main()
{
	// Write your code for Task 1
	list<Student> students;

	int num;
	cout << "How many students to insert? ";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		Student s;
		cin >> s;
		insertIntoListAscending(students, s);
	}

	cout << endl << "Grades (ascending):" << endl;
	list<Student>::iterator i;
	for (i = students.begin(); i != students.end(); i++)
	{
		cout << *i << endl;
	}

	cout << endl << "Grades (descending):" << endl;
	list<Student>::reverse_iterator j;
	for (j = students.rbegin(); j != students.rend(); j++)
	{
		cout << *j << endl;
	}

	return 0;
}



