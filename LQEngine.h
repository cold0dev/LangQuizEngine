//
// Created by Cold on 03/05/2022.
//

#ifndef LQENGINE_LQENGINE_H
#define LQENGINE_LQENGINE_H
#include <string>
#include "LQDatabase.h"
#include "LQQuestion.h"

class LQEngine {
private:
    LQDatabase* m_database;
    int m_active_part = 0;
    int m_correct_answers = 0;

    int m_correct_index = 0;
    void reset_correct_answers();
public:
    LQEngine(std::string& database_buffer);
    void set_active_part(int part) { m_active_part = part; }
    int get_active_part() { return m_active_part; }
    int get_part_count() { return m_database->get_part_count(); }
    std::vector<LQQuestion*> get_questions();
    bool answer(int index);
    int get_correct_index() { return m_correct_index; }
    int get_correct_answers() { return  m_correct_answers; }
};


#endif //LQENGINE_LQENGINE_H
