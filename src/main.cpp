//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
//  Copyright (C) 2023 SnowyFox

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t InitialWidth = 800;
const uint32_t InitialHeight = 600;
const char* EngineName = "Betvulkan";

void logGlfwError(int error, const char* errorMessage) {
        std::cerr << "GLFW Error " << error << ": " << errorMessage << std::endl;
}

class Application {
	public:
		void invoke() {
			initializeGlfw();
			initializeVulkan();
			run();
			finalizeGlfw();
		}

	private:
		GLFWwindow* window;

		void initializeGlfw() {
			glfwSetErrorCallback(logGlfwError);

			glfwInit();

			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // disable opengl
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // TODO: support resizable windows

			window = glfwCreateWindow(InitialWidth, InitialHeight, EngineName, nullptr, nullptr);
			//                        width         height         title       monitor  opengl-only
		}

		void initializeVulkan() { }

		void run() {
			while (!glfwWindowShouldClose(window)) {
				glfwPollEvents();
			}
		}

		void finalizeGlfw() {
			glfwDestroyWindow(window);

			glfwTerminate();
		}
};

int main() {
	Application app;

	try {
		app.invoke();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

