#include "ValueIterationModel.h"

namespace LCKMAT002 {

    ValueIterationModel::ValueIterationModel(int states) {
        this->states = std::vector<int>(states);
        this->values = std::vector<double>(states);
    }

}
