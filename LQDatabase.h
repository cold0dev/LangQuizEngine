//
// Created by Cold on 03/05/2022.
//

#ifndef LQENGINE_LQDATABASE_H
#define LQENGINE_LQDATABASE_H
#include <vector>
#include "LQQuestion.h"
#include <string>

class LQDatabase {
private:
    std::vector<LQQuestion*> m_questions;
    unsigned long m_parts { 0 };
    void parse(std::string& database_buffer);
    LQQuestion* get_random_question(int part, std::vector<long>& used_ids);
public:
    LQDatabase(std::string& database_buffer);
    std::vector<LQQuestion*> get_questions(int part);
    unsigned long get_part_count() { return m_parts; }
    void reset_database();
};


#endif //LQENGINE_LQDATABASE_H
