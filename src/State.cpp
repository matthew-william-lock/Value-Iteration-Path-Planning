#include "State.h"

namespace  LCKMAT002 {
    State::State(const std::string & name) : name(name), previousValue(0),currentValue(0) {
        // states.reserve(1);
        // states.push_back(nullptr);
    }   
    
    State::~State(){
        // Although we use pointer, we do not point to dynamic memory.
        // Thus no deallocation is required
        // std::cout<<"End of "<<this->getName()<< " size "<<this->states.size()<<std::endl;
    }

    const std::string State::getName(){
        return this->name;
    }

    const double State::getReward(int index){
        return actionReward.at(index);
    }

    void State::addStateActionProb(State * s, const double & actionR, const double & actionProb){
        this->states.push_back(s);
        this->actionReward.push_back(actionR);
        this->actionProbability.push_back(actionProb);
    }

    std::string State::getStatesOfStates(){
        std::string outputString("");
        outputString.append( this->getName() );
        outputString.append(" Size ");
        outputString.append( std::to_string(this->states.size()) );
        outputString+="\n";
        for (size_t i = 0; i < states.size(); i++){
            outputString.append(states.at(i)->getName());
            outputString+=" : ";
            outputString+=states.at(i)->getStates();
            outputString+="\n";
        }
        return outputString;        
    }

    std::string State::getStates(){
        std::string outputString("");
        for (size_t i = 0; i < states.size(); i++){
            outputString+=states.at(i)->getName();
            outputString+=" ";
        }
        return outputString;
    }

    double State::returnValue(const double & gamma){
        int index=0;
        double max=-1;
        for (size_t i = 0; i < states.size(); i++){
            // double value = actionReward.at(i);

            double value = actionReward.at(i) + gamma *actionProbability.at(i) * states.at(i)->previousValue;

            // for (size_t j = 0; j < states.size(); j++){
            //     value+=gamma*actionProbability.at(j)*states.at(j)->previousValue;
            // }

            if (value>max){
                max=value;
                index=i;
            }            
        }
        return max;
    }

    void State::updateCurrentValue(const double & value){
        this->currentValue=value;
    }
    void State::updatePreviousValue(const double & value){
        this->previousValue=value;
    }

    const double State::returnPreviousValue(){
        return previousValue;
    }
    const double State::returnCurrentValue(){
        return currentValue;
    }

    State * State::pi(){
        double max;
        int index=0;
        if (states.size()>1){
            max=states.at(0)->returnCurrentValue()+actionReward.at(0);
        }
        
        for (size_t i = 0; i < states.size(); i++){
            if (states.at(i)->returnCurrentValue()+actionReward.at(i)>max){
                max = states.at(i)->returnCurrentValue()+actionReward.at(i);
                index=i;
            }
            
        }
        return states.at(index);
    }


}