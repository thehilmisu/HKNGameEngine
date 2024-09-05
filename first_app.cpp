#include "first_app.h"

namespace hkn {
    void FirstApp::run() {
        while (!hknWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}