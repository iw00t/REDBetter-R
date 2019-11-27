#include "BaseView.h"

#include <iostream>

namespace REDBetterR {
    void BaseView::displaySpacer() const {
        std::cout << std::string(80, '-') << std::endl;
    }
}
