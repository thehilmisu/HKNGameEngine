#include "hkn_model.h"

#include <cassert>
#include <cstring>

namespace hkn{

    HknModel::HknModel(HknEngineDevice &device, const std::vector<Vertex> &vertices) : hknDevice{device} {
        createVertexBuffers(vertices);
    }   

    HknModel::~HknModel(){
        vkDestroyBuffer(hknDevice.device(), vertexBuffer, nullptr);
        vkFreeMemory(hknDevice.device(), vertexBufferMemory, nullptr);
    }

    void HknModel::createVertexBuffers(const std::vector<Vertex> &vertices) {
        vertexCount = static_cast<uint32_t>(vertices.size());
        assert(vertexCount >= 3 && "Vertex count must be at least 3");
        VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;

        hknDevice.createBuffer(
            bufferSize,
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            vertexBuffer,
            vertexBufferMemory
        );

        void *data;
        vkMapMemory(hknDevice.device(), vertexBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, vertices.data(), static_cast<size_t>(bufferSize));
        vkUnmapMemory(hknDevice.device(), vertexBufferMemory);

        
    }

    void HknModel::bind(VkCommandBuffer commandBuffer) {
        VkBuffer buffers[] = {vertexBuffer};
        VkDeviceSize offsets[] = {0};
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, buffers, offsets);

    }
    
    void HknModel::draw(VkCommandBuffer commandBuffer) {        
        vkCmdDraw(commandBuffer, vertexCount, 1, 0, 0);
    }   

    std::vector<VkVertexInputBindingDescription> HknModel::Vertex::getBindingDescriptions() {
        std::vector<VkVertexInputBindingDescription> bindingDescripttions(1);
        bindingDescripttions[0].binding = 0;
        bindingDescripttions[0].stride = sizeof(Vertex);
        bindingDescripttions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescripttions;
    }

    std::vector<VkVertexInputAttributeDescription> HknModel::Vertex::getAttributeDescriptions() {
        std::vector<VkVertexInputAttributeDescription> attributeDescripttions(1);
        attributeDescripttions[0].binding = 0;
        attributeDescripttions[0].location = 0;
        attributeDescripttions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescripttions[0].offset = 0;

        return attributeDescripttions;
    }

}