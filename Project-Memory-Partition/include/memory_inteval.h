#ifndef __MEMORY_INTERVAL_H__
#define __MEMORY_INTERVAL_H__

#include <string>
#include <iostream>

class Memory_Interval{
    private:
        std::string pid_name;
        int start;
        int end;

    public:
        Memory_Interval(std::string name, int start, int size){
            this->pid_name = name;
            this->start = start;
            this->end = start + size -1;
        }

        Memory_Interval(std::string name){
            this->pid_name = name;
            this->start = 0;
            this->end = 0;
        }

        ~Memory_Interval(){ }

        void set_pid(std::string pid_name_value){
            this->pid_name = pid_name_value;
        }
        void set_start(int start_value){
            this->start = start_value;
        }

        void set_end(int end_value){
            this->end = this->start + end_value -1;
        }
        void update_end(int end_value){
            this->end = end_value;
        }
        std::string get_pid() const {
            return this->pid_name;
        }
        int get_start() const {
            return this->start;
        }
        int get_end() const {
            return this->end;
        }


        bool compare_intervals_pid(const Memory_Interval& obj) const {
            if(this->pid_name.compare(obj.pid_name) == 0)
            return true;
            else return false;
        }

        friend std::ostream& operator <<(std::ostream &oss, const Memory_Interval& obj){
            oss<<"(["<<obj.pid_name<<"] ";
            oss<<obj.start<<"~~>"<<obj.end;
            oss<<") ";
            return oss;
        }

};

#endif // __MEMORY_INTERVAL_H__
