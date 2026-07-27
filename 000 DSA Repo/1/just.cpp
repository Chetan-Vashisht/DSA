#include <iostream>
using namespace std;
class student{
    private:
        int studentId;
        string studentName;
        int age;
        int arr[5];
        int avgMarks=0;
        
    public:
        void intputData(){
            cout<<"Enter studentId";
            cin>>studentId;
            cout<<"enter studentName";
            cin>>studentName;
            cout<<"enter age";
            cin>>age;
            cout<<"enter marks ";
            for (int i = 0; i < 5; i++)
            {
                cin>>arr[i];
                cout<<"Array of size 5 is "
            }
        }
        void calcAvg(){
            int sum=0;
            for (int i = 0; i < sizeof(arr); i++)
            {
                sum+=i;
            }
            avgMarks=sum/sizeof(arr);
            cout<<"Average marks "<<avgMarks;
        }
        void displayGrade(){
            if(avgMarks>90) cout<<"grade A+";
            else if (avgMarks>80 && avgMarks<90) cout<<"grade A";
            else if (avgMarks>70 && avgMarks<80) cout<<"grade B";
                else if (avgMarks>70 && avgMarks<60) cout<<"grade C";
                else if (avgMarks<60) cout<<"Grade D";
        }   ;
       
int main() {
    student obj;
    obj.intputData();
    obj.displayData();
    obj.calcAvg();
    obj.displayGrade();
    obj.diplay.data.revmoe.make


  return 0;
}


#include <iostream>
using namespace std;
int main() {

    cout<<""


  return 0;
}