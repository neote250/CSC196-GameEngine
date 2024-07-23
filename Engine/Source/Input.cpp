
#include "Input.h"

#include <SDL.h>


bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);

	_keyboardState.resize(numKeys);

	//copy current keyboard state into _keyboard state
	std::copy(keyboardState, keyboardState + numKeys, _keyboardState.begin());

	_prevKeyboardState = _keyboardState;

	return true;
}

void Input::Shutdown()
{

}

void Input::Update()
{

	//Keyboard Input
	_prevKeyboardState = _keyboardState;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + _keyboardState.size(), _keyboardState.begin());

	//Mouse Input
	int x, y;
	uint32_t buttonState = SDL_GetMouseState(&x, &y);

	_mousePosition.x = (float)x;
	_mousePosition.y = (float)y;
	
		// 000 button state
		// 001 mask

	_prevMouseButtonState = _mouseButtonState;

	_mouseButtonState[0] = buttonState & SDL_BUTTON_LMASK;
	_mouseButtonState[1] = buttonState & SDL_BUTTON_MMASK;
	_mouseButtonState[2] = buttonState & SDL_BUTTON_RMASK;
}
