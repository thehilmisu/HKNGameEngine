#pragma once 

#include "hkn_window.h"

namespace hkn {
    class FirstApp {
        public :
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            HknWindow hknWindow{WIDTH, HEIGHT, "HKN GAME ENGINE"};
    };
}