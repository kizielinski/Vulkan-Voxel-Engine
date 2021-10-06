/*
 * Vulkan Program
 *
 * Copyright (C) 2016 Valve Corporation
 * Copyright (C) 2016 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
Vulkan C++ Project Template
Create and destroy a simple Vulkan instance.
*/

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <vulkan/vulkan.hpp>

#include <iostream>
#include <vector>

int test()
{

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;



//    // Use validation layers if this is a debug build
//    std::vector<const char*> layers;
//#if defined(_DEBUG)
//    layers.push_back("VK_LAYER_KHRONOS_validation");
//#endif
//
//    // VkApplicationInfo allows the programmer to specifiy some basic information about the
//    // program, which can be useful for layers and tools to provide more debug information.
//    vk::ApplicationInfo appInfo = vk::ApplicationInfo()
//        .setPApplicationName("Vulkan C++ Program Template")
//        .setApplicationVersion(1)
//        .setPEngineName("LunarG SDK")
//        .setEngineVersion(1)
//        .setApiVersion(VK_API_VERSION_1_0);
//
//    // VkInstanceCreateInfo is where the programmer specifies the layers and/or extensions that
//    // are needed. For now, none are enabled.
//    vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
//        .setFlags(vk::InstanceCreateFlags())
//        .setPApplicationInfo(&appInfo)
//        .setEnabledExtensionCount(0)
//        .setPpEnabledExtensionNames(NULL)
//        .setEnabledLayerCount(static_cast<uint32_t>(layers.size()))
//        .setPpEnabledLayerNames(layers.data());
//
//    // Create the Vulkan instance.
//    vk::Instance instance;
//    try {
//        instance = vk::createInstance(instInfo);
//    } catch(std::exception e) {
//        std::cout << "Could not create a Vulkan instance: " << e.what() << std::endl;
//        return 1;
//    }
//
//    // Normally, a program would do something with the instance here. This, however, is just a
//    // simple demo program, so we just finish up right away.
//
//    instance.destroy();
//
//    return 0;
}
