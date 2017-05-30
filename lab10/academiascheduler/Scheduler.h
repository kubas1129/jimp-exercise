//
// Created by kubas1129 on 16.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <string>
#include <vector>
#include <stdexcept>

namespace academia {

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound() : std::runtime_error("NoViableSolutionFound") {}
    };


    class SchedulingItem{
    public:

        SchedulingItem(int courseID, int teacherID,int roomID,int timeSlot, int YEAR) : course_id(courseID), teacher_id(teacherID), room_id(roomID), time_slot(timeSlot), year(YEAR) {}

        int CourseId() const { return course_id; }
        int TeacherId() const { return teacher_id; }
        int RoomId() const { return room_id; }
        int TimeSlot() const { return time_slot; }
        int Year() const { return year; }

    private:
        int course_id,teacher_id,room_id,time_slot, year;
    };

    class Schedule{
    public:

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[](int index) const;

    private:
        std::vector<SchedulingItem> schedules_;
    };


    class Scheduler {
    public:


        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) =0;


    };

    class GreedyScheduler: public Scheduler{
    public:

        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;

    };



}

#endif //JIMP_EXERCISES_SCHEDULER_H
