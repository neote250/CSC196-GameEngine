#pragma once
#include "Vector2.h"
#include <vector>
#include <array>

class Input {
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool GetKeyDown(uint8_t key) { return _keyboardState[key]; }
	bool GetPreviousKeyDown(uint8_t key) { return _prevKeyboardState[key]; }

	Vector2 GetMousePosition() { return _mousePosition; }
	bool GetMouseButtonDown(uint8_t button) { return _mouseButtonState[button]; }
	bool GetPreviousMouseButtonDown(uint8_t button) { return _prevMouseButtonState[button]; }


private:
	std::vector<uint8_t> _keyboardState;
	std::vector<uint8_t> _prevKeyboardState;

	Vector2 _mousePosition{ 0,0 };
	std::array<uint8_t, 3> _mouseButtonState{ 0,0,0 };
	std::array<uint8_t, 3> _prevMouseButtonState{ 0,0,0 };

};