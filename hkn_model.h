#pragma once

#include "hkn_engine_device.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <vector>

namespace hkn{
    class HknModel{
        public:

            struct Vertex{
                glm::vec2 position;

                static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
                static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();

            };

            HknModel(HknEngineDevice &device, const std::vector<Vertex> &vertices);
            ~HknModel();

            HknModel(const HknModel &) = delete;
            void operator=(const HknModel &) = delete;  


            void bind(VkCommandBuffer commandBuffer);
            void draw(VkCommandBuffer commandBuffer);   

        private:
            void createVertexBuffers(const std::vector<Vertex> &vertices);

            HknEngineDevice& hknDevice;
            VkBuffer vertexBuffer;
            VkDeviceMemory vertexBufferMemory;
            uint32_t vertexCount;
            
    };
}