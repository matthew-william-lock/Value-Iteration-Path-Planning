#include <iostream>
#include <fstream>

#include "State.h"

int main (){

    using namespace LCKMAT002;
    using namespace std;

    ofstream results;
    results.open ("../results.txt");

    {

        // Create the states
        State S1 = State("S1");
        State S2 = State("S2");
        State S3 = State("S3");
        State S4 = State("S4");
        State S5 = State("S5");
        State S6 = State("S6");

        // Add state dependencies
        S1.addStateActionProb(&S4,0,1);
        S1.addStateActionProb(&S2,0,1);

        S2.addStateActionProb(&S1,0,1);
        S2.addStateActionProb(&S5,0,1);
        S2.addStateActionProb(&S3,50,1);

        S3.addStateActionProb(&S3,0,1);

        S4.addStateActionProb(&S1,0,1);
        S4.addStateActionProb(&S5,0,1);

        S5.addStateActionProb(&S4,0,1);
        S5.addStateActionProb(&S2,0,1);
        S5.addStateActionProb(&S6,0,1);
        

        S6.addStateActionProb(&S5,0,1);
        S6.addStateActionProb(&S3,100,1);

        // Iterate
        bool changed = true;
        int iterations = 1;

        while (changed){
            
            // Update current value
            S1.updateCurrentValue(S1.returnValue(0.8));
            S2.updateCurrentValue(S2.returnValue(0.8));
            S3.updateCurrentValue(S3.returnValue(0.8));
            S4.updateCurrentValue(S4.returnValue(0.8));
            S5.updateCurrentValue(S5.returnValue(0.8));
            S6.updateCurrentValue(S6.returnValue(0.8));

            cout<<"Iteration "<<iterations<<endl;
            cout<<"S1 "<<S1.returnCurrentValue()<<endl;
            cout<<"S2 "<<S2.returnCurrentValue()<<endl;
            cout<<"S3 "<<S3.returnCurrentValue()<<endl;
            cout<<"S4 "<<S4.returnCurrentValue()<<endl;
            cout<<"S5 "<<S5.returnCurrentValue()<<endl;
            cout<<"S6 "<<S6.returnCurrentValue()<<endl<<endl;

            if (S1.returnPreviousValue()!= S1.returnCurrentValue() || S2.returnPreviousValue()!= S2.returnCurrentValue() || S3.returnPreviousValue()!= S3.returnCurrentValue() ||
                S4.returnPreviousValue()!= S4.returnCurrentValue() || S5.returnPreviousValue()!= S5.returnCurrentValue() || S6.returnPreviousValue()!= S6.returnCurrentValue() ){
                changed=true;
            } else{
                changed =false;
            }

            // Update Previous value
            S1.updatePreviousValue(S1.returnCurrentValue());
            S2.updatePreviousValue(S2.returnCurrentValue());
            S3.updatePreviousValue(S3.returnCurrentValue());
            S4.updatePreviousValue(S4.returnCurrentValue());
            S5.updatePreviousValue(S5.returnCurrentValue());
            S6.updatePreviousValue(S6.returnCurrentValue());
            iterations++;
        }
        iterations--;
        
        cout<<"Iterations "<<iterations<<endl<<endl;

        // Question 1        
        results << "Question 1 "<<endl;
        results << "Optimal Values :"<<endl;
        results <<"S1 "<< S1.returnCurrentValue()<<endl;
        results <<"S2 "<< S2.returnCurrentValue()<<endl;
        results <<"S3 "<< S3.returnCurrentValue()<<endl;
        results <<"S4 "<< S4.returnCurrentValue()<<endl;
        results <<"S5 "<< S5.returnCurrentValue()<<endl;
        results <<"S6 "<< S6.returnCurrentValue()<<endl;
        results<<"Iterations : "<<iterations<<endl<<endl;

        // Question 2
        // Find Optimal Policy
        vector<string> transitions = vector<string>();
        State * currentState = &S1;
        transitions.push_back(currentState->getName());
        while (currentState!=&S3){
            currentState=currentState->pi();
            transitions.push_back(currentState->getName());
        }

        cout<<"Question 2"<<endl;
        results << "Question 2"<<endl;
        cout<<transitions.at(0);
        results<<transitions.at(0);
        for (size_t i = 1; i < transitions.size(); i++){
            results<<"->"<<transitions.at(i);
            cout<<"->"<<transitions.at(i);
        }
        cout<<endl<<endl;
        results<<endl<<endl;

    }

    //Question 3
    {
        results << "Question 3"<<endl;
        cout<<"Question 3"<<endl;

        results<<"Yes it is possible to change the reward function such that v* changes but the policy remains unchanged."<<endl;
        results<< "One way to do this is to change the reward functions. While there are many ways to change the reward function,";
        results<<"for the purposes of this demonstration the existing reward functions were simply doubled"<<endl;

        State S1 = State("S1");
        State S2 = State("S2");
        State S3 = State("S3");
        State S4 = State("S4");
        State S5 = State("S5");
        State S6 = State("S6");

        S1.addStateActionProb(&S4,0,1);
        S1.addStateActionProb(&S2,0,1);
        S2.addStateActionProb(&S1,0,1);
        S2.addStateActionProb(&S5,0,1);
        S2.addStateActionProb(&S3,100,1);
        S3.addStateActionProb(&S3,0,1);
        S4.addStateActionProb(&S1,0,1);
        S4.addStateActionProb(&S5,0,1);
        S5.addStateActionProb(&S4,0,1);
        S5.addStateActionProb(&S2,0,1);
        S5.addStateActionProb(&S6,0,1);       
        S6.addStateActionProb(&S5,0,1);
        S6.addStateActionProb(&S3,200,1);

        // Iterate
        bool changed = true;
        int iterations = 1;

        while (changed){
            
            // Update current value
            S1.updateCurrentValue(S1.returnValue(0.8));
            S2.updateCurrentValue(S2.returnValue(0.8));
            S3.updateCurrentValue(S3.returnValue(0.8));
            S4.updateCurrentValue(S4.returnValue(0.8));
            S5.updateCurrentValue(S5.returnValue(0.8));
            S6.updateCurrentValue(S6.returnValue(0.8));

            cout<<"Iteration "<<iterations<<endl;
            cout<<"S1 "<<S1.returnCurrentValue()<<endl;
            cout<<"S2 "<<S2.returnCurrentValue()<<endl;
            cout<<"S3 "<<S3.returnCurrentValue()<<endl;
            cout<<"S4 "<<S4.returnCurrentValue()<<endl;
            cout<<"S5 "<<S5.returnCurrentValue()<<endl;
            cout<<"S6 "<<S6.returnCurrentValue()<<endl<<endl;

            if (S1.returnPreviousValue()!= S1.returnCurrentValue() || S2.returnPreviousValue()!= S2.returnCurrentValue() || S3.returnPreviousValue()!= S3.returnCurrentValue() ||
                S4.returnPreviousValue()!= S4.returnCurrentValue() || S5.returnPreviousValue()!= S5.returnCurrentValue() || S6.returnPreviousValue()!= S6.returnCurrentValue() ){
                changed=true;
            } else{
                changed =false;
            }

            // Update Previous value
            S1.updatePreviousValue(S1.returnCurrentValue());
            S2.updatePreviousValue(S2.returnCurrentValue());
            S3.updatePreviousValue(S3.returnCurrentValue());
            S4.updatePreviousValue(S4.returnCurrentValue());
            S5.updatePreviousValue(S5.returnCurrentValue());
            S6.updatePreviousValue(S6.returnCurrentValue());
            iterations++;
        }
        iterations--;
        results << "Optimal Values :"<<endl;
        results <<"S1 "<< S1.returnCurrentValue()<<endl;
        results <<"S2 "<< S2.returnCurrentValue()<<endl;
        results <<"S3 "<< S3.returnCurrentValue()<<endl;
        results <<"S4 "<< S4.returnCurrentValue()<<endl;
        results <<"S5 "<< S5.returnCurrentValue()<<endl;
        results <<"S6 "<< S6.returnCurrentValue()<<endl;
        results<<"Iterations : "<<iterations<<endl;
        cout<<"Iterations "<<iterations<<endl<<endl;
        vector<string> transitions = vector<string>();
        State * currentState = &S1;
        transitions.push_back(currentState->getName());
        while (currentState!=&S3){
            currentState=currentState->pi();
            transitions.push_back(currentState->getName());
        }
        results<<"Optimal Policy:"<<endl;
        cout<<transitions.at(0);
        results<<transitions.at(0);
        for (size_t i = 1; i < transitions.size(); i++){
            results<<"->"<<transitions.at(i);
            cout<<"->"<<transitions.at(i);
        }
        cout<<endl;
        results<<endl;

    }
    

    results.close();
    
    
    return 0;
}