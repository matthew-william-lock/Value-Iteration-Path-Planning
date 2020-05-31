#ifndef VALUEITERATIONMODEL_H
#define VALUEITERATIONMODEL_H

#include <vector>

namespace LCKMAT002{

    class ValueIterationModel
    {
    private:
        std::vector<int> states;
        std::vector<double> values;
    public:
        ValueIterationModel(int states);
        ~ValueIterationModel();
    };    

}

#endif VALUEITERATIONMODEL_H