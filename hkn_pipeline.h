#pragma once

#include <string>
#include <vector>
#include "hkn_engine_device.h"

namespace hkn {

    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };
    class HknPipeline {
        public:
            HknPipeline(HknEngineDevice &device, 
                        const std::string& vertFilePath, 
                        const std::string& fragFilePath,
                        const PipelineConfigInfo& configInfo);
            ~HknPipeline();

            HknPipeline(const HknPipeline&) = delete;
            void operator=(const HknPipeline&) = delete;

            void bind(VkCommandBuffer commandBuffer);
            static PipelineConfigInfo defaultPipelineConfigInfo(u_int32_t width, u_int32_t height);


        private:
            static std::vector<char> readFile(const std::string& filePath);

            void createGraphicsPipeline(const std::string& vertFilePath, 
                                        const std::string& fragFilePath,
                                        const PipelineConfigInfo& configInfo);
            void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

            HknEngineDevice& hknDevice;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
}