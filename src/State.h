#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <iostream> // removed before hand in

namespace LCKMAT002 {
    class State
    {
    private:
        std::string name;
        double currentValue;
        double previousValue;
        std::vector<State*> states;
        std::vector<double> actionReward;
        std::vector<double> actionProbability;
    public:
        State(const std::string & name);
        ~State();

        // Return the name of the state
        const std::string getName();

        // Return the value of reward moving to partocular state
        const double getReward(int index);

        // Connect state to another existing state and provide transition reward and probability
        void addStateActionProb(State * s, const double & actionR, const double & actionProb);

        // return list of states and their states
        std::string getStatesOfStates();

        // Return list of all states associated 
        std::string getStates();

        // Return value of state according to V^{\pi^*}=max_a \{R(i,a)+ \gamma\sum_j T_{ij}^a V^{\pi^*}(j)\}
        double returnValue(const double & gamma);

        // Update current and previous values of states
        void updateCurrentValue(const double & value);
        void updatePreviousValue(const double & value);

        // Return current and previous values
        const double returnPreviousValue();
        const double returnCurrentValue();

        // Return next node according to optimal policy
        State * pi();

        // Change act
    };
    
    
}

#endif