#include "top.hpp"

Top::Top(sc_core::sc_module_name nm) 
    : sc_module(nm)
{
    initiator = new Initiator("initiator"); 
    target = new Target("target"); 
    initiator->initiator_sk.bind(target->target_sk); 
}

Top::~Top() { 
    delete initiator; 
    delete target; 
}
