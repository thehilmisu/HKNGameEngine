#pragma once 

#include "hkn_window.h"
#include "hkn_pipeline.h"
#include "hkn_engine_device.h"

namespace hkn {
    class FirstApp {
        public :
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            HknWindow hknWindow{WIDTH, HEIGHT, "HKN GAME ENGINE"};
            HknEngineDevice hknDevice{hknWindow};
            HknPipeline hknPipeline{
                hknDevice,
                "shaders/simple_shader.vert.spv", 
                "shaders/simple_shader.frag.spv", 
                HknPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
}