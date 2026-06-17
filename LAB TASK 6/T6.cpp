#include<iostream>
#include<vector>
using namespace std;

class Student{
	public:
		string name;
		string section;
		Student(string n, string s):name(n), section(s){}
};

class Marks:public Student{
	public:
		int numberOfSubjects;
		vector<string> subjects;
		vector<int> marksOfSubjects;
		Marks(string n,string s,vector<string> sub, vector<int> MOS):Student(n,s),subjects(sub),marksOfSubjects(MOS){}
			void displayMarks(){
			for(int i = 0; i < marksOfSubjects.size(); i++){
				cout << subjects[i] << " : " << marksOfSubjects[i] << endl;
			}
		}
	
};

class Result:public Marks{
	public:
		Result(string n,string s,vector<string> sub, vector<int> MOS):Marks(n,s,sub,MOS){}
		void displayCalculateTotal(){
			int t = 0;
			for(int i = 0; i < marksOfSubjects.size(); i++){
				t += marksOfSubjects[i];
			}
			cout << "Total : " << t << endl;
		}
		
		void displayAvg(){
			int t = 0;
			for(int i = 0; i < marksOfSubjects.size(); i++){
				t += marksOfSubjects[i];
			}
			float avg = static_cast<float>(t)/marksOfSubjects.size();
			cout << "Average : "<< avg << endl;
		}


};




int main(){
	vector<string> sub(3);
	sub[0] = "PF";
	sub[1] = "OOP";
	sub[2] = "DSA";
	vector<int> marks(3);
	marks[0] = 90;
	marks[1] = 94;
	marks[2] = 93;
	Result a("Ahmed", "BCS-2E",sub,marks);
	a.displayCalculateTotal();
	a.displayAvg();
	return 0;
}