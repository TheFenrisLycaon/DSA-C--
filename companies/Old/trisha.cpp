#include<iostream>
using namespace std;

class Department
{
    public:       
    Department()
    {
        int n = 100;
        // using counter to create links
        int mark[n], roll[n], link[n], counter=0;
        string courses[n];
        if(counter != 0) counter ++ ;

    }

    int find(int x)
    { 
        if(len(mark) > 0)
            for(int i=0; i<len(mark); i++)
                if(roll[i] == x)
                   return i;
                else
                    counter = i + 1;
        else
            counter = 0;

        return 0;
    }

    void setMarks(int roll_num, int marks)
    {
        id = find(roll_num);
        link[id] = id;
        roll[id] = roll_num;
        mark[id] = marks;
    } 

    void getHightest()
    {
        k = mark[0];
        for(int i=1;i<n; i++)
            if(k < mark[i])
                k = mark[i];
        for(int i=0; i<n; i++)
            if(k==mark[i])
                std :: cout << roll[i] << std :: endl;
    }

    void getAverage()
    {
        avg = 0;
        for(int i; i<n; i++)
            avg += mark[i];
        avg /= counter;
        std :: cout << avg << std :: endl ;
    }

    void fetchStudent(int roll_num)
    {
        id = find(roll_num);
        std :: cout << roll[id-1] << "\t" << mark[id-1];
    }

    void addCourse(string course_code)
    {
        int i = len(courses);
        courses[i] = course_code;
    }

    void listCourses()
    {
        for(int i=0;i<n;i++)
            std :: cout << courses[i];
    }
};

int main()
{
    Department d;
    d.setMarks(104,95);
    std ::  cout << d.getAverage() << std :: endl;
    d.setMarks(504,55);
    std ::  cout << d.getHightest() << " " << d.getAverage() << std :: endl;
    d.addCourse("HS101");
    d.addCourse("MA105");
    d.listCourses();
    d.setMarks(104,98);
    d.fetchStudent(504);
    d.fetchStudent(100);
    d.fetchStudent(150);
}
