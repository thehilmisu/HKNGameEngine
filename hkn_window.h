#pragma once

#define  GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace hkn{

    class HknWindow{

        public:
            HknWindow(int w, int h, std::string name);
            ~HknWindow();

            HknWindow(const HknWindow &) = delete;
            HknWindow &operator=(const HknWindow &) = delete;

            bool shouldClose() { return glfwWindowShouldClose(window);}
            VkExtent2D getExtend() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};}
            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
        private :

            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };

}//namespace hkn