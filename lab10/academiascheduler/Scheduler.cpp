//
// Created by kubas1129 on 16.05.17.
//

#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include "Scheduler.h"


namespace academia {


    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule sched;
        for(auto &v : schedules_)
        {
            if(v.TeacherId() == teacher_id) sched.schedules_.push_back(v);
        }
        return sched;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule sched;
        for(auto &v : schedules_)
        {
            if(v.RoomId() == room_id) sched.schedules_.push_back(v);
        }
        return sched;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule sched;
        for(auto &v : schedules_)
        {
            if(v.Year() == year) sched.schedules_.push_back(v);
        }
        return sched;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> availabletime;
        std::set<int> reservetime;
        for(auto &v : schedules_)
        {
            reservetime.emplace(v.TimeSlot());
        }

        for(int i =1;i <= n_time_slots;i++)
        {
            if(reservetime.find(i) == reservetime.end()) availabletime.push_back(i);
        }
        return availabletime;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedules_.push_back(item);
    }

    size_t Schedule::Size() const {
        return schedules_.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
        return schedules_[index];
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule sched{};

        std::vector<std::vector<int>> teacher_course; //first = teacherID, second = courseID
        std::vector<std::vector<int>> room_taken; //first = roomID, second slot_time

        for(auto &v : teacher_courses_assignment)
        {
            for(auto &d : v.second)
            {
                teacher_course.push_back({v.first, d});
            }
        }


        for(auto &courses: courses_of_year)
        {
            for(auto &coursesID : courses.second)
            {
                for(auto &teacherCourses : teacher_course)
                {
                    if(teacherCourses[1] == coursesID)
                    {
                        for(auto &Room : rooms)
                        {

                            if(room_taken.size() > 0)
                            {
                                for(auto &RoomTaken : room_taken)
                                {
                                    if(sched.AvailableTimeSlots(n_time_slots).size() == 0)
                                    {
                                        throw NoViableSolutionFound();
                                    }
                                    std::vector<int> available_timeSlot = sched.AvailableTimeSlots(n_time_slots);

                                    SchedulingItem item(coursesID, teacherCourses[0], Room,available_timeSlot[0], courses.first);
                                    sched.InsertScheduleItem(item);
                                    room_taken.push_back({Room, teacherCourses[0]});
                                    break;
                                }
                            }
                            else
                            {
                                if(sched.AvailableTimeSlots(n_time_slots).size() == 0)
                                {
                                    throw NoViableSolutionFound();
                                }
                                std::vector<int> available_timeSlot = sched.AvailableTimeSlots(n_time_slots);
                                SchedulingItem item(coursesID, teacherCourses[0], Room,available_timeSlot[0], courses.first);
                                sched.InsertScheduleItem(item);
                                room_taken.push_back({Room, teacherCourses[0]});
                            }
                        }
                    }
                }
            }
        }
        return sched;
    }


}