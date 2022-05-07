//
// Created by Cold on 03/05/2022.
//

#ifndef LQENGINE_LQQUESTION_H
#define LQENGINE_LQQUESTION_H
#include <string>

class LQQuestion {
private:
    long m_id;
    std::string m_question;
    std::string m_answer;
    bool m_used;
public:
    LQQuestion(long id, std::string& question, std::string& answer);
    std::string& get_question() { return m_question; }
    std::string& get_answer() { return m_answer; }
    bool is_used() { return m_used; }
    long get_id() { return m_id; }
    void set_used(bool status) { m_used = status; }
};


#endif //LQENGINE_LQQUESTION_H
