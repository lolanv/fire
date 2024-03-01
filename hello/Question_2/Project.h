// Project.h
#ifndef PROJECT_H
#define PROJECT_H

#include <string>



class Project {
private:
    /* data */
    std::string _project_name;
    float _project_budget;

public:
   Project(/* args */)=default;
    //copy constructor 
    Project(const Project&) = delete;
    //copy operator
    Project& operator=(const Project&) = delete;
    //move constructor
    Project(Project&&) = delete;
    //move operator
    Project& operator=(Project&&) = delete;
    ~Project()=default;


    Project(std::string name, float budget);
    std::string getName() const { return _project_name; }
    float getBudget() const { return _project_budget; }
};

#endif // PROJECT_H