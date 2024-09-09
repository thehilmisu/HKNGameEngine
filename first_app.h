#pragma once 

#include "hkn_window.h"
#include "hkn_pipeline.h"
#include "hkn_engine_device.h"
#include "hkn_swap_chain.h"
#include "hkn_model.h"

#include <memory>
#include <vector>

namespace hkn {
    class FirstApp {
        public :
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            FirstApp();
            ~FirstApp();

            FirstApp(const FirstApp &) = delete;
            void operator=(const FirstApp &) = delete;

            void run();

        private:
            void loadModels();
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();

            HknWindow hknWindow{WIDTH, HEIGHT, "HKN GAME ENGINE"};
            HknEngineDevice hknDevice{hknWindow};
            HknSwapChain hknSwapChain{hknDevice, hknWindow.getExtend()};
            std::unique_ptr<HknPipeline> hknPipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
            std::unique_ptr<HknModel> hknModel;
           
    };
}