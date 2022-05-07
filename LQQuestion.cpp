//
// Created by Cold on 03/05/2022.
//

#include "LQQuestion.h"

#include <utility>

LQQuestion::LQQuestion(long id, std::string& question, std::string& answer) {
    m_id = id;
    m_question = std::move(question);
    m_answer = std::move(answer);
    m_used = false;
}
