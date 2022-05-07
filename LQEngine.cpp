//
// Created by Cold on 03/05/2022.
//

#include "LQEngine.h"
#include <cstdlib>

LQEngine::LQEngine(std::string& database_buffer) {
    m_database = new LQDatabase(database_buffer);
}

void LQEngine::reset_correct_answers() {
    m_correct_answers = 0;
    m_database->reset_database();
}

std::vector<LQQuestion *> LQEngine::get_questions() {
    std::vector<LQQuestion *> out = m_database->get_questions(m_active_part);
    while (true) {
        m_correct_index = rand() % 3;
        if (out[m_correct_index]->is_used()){
            out = m_database->get_questions(m_active_part);
            continue;
        }
        break;
    }
    out[m_correct_index]->set_used(true);
    return out;
}

bool LQEngine::answer(int index) {
    if (index == m_correct_index){
        m_correct_answers++;
        if (m_correct_answers == 20){
            m_correct_answers = 0;
            m_active_part++;
        }
        return true;
    }

    reset_correct_answers();
    return false;
}