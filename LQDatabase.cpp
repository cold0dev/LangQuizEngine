//
// Created by Cold on 03/05/2022.
//

#include "LQDatabase.h"
#include <cstdlib>

LQDatabase::LQDatabase(std::string &database_buffer) {
    parse(database_buffer);
}

std::vector<std::string> split(std::string& text,char delim){
    std::vector<std::string> out;
    std::string buf = "";
    for (char c : text){
        if (c == delim){
            out.push_back(buf);
            buf = "";
            continue;
        }
        buf += c;
    }
    if (!buf.empty()){
        out.push_back(buf);
    }

    return out;
}

void LQDatabase::parse(std::string &database_buffer) {
    std::vector<std::string> lines = split(database_buffer,'\n');
    long id = 0;

    for (std::string line : lines){
        std::vector<std::string> args = split(line,';');
        if (args.size() < 2)continue;
        LQQuestion* question = new LQQuestion(id,args[0],args[1]);
        id++;
        m_questions.push_back(question);
    }

    m_parts = m_questions.size() / 20;
    if (m_questions.size() % 20 != 0)m_parts++;
}

std::vector<LQQuestion*> LQDatabase::get_questions(int part) {
    std::vector<LQQuestion*> out;
    std::vector<long> used_ids;

    LQQuestion* question1 = get_random_question(part,used_ids);
    used_ids.push_back(question1->get_id());
    LQQuestion* question2 = get_random_question(part,used_ids);
    used_ids.push_back(question2->get_id());
    LQQuestion* question3 = get_random_question(part,used_ids);
    used_ids.push_back(question3->get_id());
    LQQuestion* question4 = get_random_question(part,used_ids);

    out.push_back(question1);
    out.push_back(question2);
    out.push_back(question3);
    out.push_back(question4);

    return out;
}

LQQuestion* LQDatabase::get_random_question(int part, std::vector<long>& used_ids) {
    LQQuestion* question;
    while (true){
        int index = rand() % 20 + (part * 20);
        question = m_questions[index];

        bool contain = false;
        for (long id : used_ids){
            if (id == question->get_id()){
                contain = true;
            }
            else if (question->get_question() == m_questions[id]->get_question()){
                contain = true;
            }
            else if (question->get_answer() == m_questions[id]->get_answer()){
                contain = true;
            }
        }

        if(!contain)break;
    }

    return question;
}

void LQDatabase::reset_database() {
    for (LQQuestion* q : m_questions){
        q->set_used(false);
    }
}
