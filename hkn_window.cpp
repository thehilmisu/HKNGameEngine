#include "hkn_window.h"

namespace hkn{

    HknWindow::HknWindow(int w, int h, std::string name) : width(w), height(h), windowName(name){
        initWindow();
    }

    HknWindow::~HknWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void HknWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

}

